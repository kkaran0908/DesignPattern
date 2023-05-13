#include <iostream>
#include <fstream>
#include <map>
#include <memory>
using namespace std;

class HotDrink{
public:
	virtual ~HotDrink() = default;
	virtual void prepare(int volume = 0) = 0;
};

class Tea: public HotDrink{
public:
	void prepare(int volume) override
	{
		cout<<"Preparing tea with volume:\t" << volume;
	}

};

class Coffee: public HotDrink{
public:
	void prepare(int volume) override
	{
		cout<<"Preparing coffee with volume:\t" << volume;
	}
};

class HotDrinkFactory{
public:
	virtual ~HotDrinkFactory() = default;
	virtual unique_ptr<HotDrink> make() const = 0;
};

class TeaFactory : public HotDrinkFactory{
public:
	unique_ptr<HotDrink> make() const override
	{
		return make_unique<Tea>();
	}
};

class CoffeeFactory : public HotDrinkFactory{
public:
	unique_ptr<HotDrink> make() const override
	{
		return make_unique<Coffee>();
	}
};

class DrinkFactory{
	map<string, unique_ptr<HotDrinkFactory>> factories_;
public:
	DrinkFactory()
	{
		factories_["Tea"] = make_unique<TeaFactory>();
		factories_["Coffee"] = make_unique<CoffeeFactory>();
	}

	unique_ptr<HotDrink> make_drink(const string& type)
	{
		auto drink = factories_[type]->make();
		return drink;
	}
};

int main()
{
	DrinkFactory df;
	auto tf = df.make_drink("Coffee");
	tf->prepare(20);

	return 0;
}









