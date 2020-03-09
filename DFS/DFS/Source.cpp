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

void dfs(vector<vector<int>>& Graph, vector<int>& Num, vector<int>& Up, vector<pair<int, int>>& T, vector<pair<int, int>>& RE, vector<pair<int, int>> &Bridge, vector<bool>& R, int &n, int v, int prev)
{
	R[v] = true;
	Num[v] = n;
	Up[v] = Num[v];
	n++;

	for (int w : Graph[v])
	{
		if (!R[w])
		{
			T.push_back(make_pair(v, w));
			dfs(Graph, Num, Up, T, RE, Bridge, R, n, w, v);
			Up[v] = min(Up[v], Up[w]);

		}
		else if (R[w] && prev != w && checkR(RE, v, w)) {
			RE.push_back(make_pair(v, w));
			Up[v] = min(Up[v], Num[w]);
		}

		if (Up[w] > Num[v])
			Bridge.push_back(make_pair(v, w));

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

	dfs(Graph, Num, Up, T, RE, Bridge, R, n, 0, -1);

	cout << "\nSpanning Tree: " << endl;
	for (pair<int, int> i : T)
		cout << i.first +1 << " " << i.second +1 << endl;

	if (Bridge.size())
	{
		cout << "\nBridges: " << endl;
		for (pair<int, int> i : Bridge)
			cout << i.first + 1 << " " << i.second + 1 << endl;
	}
	else
		cout << "\nBridge Not Found" << endl;

	cout << "\nReverse Edges: " << endl;
	for (pair<int, int> i : RE)
		cout << i.first +1 << " " << i.second +1 << endl;

	cout << "\nNum: " << endl;
	for (int i : Num)
		cout << i << " ";

	cout << "\n\nUp: " << endl;
	for (int i : Up)
		cout << i << " ";

}