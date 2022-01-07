#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool comp(const pair<int, string> &a, const pair<int, string> &b)
{
	/* if cost of two paths is same, prefer the lexicographically smaller one */
	if(a.first == b.first)
	{
		return a.second < b.second;
	}
	/* prefer the smaller cost */
	return a.first < b.first;
}

void listAllPaths(int src, int dest, vector<pair<int, int>> v[], int n, vector<bool> visited, string path, int cost, vector<pair<int, string>> &res)
{
	if(src == dest)
	{
		res.push_back(make_pair(cost, path));
		return;
	}
	visited[src] = true;
	for(int i=0; i<(int)v[src].size(); i++)
	{
		int neighbour_node = v[src][i].first;
		int weight = v[src][i].second;
		if(visited[neighbour_node] == false)
		{
			string temp_path = path + " " + to_string(neighbour_node);
			int temp_cost = cost + weight;
			listAllPaths(neighbour_node, dest, v, n, visited, temp_path, temp_cost, res);
		}
	}
	visited[src] = false;
}

int main()
{
	int n;
	// cout << "Enter no. of cities: ";
	cin >> n;
	vector<pair<int, int>> v[n];
	int m;
	// cout << "Enter no. of edges: ";
	cin >> m;
	int x, y, z;
	// cout << "Enter the edges and weights(x y wt): " << endl;
	for(int i=0; i<m; i++)
	{
		cin >> x >> y >> z;
		v[x].push_back(make_pair(y, z));
		v[y].push_back(make_pair(x, z));
	}
	
	int k;
	// cout << "Enter 'k' for k shortest paths: ";
	cin >> k;
	vector<pair<int, string>> res;
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			int src = i;
			int dest = j;
			string path = to_string(src);
			int cost = 0;
			vector<bool> visited(n, false);
			listAllPaths(src, dest, v, n, visited, path, cost, res);
		}
	}
	if(res.size() > 0)
	{
		sort(res.begin(), res.end());
		// cout << "Printing all the paths" << endl;
		// for(int i=0; i<(int)res.size(); i++)
		// {
		// 	cout << res[i].second << endl;
		// }
		// cout << "Printing " << k << " shortest paths" << endl;
		if(k > (int)res.size())
		{
			// cout << "count of total paths is less than k" << endl;
			for(int i=0; i<(int)res.size(); i++)
			{
				cout << res[i].second << endl;
			}
		}
		else
		{
			for(int i=0; i<k; i++)
			{
				cout << res[i].second << endl;
			}
		}
	}
	

	return 0;
}