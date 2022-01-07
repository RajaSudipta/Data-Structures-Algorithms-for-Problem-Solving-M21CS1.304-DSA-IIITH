#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

int d1[] = {-1, 0, 1, 0};
int d2[] = {0, 1, 0, -1};

int validCoordinate(int x, int y, int row, int col)
{
	if(x<0 || x>=row || y<0 || y>=col)
	{
		return false;
	}
	return true;
}

int solver(vector<vector<char>> grid, int row, int col, int src_x, int src_y, int dest_x, int dest_y, vector<vector<bool>> &visited)
{
	queue<pair<pair<int, int>, int>> q; // ((x, y), turn)
	q.push(make_pair(make_pair(src_x, src_y), 0));
	while(!q.empty())
	{
		int curr_x = q.front().first.first;
		int curr_y = q.front().first.second;
		int turn = q.front().second;
		visited[curr_x][curr_y] = true;
		q.pop();

		if(curr_x == dest_x && curr_y == dest_y)
		{
			return turn;
		}

		for(int i=0; i<4; i++)
		{
			int neighbour_x = curr_x + d1[i];
			int neighbour_y = curr_y + d2[i];
			int new_turn = turn + 1;
			if(validCoordinate(neighbour_x, neighbour_y, row, col)==true)
			{
				if(grid[neighbour_x][neighbour_y] == '.')
				{
					if(visited[neighbour_x][neighbour_y] == false)
					{
						q.push(make_pair(make_pair(neighbour_x, neighbour_y), new_turn));
					}					
				}
			}
		}
	}
	return INT_MAX;
}

int main()
{
	int row, col;
	// cout << "Enter rows and cols: ";
	cin >> row >> col;
	vector<vector<char>> grid(row, vector<char>(col));
	char ch;
	int src_x, src_y, dest_x, dest_y;
	bool flag = false;
	vector<pair<int, int>> riders;
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			cin >> ch;
			grid[i][j] = ch;
			if(ch == '.' && flag == false)
			{
				dest_x = i;
				dest_y = j;
				flag = true;
			}
			if(ch == 'A')
			{
				src_x = i;
				src_y = j;
			}
			if(ch == 'R')
			{
				riders.push_back(make_pair(i, j));
			}
		}
	}

	int res = INT_MAX;
	/* find out the minimum distance paths among all the other riders */
	for(int i=0; i<(int)riders.size(); i++)
	{
		int curr_rider_x = riders[i].first;
		int curr_rider_y = riders[i].second;
		// cout << curr_rider_x << " " << curr_rider_y << endl;
		vector<vector<bool>> visited(row,vector<bool>(col,false));
		int curr_rider_path_distance = solver(grid, row, col, curr_rider_x, curr_rider_y, dest_x, dest_y, visited);
		res = min(res, curr_rider_path_distance);
	}

	/* find out the minimum distance pathof A */
	vector<vector<bool>> visited(row,vector<bool>(col,false));
	int path_distance_A = solver(grid, row, col, src_x, src_y, dest_x, dest_y, visited);

	if(path_distance_A <= res)
	{
		cout << "YES" << endl;
		cout << path_distance_A << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	// vector<vector<bool>> visited(row,vector<bool>(col,false));
	// int res = solver(grid, row, col, src_x, src_y, dest_x, dest_y, visited);

	// cout << "Source: " << src_x << ", " << src_y << endl;
	// cout << "Destination: " << dest_x << ", " << dest_y << endl;

	// if(res == INT_MAX)
	// {
	// 	cout << "NO" << endl;
	// }
	// else
	// {
	// 	cout << "YES" << endl;
	// 	cout << res << endl;
	// }

	return 0;
}