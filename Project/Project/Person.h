#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	string name;
	int age;
	Person() 
	{
		name = "EmptyName";
		age = 0;
	};

	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	};

	Person& operator=(const Person p)
	{
		name = p.name;
		age = p.age;
		return *this;
	}

	bool operator>(const Person p)
	{
		return (age > p.age) ? true : false;
	}

	bool operator<(const Person p)
	{
		return (age < p.age) ? true : false;
	}

	bool operator==(const Person p)
	{
		return (age == p.age) ? true : false;
	}

	friend ostream& operator<<(ostream& os, const Person p)
	{
		return os << p.name << " " << p.age;
	}

	friend istream& operator>>(istream& is, Person& p)
	{
		return is >> p.name >> p.age;
	}

};

