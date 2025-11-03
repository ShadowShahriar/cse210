#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool hasDFSCycle(int u, const vector<vector<int>> &adj, vector<int> &color)
{
	color[u] = 1; // visiting
	for (int v : adj[u])
	{
		if (color[v] == 1)
			return true; // back to the edge -> cycle
		else if (color[v] == 0)
		{
			if (hasDFSCycle(v, adj, color))
				return true;
		}
	}
	color[u] = 2; // done
	return false;
}

int main()
{
	long long M, N;
	cout << "Number of Nodes: ";
	cin >> N;
	cout << "Number of Edges: ";
	cin >> M;

	vector<pair<string, string>> edges;
	edges.reserve((size_t)M);

	string a, b;
	cout << "Edges:" << endl;
	for (long long i = 0; i < M; ++i)
	{
		if (!(cin >> a >> b))
			break;
		edges.emplace_back(a, b);
	}

	unordered_map<string, int> idx;
	idx.reserve(edges.size() * 2 + 10);
	for (auto &e : edges)
	{
		if (idx.find(e.first) == idx.end())
		{
			int id = (int)idx.size();
			idx[e.first] = id;
		}
		if (idx.find(e.second) == idx.end())
		{
			int id = (int)idx.size();
			idx[e.second] = id;
		}
	}

	int n = (int)idx.size();
	vector<vector<int>> adj(n);
	for (auto &e : edges)
	{
		int u = idx[e.first];
		int v = idx[e.second];
		adj[u].push_back(v);
	}

	if (N > n)
	{
		int extra = (int)N - n;
		adj.resize((size_t)N);
		n = (int)N;
	}

	vector<int> color(n, 0);
	bool hasCycle = false;
	for (int i = 0; i < n && !hasCycle; ++i)
		if (color[i] == 0)
			if (hasDFSCycle(i, adj, color))
				hasCycle = true;

	cout << "Deadlock: " << (hasCycle ? "Yes" : "No") << endl;
	return 0;
}
