/*
1. High level module must not depend on low level modules but both of them
should depend on abstraction
2. Abstraction should not depend on details but details should be dependent on abstraction

NOTE: whenever we are talking about abstraction, we generally talk about interfaces or/and base class
*/

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;


enum class Relationship{
	parent = 1,
	child  = 2,
	sibling= 3
};

class Person{
public:
	Person(std::string name_):name{name_}{};
	std::string name;
};

class RelationshipBrowser{
public:
	virtual std::vector<Person> find_all_child(const std::string& name) = 0;
};

//low-level construct/module
class Relationships : public RelationshipBrowser
{ 
public:
	std::vector<std::tuple<Person, Relationship, Person>> relations;

	void add_parent_and_child(const Person& parent, const Person& child)
	{
		relations.push_back({parent, Relationship::child, child});
		relations.push_back({child, Relationship::parent, parent});
	}

	std::vector<Person> find_all_child(const std::string& name)
	{
		std::vector<Person> result;
		for(auto&& [first, relation, last]: relations)
		{
			if(first.name == name && relation == Relationship::child)
			{
				result.push_back(last.name);
			}
		}
		return result;
	}
};

//high-level module/construct (it must not be dependent on the low-level module)
class Research{ 
public:
	//now we are dependent on the interface rather than low-level module/construct
	Research(RelationshipBrowser& rp, const std::string name)
	{
		auto kids = rp.find_all_child(name);

		for(auto& kid: kids)
		{
			std::cout << name << "child:\t" << kid.name <<std::endl;
		}

	}

	//completely dependent on low-level module
	/*Research(Relationships& rp)
	{
		auto& relations = rp.relations;

		for(auto&& [first, relation, last]: relations)
		{
			if(first.name=="John" && relation == Relationship::child)
			{
				std::cout <<"John's child:\t" <<last.name<<std::endl;
			}
		}
	}*/
};

int main()
{
	Person p("John");
	Person c("David");
	Relationships rp;

	rp.add_parent_and_child(p,c);
	
	Research r(rp, "John");

	return 0;
}


