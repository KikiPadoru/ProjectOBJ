#pragma once
#include <iostream>
using namespace std;

class Heap
{
private:
	int lenght;
	int heap_size;
	int* h;
	int parent(int i) 
	{
		return i >> 1;
	}
	int left(int i)
	{
		return 2 * i + 1;
	}
	int right(int i)
	{
		return 2 * i + 2;
	}
public:
	Heap()
	{
		lenght = 0;
		heap_size = 0;
		h = new int[100];
	}

	Heap(int* arr, int n)
	{
		lenght = n;
		heap_size = lenght;
		h = new int[lenght];
		for (int i = 0; i < n; i++) {
			h[i] = arr[i];
		}
	}

	void build_max_heap()
	{
		heap_size = lenght;
		for (int i = lenght / 2, j = 1; i >= 0; i--, j++)
		{
			/*cout << "Iter " << j << "\ti = " << i << endl;
			print_heap();
			cout << endl;*/
			max_heapify(i);
		}
	}
	void add(int x)
	{
		int i = heap_size;
		h[i] = x;
		heap_size++;
	}
	void print()
	{
		for (int i = 0; i < heap_size; i++)
			cout << h[i] << " ";
		cout << endl;
	}
	void max_heapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int largest;
		if (l <= heap_size && h[l] > h[i])
			largest = l;
		else
			largest = i;
		if (r <= heap_size && h[r] > h[largest])
			largest = r;
		if (largest != i) {
			swap(h[i], h[largest]);
			max_heapify(largest);
		}
	}
	void print_heap()
	{
		int i = 0;
		int k = 1;
		while (i < heap_size)
		{
			while ((i < k) && (i < heap_size)) {
				cout << h[i] << " ";
				i++;
			}
			cout << endl;
			k = k * 2 + 1;
		}
	}
	int heap_extract_max()
	{
		if (heap_size < 1)
		{
			cout << "ERORO";
			return 0;
		}
		int max = h[0];
		heap_size = heap_size - 1;
		max_heapify(0);
		return max;
	}
	void heap_sort()
	{
		build_max_heap();
		for (int i = lenght - 1; i > 1; i--)
		{
			swap(h[0], h[i]);
			heap_size = heap_size - 1;
			max_heapify(0);
		}
	}
	void get_arr()
	{
		for (int i = 0; i < lenght; i++)
			cout << h[i] << " ";
	}
};

