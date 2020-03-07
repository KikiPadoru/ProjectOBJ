#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	//Init
	string name;
	int age;

	//Default Contructor
	Person();

	//Contructor
	Person(string name, int age);
	
	//Operator =
	Person& operator=(const Person p);
	
	//Operator >
	bool operator>(const Person p);
	
	//Operator <
	bool operator<(const Person p);
	
	//Operator ==
	bool operator==(const Person p);
	
	//cout overload
	friend ostream& operator<<(ostream& os, const Person p);

	//cin overload
	friend istream& operator>>(istream& is, Person& p);
	
};

