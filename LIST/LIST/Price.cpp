#include "Price.h"

Price::Price()
{
	name = "";
	shop = "";
	cost = 0;
}

Price::Price(string name, string shop, int cost)
{
	this->name = name;
	this->shop = shop;
	this->cost = cost;
}

Price::Price(const Price& a)
{
	this->name = a.name;
	this->shop = a.shop;
	this->cost = a.cost;
}

string Price::getName()
{
	return this->name;
}

string Price::getShop()
{
	return this->shop;
}

bool Price::operator>(const Price a)
{
	if (!(this->name.compare(a.name)))
		if (!(this->shop.compare(a.shop)))
			return this->cost > a.cost;
		else
			return this->shop.compare(a.shop) > 0;
	else
		return this->name.compare(a.name) > 0;
}

bool Price::operator<(const Price a)
{
	if (!(this->name.compare(a.name)))
		if (!(this->shop.compare(a.shop)))
			return this->cost < a.cost;
		else
			return this->shop.compare(a.shop) < 0;
	else
		return this->name.compare(a.name) < 0;
}

bool Price::operator==(const Price a)
{
	return this->name.compare(a.name) == 0 && this->shop.compare(a.shop) == 0 && this->cost == a.cost;
}

bool Price::operator!=(const Price a)
{
	return this->name.compare(a.name) != 0 || this->shop.compare(a.shop) != 0 || this->cost != a.cost;
}

void Price::writeBin(fstream& file)
{
	file.write((char*)this, sizeof(*this));
}

void Price::readBin(fstream& file)
{
	file.read((char*)this, sizeof(*this));
}

ostream& operator<<(ostream& os, const Price a)
{
	return os << a.name << " " << a.shop << " " << a.cost;
}

istream& operator>>(istream& is, Price& a)
{
	return is >> a.name >> a.shop >> a.cost;
}