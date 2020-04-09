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

int Price::compName(const void* a, const void* b)
{
	Price* A = (Price*)a;
	Price* B = (Price*)b;
	return A->getName().compare(B->getName());
}

int Price::compShop(const void* a, const void* b)
{
	Price* A = (Price*)a;
	Price* B = (Price*)b;
	return A->getShop().compare(B->getShop());
}

int Price::compCost(const void* a, const void* b)
{
	Price A = *((Price*)a);
	Price B = *((Price*)b);
	if (A > B)
		return 1;
	else if (A == B)
		return 0;
	else
		return -1;
}

int Price::compSpree(const void* a, const void* b)
{
	if (!compName(a, b))
		if (!compShop(a, b))
			return compCost(a, b);
		else
			return compShop(a, b);
	else
		return compName(a, b);
}

bool Price::operator>(const Price a)
{
	return this->cost > a.cost;
}

bool Price::operator<(const Price a)
{
	return this->cost < a.cost;
}

bool Price::operator==(const Price a)
{
	return this->cost == a.cost;
}

ostream& operator<<(ostream& os, const Price a)
{
	return os << a.name << " " << a.shop << " " << a.cost << endl;
}

istream& operator>>(istream& is, Price& a)
{
	return is >> a.name >> a.shop >> a.cost;
}
