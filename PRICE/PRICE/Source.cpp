#include <fstream>
#include "Price.h"

using namespace std;

void Search(Price* arr, int n, string name)
{
	if (name != "0") {
		bool flag = 0;
		for (int i = 0; i < n; i++)
			if (arr[i].getName() == name) {
				cout << arr[i];
				flag = 1;
			}
		if (!flag)
			cout << "Product Not Found";
	}
	return;
}

int main()
{
	ifstream in("list.txt");

	int n;
	in >> n;

	Price* list = new Price[n];

	for (int i = 0; i < n; i++)
		in >> list[i];

	qsort(list, n, sizeof(Price), Price::compSpree);

	for (int i = 0; i < n; i++)
		cout << list[i];
	string searchName;

	while (searchName != "0")
	{
		cin >> searchName;
		Search(list, n, searchName);
	}

}	