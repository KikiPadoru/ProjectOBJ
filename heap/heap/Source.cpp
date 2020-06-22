#include "Heap.h"

int main()
{
	int a[10] = { 4, 1, 3, 2, 16, 9, 10, 14 ,8, 7 };
	Heap A(a, 10);

	A.print_heap();
	A.build_max_heap();
	cout << endl;
	A.print_heap();
	A.heap_sort();
	cout << endl;
	A.print_heap();
	cout << endl;
	A.get_arr();
}