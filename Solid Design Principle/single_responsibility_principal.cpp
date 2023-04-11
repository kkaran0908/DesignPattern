#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Book
{
public:
	std::string book_name;
	vector<std::string> line;
	Book(std::string& name)
	{
		book_name = name;
	}

	void addContent(std::string line_content)
	{
		line.push_back(line_content);
	}
};

class NewsPaper
{
public:
	std::string newspaper_name;
	vector<std::string> line;
	NewsPaper(std::string& name)
	{
		newspaper_name = name;
	}

	void addContent(std::string line_content)
	{
		line.push_back(line_content);
	}
};

class SaveManager
{
public:
	template<typename T>
	void saveFile(const std::string& file_name, T& obj)
	{
		ofstream ofs(file_name);
		for(auto& l : obj.line)
		{
			ofs<<l<<std::endl;
		}
	}
};

int main()
{
	std::string book_name = "life";
	Book b(book_name);
	b.addContent("This is the first line");
	b.addContent("This is the second line");


	std::string newspaper_name = "DainikJagran";
	NewsPaper np(newspaper_name);
	np.addContent("NewsPaper line no 1");

	SaveManager s;
	s.saveFile<Book>("book.txt", b);
	s.saveFile<NewsPaper>(newspaper_name,np);

	return 0;

}