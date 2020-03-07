#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class MyString
{
private:
	char* str;
	int n;

public:
	MyString() 
	{
		str = 0;
		n = 0;
	};

	MyString(const char* str)
	{
		this->n = strlen(str);
		this->str = new char[n + 1];
		strcpy(this->str, str);
	}

	MyString(char* str)
	{
		this->n = strlen(str);
		this->str = new char[n + 1];
		strcpy(this->str, str);
	}
	
	~MyString() {}

	friend ostream& operator<<(ostream& os, const MyString a)
	{
		return os << a.str;
	}

	friend istream& operator>>(istream& is, const MyString a)
	{
		return is >> a.str;
	}
};

