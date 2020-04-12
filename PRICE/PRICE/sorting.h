#include <iostream>
template <class T>
inline void insertionSort(T* A, int n, int (*comp)(const void*, const void*))
{

	for (int i = 1; i < n; i++) {
		int j = i - 1;
		while (j >= 0 && !comp(&A[j], &A[j + 1]))
		{
			T tmp = A[j];
			A[j] = A[j + 1];
			A[j + 1] = tmp;
			j = j - 1;
		}
	}
}

template <class T>
inline void selectionSort(T* A, int n, int (*comp)(const void*, const void*))
{
	for (int i = 0; i < n - 2; i++)
	{
		int min = i;
		for (int j = i + 1; j < n - 1; j++)
			if (!comp(&A[min], &A[j]))
				min = j;
		T tmp = A[i];
		A[i] = A[min];
		A[min] = tmp;
	}
}

template <class T>
inline void bubbleSort(T* A, int n, int (*comp)(const void*, const void*))
{
	for (int i = 1; i < n; i++)
	{
		bool flag = 0;
		int min = i;
		for (int j = i; j < n - i - 1; j++)
		{
			if (!comp(&A[j], &A[j + 1]))
			{
				T tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
				flag = 1;
			}
			if (!comp(&A[j], &A[min]))
				min = j;
		}
		if (!flag)
			break;
		if (min != i)
		{
			T tmp = A[i];
			A[i] = A[min];
			A[min] = tmp;
		}


	}
}

template <class T>
inline void shellSort(T* A, int l, int r, int (*comp)(const void*, const void*))
{
	for (int d = (r - l) / 2; d != 0; d /= 2)
		for (int i = l + d; i != r; ++i)
			for (int j = i; j - l >= d && !comp(&A[j], &A[j - d]); j -= d) {
				T tmp = A[j];
				A[j] = A[j - d];
				A[j - d] = tmp;
			}
}

template <class T>
inline void quickSort(T* A, int l, int r, int (*comp)(const void*, const void*))
{
	if (l < r) {
		int q = partition(A, l, r, comp);
		quickSort(A, l, q, comp);
		quickSort(A, q + 1, r, comp);
	}
}

template <class T>
inline int partition(T* A, int l, int r, int (*comp)(const void*, const void*))
{
	T v = A[(l + r) / 2];
	int i = l;
	int j = r;

	while (i <= j) {
		while (comp(&v, &A[i]))
			i++;

		while (comp(&A[j], &v))
			j--;

		if (i >= j)
			break;

		T tmp = A[i++];
		A[i++] = A[j--];
		A[j--] = tmp;
	}
	return	j;
}