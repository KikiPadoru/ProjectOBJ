#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List<int> A;
	A.push_back(5);
	A.push_back(6);
	A.push_back(8);
	A.push_front(3);
	A.push_back(5);
	A.push_front(-35);
	A.print();
	A.del(5);
	A.print();
}