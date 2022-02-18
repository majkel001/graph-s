#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(vector<vector<int>>&graph,int v,bool visited[])
{
	stack<int>Q;
	Q.push(v);
	int acc_node;
	while (!Q.empty())
	{
		acc_node = Q.top();
		visited[acc_node] = true;
		cout << acc_node + 1 << " ";
		Q.pop();
		for (int i = 0; i < graph[acc_node].size(); i++)
		{
			if (!visited[graph[acc_node][i]])
			{
				Q.push(graph[acc_node][i]);
			}
		}
	}

}

int main()
{
	int V, E;
	cin >> V >> E;

	bool* visited = new bool[V * sizeof(bool)];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	vector<vector<int>>graph;
	graph.reserve(V);
	graph.resize(V);

	int a, b;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(graph, 0, visited);

	delete[]visited;
	return 0;
}
