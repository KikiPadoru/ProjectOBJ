#include <iostream>
using namespace std;

//Сортировка вставками 
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

//Сортировка пузырьком
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

//Сортировка Шелла
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

//Разбиение Хоара
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

//Быстрая сортировка
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

//Сортировка расческой
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

//Сортировка выбором
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
//Пирамидальная (турнирная) сортировка
template <typename T>
void heap_sort(T* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n / 2 - 1 - i / 2; j > -1; j--)
		{
			if (2 * j + 2 <= n - 1 - i)
			{
				if (arr[2 * j + 1] > arr[2 * j + 2])
				{
					if (arr[j] < arr[2 * j + 1])
					{
						T tmp = arr[j];
						arr[j] = arr[2 * j + 1];
						arr[2 * j + 1] = tmp;
					}
				}
				else
				{
					if (arr[j] < arr[2 * j + 2])
					{
						T tmp = arr[j];
						arr[j] = arr[2 * j + 2];
						arr[2 * j + 2] = tmp;
					}
				}
			}
			else
			{
				if (2 * j + 1 <= n - 1 - i)
					if (arr[j] < arr[2 * j + 1]) {
						T tmp = arr[j];
						arr[j] = arr[2 * j + 1];
						arr[2 * j + 1] = tmp;
					}
			}
		}
		T tmp = arr[0];
		arr[0] = arr[n - i - 1];
		arr[n - i - 1] = tmp;
	}
}

//Слияние для рекурсивного
template<typename T>
void merge_r(T* a, int left, int mid, int right) {
	int it1 = 0;
	int it2 = 0;

	T* res = new T[right - left + 1];

	while (left + it1 <= mid && mid + it2 < right) {
		if (a[left + it1] < a[mid + it2 + 1]) {
			res[it1 + it2] = a[left + it1];
			it1 += 1;
		}
		else {
			res[it1 + it2] = a[mid + it2 + 1];
			it2 += 1;
		}
	}
	while (left + it1 <= mid) {
		res[it1 + it2] = a[left + it1];
		it1 += 1;
	}
	while (mid + it2 < right) {
		res[it1 + it2] = a[mid + it2 + 1];
		it2 += 1;
	}
	for (int i = 0; i < right - left + 1; i++)
		a[left + i] = res[i];
}

//Слияние для итеративного
template<typename T>
void merge_i(T* a, int left, int mid, int right) {
	int it1 = 0;
	int it2 = 0;

	T* res = new T[right - left];

	while (left + it1 < mid && mid + it2 < right) {
		if (a[left + it1] < a[mid + it2]) {
			res[it1 + it2] = a[left + it1];
			it1 += 1;
		}
		else {
			res[it1 + it2] = a[mid + it2];
			it2 += 1;
		}
	}
	while (left + it1 < mid) {
		res[it1 + it2] = a[left + it1];
		it1 += 1;
	}
	while (mid + it2 < right) {
		res[it1 + it2] = a[mid + it2];
		it2 += 1;
	}
	for (int i = 0; i < it1 + it2; i++)
		a[left + i] = res[i];
}


//Рекурсивная сортировка слиянием
template<typename T>
void merge_sort_recursive(T* a, int left, int right)
{
	if (left < right) {
		int mid = (left + right) / 2;

		merge_sort_recursive(a, left, mid);
		merge_sort_recursive(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}

//Итеративная сортировка слиянием
template<typename T>
void merge_sort_iterative(T* a, int n)
{
	for (int i = 1; i < n; i *= 2)
		for (int j = 0; j < n - i; j += 2 * i)
			if (j + 2 * i < n)
				merge_i(a, j, j + i, j + 2 * i);
			else
				merge_i(a, j, j + i, n);
}

int main()
{
	int arr_i[9] = { 1, 7, 34, 1, 56, -5, 341, 57, 31 };
	char arr_c[9] = { 'b', 'a', 't', 'w','b' ,'z' ,'c' , 'v', '!' };

	merge_sort_iterative(arr_i, 9);
	merge_sort_iterative(arr_c, 9);

	for (int i = 0; i < 9; i++)
		cout << arr_i[i] << " ";
	cout << endl;
	for (int i = 0; i < 9; i++)
		cout << arr_c[i] << " ";
	cout << endl;
}