#include<iostream>
#include<string>
using namespace std;

char grid[5000][5000];
bool visited[5000][5000];
string output[50000];
int output_size;
string input[50000];

class TrieNode 
{
public:
	string str;
	TrieNode *child[26];
	TrieNode()
	{
		str = "";
		for(int i=0; i<26; i++)
		{
			child[i] = NULL;
		}
	}
};

void insertTrie(TrieNode *root, string key)
{
	TrieNode *curr_node = root;
	int len = key.length();
	for(int i=0; i<len; i++)
	{
		char c = key[i];
		if(curr_node->child[c-'a'] == NULL)
		{
			curr_node->child[c-'a'] = new TrieNode();
		}
		curr_node = curr_node->child[c-'a'];
	}
	curr_node->str = key;
}

void dfs_traversal(int i, int j, int row, int col, TrieNode *root)
{
	// cout << "Inside dfs " << endl;
	if(i<0 || i>=row || j<0 || j>=col)
	{
		return;
	}
	if(visited[i][j] == true)
	{
		return;
	}
	// cout << "not returned" << endl;
	char ch = grid[i][j];
	// cout << "character: " << ch << endl;
	TrieNode *childNode = root->child[ch - 'a'];
	if(childNode == NULL)
	{
		return;
	}
	string temp = childNode->str;
	// cout << "string: " << temp << endl;
	if(temp.length() > 0)
	{
		// cout << "hi" << endl;
		childNode->str = "";
		output[output_size] = temp;
		output_size++;
	}
	visited[i][j] = true;
	dfs_traversal(i+1, j, row, col, childNode);
	dfs_traversal(i, j+1, row, col, childNode);
	dfs_traversal(i-1, j, row, col, childNode);
	dfs_traversal(i, j-1, row, col, childNode);
	visited[i][j] = false;
}

void findWordMatches(int row, int col, int X)
{
	TrieNode *root = new TrieNode();
	for(int i=0; i<X; i++)
	{
		string key = input[i];
		// cout << input[i] << " inserted in trie" << endl;
		insertTrie(root, key);
	}
	output_size = 0;
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			dfs_traversal(i, j, row, col, root);
		}
	}
}

int main()
{
	int r, c;
	cin >> r >> c;
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			cin >> grid[i][j];
			visited[i][j] = false;
		}
	}

	int X;
	cin >> X;
	for(int i=0; i<X; i++)
	{
		cin >> input[i];
	}

	findWordMatches(r, c, X);

	// cout << "output size: " << output_size << endl;

	// cout << "Unsorted output" << endl;
	// for(int i=0; i<output_size; i++)
	// {
	// 	cout << output[i] << " ";
	// }
	// cout << endl;

	/* sort the strings in output in lexicographical order */
	for(int i=0; i<output_size-1; i++)
	{
		for(int j=0; j<output_size-i-1; j++)
		{
			if(output[j] > output[j+1])
			{
				string temp;
				temp = output[j];
				output[j] = output[j+1];
				output[j+1] = temp;
			}
		}
	}

	// cout << "Sorted output" << endl;
	for(int i=0; i<output_size; i++)
	{
		cout << output[i] << " ";
	}

	return 0;
}
