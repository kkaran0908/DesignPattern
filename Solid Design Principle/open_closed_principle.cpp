/*
Your system should be open to extension but closed for modification.
*/


#include <iostream>
#include <vector>

using namespace std;

enum color{
	green = 1,
	red   = 2,
	yellow= 3
};

class Product{
public:
	Product(std::string product_name_, color product_color_)
	{
		product_name = product_name_;
		product_color= product_color_;
	}

	std::string product_name;
	color product_color;
};
/*
class Filter{
	
public:
	vector<Product*> filter_by_color(color c, std::vector<Product*> product)
	{
		vector<Product*> result;
		for(auto& p : product)
		{
			if (p->product_color == c)
			{
				result.push_back(p);
			}
		}
		return result;
	}
};*/


//***************
//better filter

//create the interface for the specification
template<typename T> class Specification{
	public:
		virtual bool is_satisfied(T* item) = 0;
};


//create the interface for filter
template<typename T> class Filter{
public:
	virtual vector<T*> filter(vector<T*>, Specification<T>& spec) = 0;
};


//implemetation of smart filter
class BetterFilter : public Filter<Product>
{
public:
	vector<Product*> filter (std::vector<Product*> products, Specification<Product>& spec) override{

		std::vector<Product*> prd;

		for(auto& itr : products)
		{
			if (spec.is_satisfied(itr))
			{
				prd.push_back(itr);

			}
		}
		return prd;
	}

};


//implementation of color specification
class ColorSpecification : public Specification<Product>
{
	color clr;
public:
	ColorSpecification(color c):clr{c}{};

	bool is_satisfied(Product* prd)
	{
		if(prd->product_color == clr)
		{
			return true;
		}
		return false;
	}
};

//implementation of color specification
class NameSpecification : public Specification<Product>
{
	std::string name;
public:
	NameSpecification(std::string name_):name{name_}{};

	bool is_satisfied(Product* prd)
	{
		if(prd->product_name == name)
		{
			return true;
		}
		return false;
	}
};

int main()
{	
	Product p1("mango", color::yellow);
	Product p2("peach", color::red);
	Product p3("Guava", color::green);
	vector<Product*> prd{&p1, &p2, &p3}; 

	BetterFilter f;
	color c = color::green;

	ColorSpecification cs(color::green);
	auto filtered_result = f.filter(prd, cs);

	for(auto& itr : filtered_result)
	{
		std::cout<< "product_name:\t" << itr->product_name 
				<<  " product_color:\t" << itr->product_color;
	}

	NameSpecification ns("mango");
	filtered_result = f.filter(prd, ns);

	for(auto& itr : filtered_result)
	{
		std::cout<< "\nproduct_name:\t" << itr->product_name 
				<<  " product_color:\t" << itr->product_color;
	}


	return 0;
}