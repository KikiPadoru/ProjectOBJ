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

	int N;
	in >> N;

	for (int i = 0; i < N; i++)
	{
		in >> A;
	}
	
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
	A.del(A[2]);

	cout << "Delete 2 items" << endl << A << endl;
	cout << "Item '" << g <<"' locate at " << A.search(g) + 1 << " position" << endl << A << endl;

	A.insert_at_sort(j);

	cout << "Adding new item without sort" << endl << A << endl;

	//A.dedup();

	cout << "Duplicate removing" << endl << A << endl;

	List<Price> B(A);

	cout << "Copy of A" << endl << B;
	cout << "Compare A and B: " << A.list_compare(B) << endl << endl;

	B.del(j);
	B.push_back(j);

	cout << "Push item to end of list" << endl << B;
	cout << "Compare A and B: " << A.list_compare(B) << endl << endl;

	for (int i = 6; i < B.get_Size();)
		B.delete_node(i);

	cout << "List B" << endl << B;
	cout << "List B is Subset of A: " << B.isSubset(A) << endl << endl;

	B.delete_node(0);

	cout << "Delete first item of List B" << endl << B;
	cout << "List B is Subset of A: " << B.isSubset(A) << endl << endl;

	B.push_back(g);
	B.pop_front();

	cout << "Add new item to List B" << endl << B;
	cout << "List B is Subset of A: " << B.isSubset(A) << endl;

}	

