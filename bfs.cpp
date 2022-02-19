#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(bool visited[],vector<vector<int>>graph,int v)
{
	queue<int>Q;
	Q.push(v);
	int acc_node;
	while (!Q.empty())
	{
		acc_node = Q.front();
		cout << acc_node + 1 << " ";
		Q.pop();

		if (!visited[acc_node])
		{
			visited[acc_node] = true;
			for (int i = 0; i < graph[acc_node].size(); i++)
			{
				if (!visited[graph[acc_node][i]])
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
	
	BFS(visited,graph,0);
	delete[]visited;
	return 0;
}
