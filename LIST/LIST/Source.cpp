#include <iostream>
#include "List.h"
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
	List<int> A;
	cout << "isEmpty? - " << A.isEmpty() << endl;
	A.push_back(5);	
	A.push_back(6);	
	A.push_back(8);	
	A.push_front(3);
	A.push_back(5); 
	A.push_back(5); 
	A.push_back(5); 
	A.push_front(-35);
	A.push_back(90);
	A.push_front(90);
	A.print();
	A.dedup();
	cout << "Dedup is Here" << endl << A << endl;
	A.insert_at_sort(5);
	A.del(-35);
	A.print();
	insertionSort(A, A.getSize());
	A.insert_at_sort(2);
	A.insert_at_sort(4);
	A.insert_at_sort(4);
	A.insert_at_sort(90);
	A.insert_at_sort(90);
	A.insert_at_sort(-70);
	A.insert_at_sort(-70);
	A.print();

}