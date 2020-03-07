#include "Person.h"

Person::Person()
{
	name = "EmptyName";
	age = 0;
}
Person::Person(string name, int age)
{
	this->name = name;
	this->age = age;
}

Person& Person::operator=(const Person p)
{
	name = p.name;
	age = p.age;
	return *this;
}

bool Person::operator>(const Person p)
{
	return (age > p.age) ? true : false;
}

bool Person::operator<(const Person p)
{
	return (age < p.age) ? true : false;
}

bool Person::operator==(const Person p)
{
	return (age == p.age) ? true : false;
}

ostream& operator<<(ostream& os, const Person p)
{
	return os << p.name << " " << p.age;
}

istream& operator>>(istream& is, Person& p)
{
	return is >> p.name >> p.age;
}
