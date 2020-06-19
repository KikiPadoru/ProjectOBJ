#include <iostream>
#include <fstream>
#include "List.h"
#include "Price.h"
using namespace std;

int main()
{
	List<Price> A;

	if (A.isEmpty())
		cout << "List is Empty" << endl << endl;
	else 
		cout << "List is not Empty" << endl << endl;

	fstream in("input.txt");

	in >> A;
	
	cout << "File Reading..." << endl << A;

	if (A.isEmpty())
		cout << "List is Empty" << endl << endl;
	else
		cout << "List is not Empty" << endl << endl;

	char a;

	Price g("NewProduct", "NewShop", 45);
	Price h("OldProduct", "OldShop", 3);
	Price j("BB", "R", 464);

	A.push_back(g);
	A.push_front(h);

	cout << "Adding 2 items" << endl << A << endl;

	A.insertion_sort();

	cout << "Sort by insertion" << endl << A << endl;

	A.del(h);

	cout << "Delete 2 items" << endl << A << endl;
	cout << "Item '" << g <<"' locate at " << A.search(g) + 1 << " position" << endl << A << endl;

	A.insert_at_sort(j);

	cout << "Adding new item without sort" << endl << A << endl;

	A.dedup();

	cout << "Duplicate removing" << endl << A << endl;

}	

