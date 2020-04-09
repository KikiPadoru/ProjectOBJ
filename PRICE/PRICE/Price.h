#pragma once
#include <iostream>
#include <string>

using namespace std;

class Price {
private: 
	string name;
	string shop;
	int cost;
public:

	//Constructors
	Price();
	Price(string name, string shop, int cost);
	Price(const Price& a);

	//Methods
	string getName();
	string getShop();

	//SortMethods
	static int compName(const void* a, const void* b);
	static int compShop(const void* a, const void* b);
	static int compCost(const void* a, const void* b);
	static int compSpree(const void* a, const void* b);

	//Compare
	bool operator>(const Price a);
	bool operator<(const Price a);
	bool operator==(const Price a);

	//IO
	friend istream& operator>>(istream& is, Price& a);
	friend ostream& operator<<(ostream& os, const Price a);
};