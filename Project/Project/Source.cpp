#include "Person.h"
using namespace std;

int main()
{
	Person p1("John", 18);
	Person p2("Maxx", 20);
	Person p3;
	
	p3.name = "Harry";

	cout << p3;

/*
	cin >> p3;

	if (p3 < p1)
		cout << p3.name << " younger than " << p1.name << endl;
	else if(p3 > p1)
		cout << p3.name << " older than " << p1.name << endl;
	else 
		cout << p3.name << " peer " << p1.name << endl;
*/



}