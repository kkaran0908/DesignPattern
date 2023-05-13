#include <iostream>
#include <fstream>
using namespace std;

enum PointType{
	cartesian,
	xCartesian
};

class Point{
	float x, y;
	Point(float a, float b):x{a},y{b}{};
public:
	//1st factory function
	static Point NewCartesian(float a, float b)
	{
		return {a, b};
	}
	//2nd factory function
	static Point NewXCartesian(float a, float b)
	{
		return {4*a, 5*b};
	}
	friend ostream &operator<<(ostream &os, const Point &point)
	{
		os << "x:\t" << point.x << "\n" << "y:\t"<<point.y; 
		return os;
	}
};


int main()
{
	Point p = Point::NewCartesian(10,20);
	cout<<p;
	return 0;
}