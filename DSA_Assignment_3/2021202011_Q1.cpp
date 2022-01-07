#include<iostream>
#include<set>
#define CORPUS_SIZE 26
#define MAX_DISTANCE 3
#define MAX_LENGTH 100
using namespace std;
set<string> autocomplete_set;
set<string> autocorrect_set;


class BKTreeNode
{
public:
	bool isFilled;
	string str;
	BKTreeNode *child[2*MAX_LENGTH];
	BKTreeNode(){}
	BKTreeNode(string s)
	{
		isFilled = true;
		str = s;
		for(int i=0; i<2*MAX_LENGTH; i++)
		{
			child[i] = NULL;
		}
	}
	~BKTreeNode(){}
};

int edit_distance(string str1, string str2)
{
	int len1 = str1.length();
	int len2 = str2.length();

	int dp[len1+1][len2+1];

	for(int i=0; i<=len1; i++)
	{
		dp[i][0] = i;
	}
	for(int j=0; j<=len2; j++)
	{
		dp[0][j] = j;
	}
	for(int i=1; i<=len1; i++)
	{
		for(int j=1; j<=len2; j++)
		{
			if(str1[i-1] == str2[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
			}
		}
	}
	return dp[len1][len2];
}

void insertBKTreeNode(BKTreeNode *root, string key)
{
	// BKTreeNode *curr_node = new BKTreeNode(key);
	// if(root->isFilled == false) // root->str == ""
	// {
	// 	cout << "Inside here" << endl;
	// 	root = curr_node;
	// 	return;
	// }
	int distance = edit_distance(root->str, key);
	// cout << root->str << " " << key << " : " << distance << endl;
	/* check whether there is any node present at that distance from root */
	if(root->child[distance] == NULL) // childNode->str == ""
	{
		root->child[distance] = new BKTreeNode(key);
		// cout << "Inserted here" << endl;
	}
	else
	{
		insertBKTreeNode(root->child[distance], key);
	}
}

void autoCorrect(BKTreeNode *root, string key)
{
	if(root == NULL) // root->str == ""
	{
		return;
	}
	else
	{
		int distance = edit_distance(root->str, key);
		if(distance <= MAX_DISTANCE)
		{
			autocorrect_set.insert(root->str);
		}
		int distance_lower_limit = distance - MAX_DISTANCE;
		int distance_upper_limit = distance + MAX_DISTANCE;

		if(distance_lower_limit < 0)
		{
			distance_lower_limit = 1;
		}
		for(int i=distance_lower_limit; i<=distance_upper_limit; i++)
		{
			autoCorrect(root->child[i], key);
		}
	}
}

class TrieNode
{
public:
	bool isEnd;
	TrieNode *child[CORPUS_SIZE];
	TrieNode()
	{
		isEnd = false;
		for(int i=0; i<CORPUS_SIZE; i++)
		{
			child[i] = NULL;
		}
	}
	~TrieNode()
	{

	}
};

bool isLastTrieNode(TrieNode *root)
{
	bool flag = true;
	for(int i=0; i<CORPUS_SIZE; i++)
	{
		if(root->child[i] != NULL)
		{
			flag = false;
			break;
		}
	}
	return flag;
}

void insertTrie(TrieNode *root, string key)
{
	TrieNode *curr_node = root;
	int len = key.length();
	for(int i=0; i<len; i++)
	{
		char c = key[i];
		if(curr_node->child[c - 'a'] == NULL)
		{
			curr_node->child[c-'a'] = new TrieNode();
		}
		curr_node = curr_node->child[c-'a'];
	}
	curr_node->isEnd = true;
}

bool searchTrie(TrieNode *root, string key)
{
	TrieNode *curr_node = root;
	int len = key.length();
	for(int i=0; i<len; i++)
	{
		char c = key[i];
		if(curr_node->child[c-'a'] == NULL)
		{
			return false;
		}
		curr_node = curr_node->child[c-'a'];
	}
	if(curr_node->isEnd == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void autocomplete_helper(TrieNode *root, const string key)
{
	string prefix = key;
	if(root->isEnd == true)
	{
		autocomplete_set.insert(key);
	}
	TrieNode *curr_node = root;
	if(isLastTrieNode(root) == true)
	{
		return;
	}
	int i=0;
	while(i < CORPUS_SIZE)
	{
		if(curr_node->child[i] != NULL)
		{
			string temp = prefix + char(i+97);
			autocomplete_helper(curr_node->child[i], temp);
		}
		i++;
	}
}

void autocomplete(TrieNode *root, string key)
{

	TrieNode *curr_node = root;
	int len = key.length();
	for(int i=0; i<len; i++)
	{
		char c = key[i];
		if(curr_node->child[c-'a'] == NULL)
		{
			return;
		}
		curr_node = curr_node->child[c-'a'];
	}
	if(isLastTrieNode(curr_node) == true)
	{
		if(curr_node->isEnd == true)
		{
			autocomplete_set.insert(key);
		}
	}
	else
	{
		autocomplete_helper(curr_node, key);
	}
}

int main()
{
	autocomplete_set.clear();
	int n;
	cin >> n;
	string temp;
	TrieNode *root = new TrieNode();
	BKTreeNode *BKroot = NULL;
	for(int i=0; i<n; i++)
	{
		cin >> temp;
		insertTrie(root, temp);
		if(i == 0)
		{
			BKroot = new BKTreeNode(temp);
		}
		else
		{
			insertBKTreeNode(BKroot, temp);
		}
	}

	int operation; 
	bool flag;
	while(true)
	{
		autocomplete_set.clear();
		autocorrect_set.clear();
		cin >> operation;
		if(operation == 1)
		{
			cin >> temp;
			flag = searchTrie(root, temp);
			cout << flag << endl;
		}
		else if(operation == 2)
		{
			cin >> temp;
			autocomplete(root, temp);
			if(autocomplete_set.size() == 0)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << autocomplete_set.size() << endl;
				for(auto it: autocomplete_set)
				{
					cout << it << endl;
				}
			}
		}
		else if(operation == 3)
		{
			cin >> temp;
			autoCorrect(BKroot, temp);
			cout << autocorrect_set.size() << endl;
			for(auto it: autocorrect_set)
			{
				cout << it << endl;
			}
		}
		else
		{
			exit(0);
		}
	}

	return 0;
}