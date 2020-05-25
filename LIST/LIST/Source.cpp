#include <iostream>
#include "List.h"
#include "Price.h"
using namespace std;

int main()
{
	List<Price> A;
	cout << "Is empty? - " << A.isEmpty() << endl << endl;

	Price a("SomeProduct", "SomeShop", 26);
	Price b("SameProduct", "SameShop", 16);
	Price c("S", "&", 10);
	Price d("D", "#", 4);

	A.push_back(a);
	A.push_back(b);
	A.push_back(c);
	A.push_front(d);

	cout << A << endl;

	cout << A.search(c) << endl;
	//A.del(d);

	A.insert_at_sort(a);

	cout << endl << "Is empty? - " << A.isEmpty() << endl << endl;
	cout << "Sorted:" << endl;
	A.insertion_sort();

	A.insert_at_sort(a);

	cout << A << endl;

	A.dedup();
	//A.delete_node(0);
	cout << "After dedup" << endl << A;




}