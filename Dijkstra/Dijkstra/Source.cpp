#include <iostream>
#include <vector>
#include <queue>
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

	vector<vector<pair<int, int>>> Graph(count);

	for (int i = 0; i < edge; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		Graph[u - 1].push_back(make_pair(v - 1, c));
	}

	vector<bool> R(count);
	vector<int> D(count);
	vector<int> F(count);

	cin >> a;

	R[a - 1] =  true;

	for (int i = 0; i < Graph[a - 1].size(); i++)
	{
		F[Graph[a-1][i].first] = a - 1;
		D[Graph[a - 1][i].first] = Graph[a - 1][i].second;
	}

	for (int i = 0; i < D.size(); i++)
		if (D[i] == 0) {
			D[i] = 99999;
			R[i] = true;
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
		R[min_v] = true;
		for (int i = 0; i < Graph[min_v].size(); i++)
		{
			if (D[min_v] + Graph[min_v][i].second < D[Graph[min_v][i].first]) {
				F[Graph[min_v][i].first] = min_v;
				D[Graph[min_v][i].first] = D[min_v] + Graph[min_v][i].second;
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