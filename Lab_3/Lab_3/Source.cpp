#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

//Сортировка расческой
template <class T>
int comb_sort(vector<T>& A)
{
	int n = 0;
	double step = A.size() - 1;
	const double factor = 1.3;

	while (step >= 1)
	{
		//Слева направо
		for (int i = 0; i + step < A.size(); i++)
		{
			if (A[i] > A[i + step])
			{
				swap(A[i], A[i + step]);
				n++;
			}
		}
		//Справа налево
		for (int i = A.size() - 1; i - step >= 0; i--)
		{
			if (A[i] < A[i - step])
			{
				swap(A[i], A[i - step]);
				n++;
			}
		}
		step /= factor;
	}
	//Прохода расческой в две стороны вполне достаточно
	/*
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
	*/
	return n;
}

//Линейный поиск самого частовстречающегося элемента в массиве
template <class T>
T majority(vector<T>& A)
{
	T majority_elem = A[0];
	int max = 0;
	for (int i = 0; i < A.size(); i++)
	{
		int counter = 0;
		for (int j = 0; j < A.size(); j++)
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

//Проверка отсортированого массива
template <class T>
bool chk_comb(vector<T>& A)
{
	for (int i = 0; i < A.size() - 1; i++)
		if (A[i] > A[i + 1])
			return 0;
	return 1;
}

//Линейный поиск в отсортированном массиве
template <class T>
T in_order(vector<T>& A)
{
	T majority_elem = A[0];
	T cur = A[0];
	int max = 0;
	int counter = 1;
	for (int i = 1; i < A.size(); i++)
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
		if (max < counter)
		{
			majority_elem = cur;
		}
	}
	return majority_elem;
}

int main()
{
	int N = 1;

	while (N < 500)
	{
		vector<int> D(N);
		for (int i = 0; i < N; i++)
			D[i] = rand() % 100;

		cout << "N = " << N;

		// Ищем в неотсортированном массиве
		clock_t t1 = clock();
		int a = majority(D);
		clock_t t2 = clock();

		//Вывод результатов
		cout << endl << "Unsort: \t" << a;
		cout << "\tTIME:\t" << t2 - t1 << "\t|" << endl;

		// Ищем в отсортированном массиве
		clock_t t3 = clock();
		comb_sort(D);
		int b = in_order(D);
		clock_t t4 = clock();

		//Вывод результатов
		cout << "In Order:\t" << b;
		cout << "\tTIME:\t" << t4 - t3 << "\t|" << endl;
		//cout << "Correct sort? - " << chk_comb(D) << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		N += 10;
	}
	//  В зависимости от входных данных, метод с использованием "расчёски" начинает работать лучше при N больших 10-20. 
}
