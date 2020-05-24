#include <iostream>
#include "List.h"
#include "Price.h"
using namespace std;

template <class T>
void insertionSort(List<T> A, int n)
{
	for (int i = 1; i < n; i++) {
		T key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = key;
	}
}

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
	A.del(d);

	A.insert_at_sort(a);

	cout << endl << "Is empty? - " << A.isEmpty() << endl << endl;
	cout << "Sorted:" << endl;
	insertionSort(A, A.getSize());

	A.insert_at_sort(a);

	cout << A << endl;

	A.dedup();
	cout << "After dedup" << endl << A;




}