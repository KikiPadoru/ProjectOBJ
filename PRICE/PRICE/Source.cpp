#include <iostream>
#include "Price.h"
#include "sorting.h"
using namespace std;

void Search(Price* arr, int n, string name);
template <class T>
void data_output(T* A, int n);
template <class T>
void data_load(ifstream& in, T* A, int n);

int main()
{
	ifstream in("list.txt", ios_base::in);

	int n;
	in >> n;

	Price* list = new Price[n];

	cout << "**Original**" << endl << endl;

	//Load Data from File
	data_load(in, list, n);

	//Print Data to Console
	data_output(list, n);

	qsort(list, n, sizeof(Price), Price::compSpree);

	cout << endl << endl << "**qsort**" << endl << endl;

	data_output(list, n);
	data_load(in, list, n);

	insertionSort(list, n, Price::compSpree);

	cout << endl << endl << "**InsertionSort**" << endl << endl;

	data_output(list, n);
	data_load(in, list, n);

	selectionSort(list, n, Price::compSpree);

	cout << endl << endl << "**SelectionSort**" << endl << endl;

	data_output(list, n);
	data_load(in, list, n);

	bubbleSort(list, n, Price::compSpree);

	cout << endl << endl << "**BubbleSort**" << endl << endl;

	data_output(list, n);
	data_load(in, list, n);

	shellSort(list, 0, n - 1, Price::compSpree);

	cout << endl << endl << "**ShellSort**" << endl << endl;

	data_output(list, n);
	data_load(in, list, n);

	quickSort(list, 0, n - 1, Price::compSpree);

	cout << endl << endl << "**QuickSort**" << endl << endl;

	data_output(list, n);

	/*fstream out("PriceList.bin", ios::out | ios::binary);
	for (int i = 0; i < n; i++)
		list[i].writeBin(out);
	out.close();

	fstream in1("PriceList.bin", ios::in | ios::binary);
	for (int i = 0; i < n; i++)
	{
		list[i].readBin(in1);
	}
	in1.close();*/

	/*string searchName;
	cout << "\nEnter name of product.\nEnter \"0\" if you want to stop.\n" << endl;
	while (searchName != "0")
	{
		cin >> searchName;
		Search(list, n, searchName);
	}*/
}

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
template <class T>
void data_output(T* A, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i];
	}
}
template <class T>
void data_load(ifstream& in, T* A, int n)
{
	for (int i = 0; i < n; i++)
		in >> A[i];
}
