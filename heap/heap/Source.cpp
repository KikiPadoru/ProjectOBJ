#include "Heap.h"

int main()
{
	int a[10] = { 4, 1, 3, 2, 16, 9, 10, 14 ,8, 7 };
	Heap<int> A(a, 10);

	//A.print(); 
	A.print_heap();

}