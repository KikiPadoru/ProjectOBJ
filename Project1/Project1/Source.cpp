#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> Graph, vector<int> &D, int s)
{
	
	D[s] = 0;
	vector<bool> R(26);
	R[0] = true;
	queue  < int> Q;
	Q.push(s);

	while (!Q.empty())
	{
		int r = Q.front();
		Q.pop();

		for (int i = 0; i < Graph[r].size(); i++)
		{
			if (R[Graph[r][i]]) continue;
			Q.push(Graph[r][i]);
			R[Graph[r][i]] = true;
			D[Graph[r][i]] = 1 + D[r];
		}
	}
	
}

void ww(vector<int>& Roads, vector<vector<int>> Graph, int r, queue<int>& Q, vector<bool>& R, vector<bool>& RR)
{
	for (int i = 0; i < Graph[r].size(); i++)
	{
		if (!R[Graph[r][i]]) {
			if (!RR[Graph[r][i]]) {
				Q.push(Graph[r][i]);
				RR[Graph[r][i]] = true;
			}
			Roads[Graph[r][i]] += Roads[r];
		}
	}
}

void rr(vector<vector<int>> Graph, vector<int> D, vector<int>& Roads, int r1, int r2, int dist = 0)
{
	queue<int> Q;
	Q.push(r1);
	vector<bool> R(26);
	vector<bool> RR(26);
	while (D[r2] - D[r1] > dist)
	{
		int len = Q.size();
		cout << len << endl;
		while (len) {
		int r = Q.front(); Q.pop();
		R[r] = true;
			ww(Roads, Graph, r, Q, R, RR);
			len--;
		}

		dist++;
	}
}

int main()  
{
	int edges;
	cin >> edges;

	vector<vector<int>> Graph(26);

	for (int i = 0; i < edges; i++)
	{
		int c, u;
		cin >> c >> u;

		for (int j = 0; j < c - 1; j++)
		{
			int v;
			cin >> v;
			
			Graph[u - 1].push_back(v - 1);
			Graph[v - 1].push_back(u - 1);
		}
	}

	vector<int> D(26);
	bfs(Graph, D, 0);
		
	for (int i = 0; i < D.size(); i++)
		cout << D[i] << " ";

	cout << "\n";

	int r1 = 1, r2 = 2;
	vector<int> Roads(26);
	Roads[r1] = 1;

	rr(Graph, D, Roads, r1, r2);

		//int req;
		//cin >> req;
		//
		//for (int i = 0; i < req; i++) {
		//	int r1, r2;
		//	cin >> r1 >> r2;
		//	vector<int> Roads(26);
		//	Roads[r1 - 1] = 1;
		//	rr(Graph, D, Roads, r1 - 1, r2 - 1);
		//	

			for (int i = 0; i < Roads.size(); i++)
				cout << Roads[i] << " ";

		//	cout << endl;

		//cout << r1 << " " << r2 << " " << Roads[r2 - 1] << endl;



}