#include <iostream>
#include <vector>

using namespace std;

bool checkR(vector<bool> R)
{
	int count = 0;
	for (int i = 0; i < R.size(); i++)
		if (!R[i])
			return 1;
	return 0;
}

int main()
{
	int count, edge, a;
	cin >> count >> edge;

	vector<vector<pair<int, int>>> Graph(count, vector<pair<int, int>> (count));

	for (int i = 0; i < Graph.size(); i++) {
		for (int j = 0; j < Graph[i].size(); j++)
			cout << " " << Graph[i][j].first << " ";
		cout << endl;
	}

	for (int i = 0; i < edge; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		Graph[u - 1][v - 1].first = v - 1;
		Graph[u - 1][v - 1].second = c;
	}

	vector<bool> R(count);
	vector<int> D(count);
	vector<int> F(count);

	cin >> a;

	for (int i = 0; i < Graph.size(); i++)
		for (int j = 0; j < Graph[i].size(); j++)
			if (Graph[i][j].second == 0) {
				Graph[i][j].second = 99999;
				R[Graph[i][j].first] = true;
			}

	R[a - 1] = true;
	

	for (int i = 0; i < Graph[a - 1].size(); i++)
	{
		F[i] = a - 1;
		D[i] = Graph[a - 1][i].second;
	}

	D[a - 1] = 0;

	while (checkR(R)) {
		int min = 99999, min_v = -1;
		for (int i = 0; i < D.size(); i++)
			if (D[i] < min && !R[i])
			{
				min = D[i];
				min_v = i;
			}
		if (min_v == -1)
			break;
		R[min_v] = true;
		for (int i = 0; i < Graph[min_v].size(); i++)
		{
			if (D[min_v] + Graph[min_v][i].second < D[i]) {
				F[i] = min_v;
				D[i] = D[min_v] + Graph[min_v][i].second;
			}
		}
	}

	cout << "F: ";

	for (int i = 0; i < F.size(); i++)
		cout << F[i] + 1<< " ";

	cout << endl << "D: ";
	 
	for (int i = 0; i < D.size(); i++)
		if (D[i] == 99999)
			cout << "inf ";
		else
		cout << D[i] << " ";
}