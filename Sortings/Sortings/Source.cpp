#include <iostream>
using namespace std;

//���������� ���������
template <typename T>
void insert_sort(T* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		T key = arr[i];
		int j = i;
		while (j >= 0 && arr[j - 1] > key) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = key;
	}
}

//���������� ���������
template <typename T>
void bubble_sort(T* arr, int n)
{
	for (int i = 0; i < n - 1; i++) {
		bool flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				T tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;
			}
		}
		if (!flag) break;
	}
}

//���������� �����
template <typename T>
void shell_sort(T* arr, int n)
{
	for (int step = n / 2; step > 0; step /= 2)
		for (int i = step; i < n; i++)
			for (int j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step)
			{
				T tmp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = tmp;
			}
}

//��������� �����
template <typename T>
int partition(T* arr, int l, int r)
{
	T v = arr[(l + r) / 2];
	int i = l;
	int j = r;

	while (i <= j) {
		while (v > arr[i])
			i++;

		while (arr[j] > v)
			j--;

		if (i >= j)
			break;
		swap(arr[i++], arr[j--]);
	}
	return	j;
}

//������� ����������
template <typename T>
void quick_sort(T* arr, int l, int r)
{
	if (l < r)
	{
		int p = partition(arr, l, r);
		quick_sort(arr, l, p);
		quick_sort(arr, p + 1, r);
	}
}

//���������� ���������
template <typename T>
void comb_sort(T* arr, int n)
{
	double fakt = 1.3;
	int step = n - 1;

	while (step >= 1)
	{
		for (int i = 0; i + step < n; i++)
		{
			if (arr[i] > arr[i + step])
			{
				T tmp = arr[i];
				arr[i] = arr[i + step];
				arr[i + step] = tmp;
			}
		}
		step /= fakt;
	}
	for (int i = 0; i < n - 1; i++) {
		bool flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				T tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;
			}
		}
		if (!flag) break;
	}
}

//���������� �������
template <typename T>
void selection_sort(T* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_i = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_i])
			{
				min_i = j;
			}
		}
		if (min_i != i)
		{
			T tmp = arr[i];
			arr[i] = arr[min_i];
			arr[min_i] = tmp;
		}
	}
}


int main()
{
	int arr_i[9] = { 1, 7, 34, 1, 56, -5, 341, 57, 31 };
	char arr_c[9] = { 'b', 'a', 't', 'w','b' ,'z' ,'c' , 'v', '!' };

	selection_sort(arr_i, 9);
	selection_sort(arr_c, 9);

	for (int i = 0; i < 9; i++)
		cout << arr_i[i] << " ";
	cout << endl;
	for (int i = 0; i < 9; i++)
		cout << arr_c[i] << " ";
	cout << endl;
}