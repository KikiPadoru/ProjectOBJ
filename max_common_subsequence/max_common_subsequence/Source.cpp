#include <iostream>
using namespace std;

int len(char* a)
{
	int i;
	for (i = 0; a[i]; i++);
	return i;
}

int main()
{
	char a[128] = "SUBSEQUENCE";
	char b[128] = "SUBSEQUENCE";

	int** table = new int* [len(a) + 1];
	for (int i = 0; i < len(a); i++)
		table[i] = new int[len(b) + 1];

	for (int i = 0; i < len(a); i++)
		for (int j = 0; j < len(b); j++)
			table[i][j] = 0;

	int max_i = 0;	int max_j = 0;	int max = 0;

	for (int i = 1; i < len(a); i++)
		for (int j = 1; j < len(b); j++)
			if (a[i - 1] == b[j - 1]) {
				table[i][j] = table[i - 1][j - 1] + 1;
				if (max < table[i][j]) {
					max = table[i][j];
					max_i = i;
					max_j = j;
				}
			}

	char* sub = new char[max];

	for (int i = max; i >= 0; i--, max_i--)
		sub[i] = a[max_i];
	sub[max + 1] = '\0';
	cout << sub << endl;

	for (int i = 0; i < len(a); i++) {
		cout << endl;
		for (int j = 0; j < len(b); j++)
			cout << table[i][j] << " ";
	}
}
