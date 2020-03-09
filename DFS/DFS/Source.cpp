#include <iostream>
#include <vector>
using namespace std;


void dfs(vector<vector<int>> &Graph, vector<int> &Num, vector<pair<int, int>> &T, vector<bool> &R, int v, int n)
{
	R[v] = true;
	Num[v] = n;
	n++;
	for (int w = 0; w < Graph[v].size(); w++)
	{
		if (!R[Graph[v][w]])
		{
			T.push_back(make_pair(v, Graph[v][w]));
			dfs(Graph, Num, T, R, Graph[v][w], n);
		}
	}
}

int main()
{
	int count, edges;
	cin >> count >> edges;

	vector<vector<int>> Graph(count);

	for (int i = 0; i < edges; i++)
	{
		int v, w;
		cin >> v >> w;
		Graph[v - 1].push_back(w - 1);
		Graph[w - 1].push_back(v - 1);
	}

	vector<int> Num(count);
	vector<pair<int, int>> T;
	vector<bool> R(count);
	int n = 1;

	dfs(Graph, Num, T, R, 0, n);

	for (int i = 0; i < T.size(); i++)
		cout << T[i].first + 1 << " " << T[i].second + 1<< endl;

}