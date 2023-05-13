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
	//this is to access the private constructor of Point class, another solution could be 
	//we can make the constructor of Point class public
	friend class Factory; //this is violating open-close principle
	friend ostream &operator<<(ostream &os, const Point &point)
	{
		os << "x:\t" << point.x << "\n" << "y:\t"<<point.y; 
		return os;
	}
};

//factory class to create the correct point

class Factory
{

public:
	static Point NewCartesian(float a, float b)
	{
		//this will call the private constructor of Point
		//either we need to make constructor public or declare Facotry as friend class(this will violate open-close principle)
		// inside point class
		return {a, b}; 
	}
	static Point NewXCartesian(float a, float b)
	{
		//this will call the private constructor of Point
		//either we need to make constructor public or declare Facotry as friend class inside point class
		return {4*a, 5*b};
	}
};



int main()
{
	auto p = Factory::NewXCartesian(10,20);
	cout << p;
	return 0;
}