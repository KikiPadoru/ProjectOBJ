#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{

	ifstream in ("in.txt");

	int n, req;
	in >> n >> req;

	vector<vector<int>> graph;
	graph.resize(n);

	for (int i = 0; i < req; i++)
	{
		int u, v;	
		in >> u >> v;
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	in.close();

	//Output
	ofstream out("out.txt");
	for (int i = 0; i < graph.size(); i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
			out << graph[i][j] + 1 << " ";
		out << endl;
	}
	out.close();

}