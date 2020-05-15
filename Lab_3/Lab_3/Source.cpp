#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

template <class T>
int comb_sort(vector<T>& A)
{
	int n = 0;
	double step = A.size() - 1;
	const double factor = 1.3;

	while (step >= 1)
	{
		for (int i = 0; i + step < A.size(); i++)
		{
			if (A[i] > A[i + step])
			{
				swap(A[i], A[i + step]);
				n++;
			}
		}
		step /= factor;
	}

	for (int i = 0; i < A.size() - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < A.size() - i - 1; j++)
			if (A[j] > A[j + 1])
			{
				swap(A[j], A[j + 1]);
				swapped = true;
				n++;
			}
		if (!swapped)
			break;
	}
	return n;
}

template <class T>
T majority(vector<T> A)
{
	T majority_elem = A[0];
	int max = 0;
	for (int i = 0; i < A.size() - 1; i++)
	{
		int counter = 0;
		for (int j = 0; j < A.size() - 1; j++)
		{
			if (A[i] == A[j])
			{
				counter++;
			}
		}
		if (max < counter)
		{
			majority_elem = A[i];
			max = counter;
		}
	}
	return majority_elem;
}

template <class T>
T in_order(vector<T> A)
{
	T majority_elem = A[0];
	T cur = A[0];
	int max = 0;
	int counter = 1;
	for (int i = 1; i < A.size() - 1; i++)
	{
		if (cur == A[i])
		{
			counter++;
		}
		else
		{
			if (max < counter)
			{
				max = counter;
				majority_elem = A[i - 1];
			}
			counter = 1;
			cur = A[i];
		}
	}
	return majority_elem;
}


int main()
{

	int N = 1;

	double Time_A = 0;
	double Time_B = 0;

	while (N < 500)
	{
		vector<int> D;
		for (int i = 0; i < N; i++)
			D.push_back(rand() % 100);

		cout << endl << N;
		clock_t t1 = clock();
		cout << endl << "Majority:\t" << majority(D);
		clock_t t2 = clock();
		
		Time_A = (double)(t2 - t1) / CLOCKS_PER_SEC;
		cout << "\tTIME:\t" << Time_A << "\t|\t" << t2 - t1 << "\t|" << endl;

		clock_t t3 = clock();
		comb_sort(D);
		in_order(D);
		cout << "In Order D:\t" << in_order(D);
		clock_t t4 = clock();

		Time_B = (double)(t4 - t3) / CLOCKS_PER_SEC;
		cout << "\tTIME:\t" << Time_B << "\t|\t" << t4 - t3 << "\t|" << endl;

		N += 10;

	} 

	cout << "N = " << N << " Time D: " << Time_B << endl;
	//100-120
}