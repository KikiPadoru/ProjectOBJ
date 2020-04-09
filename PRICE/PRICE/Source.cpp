#include <iostream>
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
			cout << "Product Not Found" << endl;
	}
	return;
}

int main()
{
	fstream in("list.txt");
	fstream out("PriceList.bin", ios::out |  ios::binary);

	int n;
	in >> n;

	Price* list = new Price[n];

	for (int i = 0; i < n; i++)
		in >> list[i];

	in.close();

	qsort(list, n, sizeof(Price), Price::compSpree);

	for (int i = 0; i < n; i++)
		list[i].writeBin(out);

	out.close();

	fstream in1("PriceList.bin", ios::in | ios::binary);

	for (int i = 0; i < n; i++) 
	{
		list[i].readBin(in1);
	}

	for (int i = 0; i < n; i++)
	{
		cout << list[i];
	}

	string searchName;
	cout << "\nEnter name of product.\nEnter \"0\" if you want to stop.\n" << endl;
	while (searchName != "0")
	{
		cin >> searchName;
		Search(list, n, searchName);
	}
	
}	