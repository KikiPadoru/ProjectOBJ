#include <iostream>
#include <vector>
using namespace std;

bool checkR(vector<pair<int, int>>RE, int v, int w)
{
	for (int i = 0; i < RE.size(); i++)
		if (RE[i].first == w && RE[i].second == v)
			return 0;
	return 1;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

void dfs(vector<vector<int>>& Graph, vector<int>& Num, vector<int>& Up, vector<pair<int, int>>& T, vector<pair<int, int>>& RE, vector<pair<int, int>> &Bridge, vector<bool>& R, int v, int &n, int prev)
{
	R[v] = true;
	Num[v] = n;
	Up[v] = Num[v];
	n++;

	for (int w = 0; w < Graph[v].size(); w++)
	{
		if (!R[Graph[v][w]])
		{
			T.push_back(make_pair(v, Graph[v][w]));
			dfs(Graph, Num, Up, T, RE, Bridge, R, Graph[v][w], n, v);
			Up[v] = min(Up[v], Up[Graph[v][w]]);

		}
		else if (R[Graph[v][w]] && prev != Graph[v][w] && checkR(RE, v, Graph[v][w])) {
			RE.push_back(make_pair(v, Graph[v][w]));
			Up[v] = min(Up[v], Num[Graph[v][w]]);
		}

		if (Up[Graph[v][w]] > Num[v])
			Bridge.push_back(make_pair(v, Graph[v][w]));

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
	vector<int> Up(count);
	vector<pair<int, int>> T;
	vector<pair<int, int>> Bridge;
	vector<pair<int, int>> RE;
	vector<bool> R(count);
	int n = 1;

	dfs(Graph, Num, Up, T, RE, Bridge, R, 0, n, -1);

	cout << "\nSpanning Tree: " << endl;
	for (int i = 0; i < T.size(); i++)
		cout << T[i].first +1 << " " << T[i].second +1 << endl;

	if (Bridge.size())
	{
		cout << "\nBridges: " << endl;
		for (int i = 0; i < Bridge.size(); i++)
			cout << Bridge[i].first + 1 << " " << Bridge[i].second + 1 << endl;
	}
	else
		cout << "\nBridge Not Found" << endl;

/*
	cout << "\nReverse Edges: " << endl;
	for (int i = 0; i < RE.size(); i++)
		cout << RE[i].first +1 << " " << RE[i].second +1 << endl;

	cout << "\nNum: " << endl;
	for (int i = 0; i < Num.size(); i++)
		cout << Num[i] << " ";
	cout << "\n\nUp: " << endl;
	for (int i = 0; i < Up.size(); i++)
		cout << Up[i] << " ";
*/
}