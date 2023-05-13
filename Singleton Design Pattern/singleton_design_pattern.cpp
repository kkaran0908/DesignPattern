#include <iostream>
#include <ostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;


class Database{
	Database()
	{
		std::cout<<"Initializing the database" <<std::endl;
		std::string s1, s2;

		ifstream ifs("file.txt");
		while(getline(ifs, s1))
		{
			getline(ifs, s2);

			data[s1] = s2;

			std::cout<<"s1:\t" << s1 <<std::endl;
			std::cout<<"s2:\t" << s2 <<std::endl;

		}
	}
	std::map<std::string, std::string> data;
public:
	Database(Database&) = delete;
	void operator=( const Database&) = delete;

	static Database& GetSingletonDatabaseConnection()
	{
		static Database db;
		return db;
	}
	std::string GetProfileId(const std::string& name)
	{
		return data[name];
	}
};

int main()
{
	std::string name = "karan";

	std::cout<< "Profile_id:\t"<<Database::GetSingletonDatabaseConnection().GetProfileId(name);

	return 0;
}