#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>&graph, int v, bool visited[])
{
	visited[v] = true;
	cout << v+1<<" ";
	for (int i = 0; i < graph[v].size(); i++)
	{
		if (!visited[graph[v][i]])
			DFS(graph, graph[v][i], visited);
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
