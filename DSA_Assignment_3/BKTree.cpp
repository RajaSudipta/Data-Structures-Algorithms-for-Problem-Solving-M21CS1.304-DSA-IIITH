#include<iostream>
#include<set>
using namespace std;
set<string> autocorrect_set;
#define MAX_DISTANCE 3
#define MAX_LENGTH 100

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
	cout << root->str << " " << key << " : " << distance << endl;
	/* check whether there is any node present at that distance from root */
	// BKTreeNode *childNode = root->child[distance];
	if(root->child[distance] == NULL) // childNode->str == ""
	{
		root->child[distance] = new BKTreeNode(key);
		cout << "Inserted here" << endl;
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

int main()
{
	int n;
	cin >> n;
	string temp;
	BKTreeNode *root = NULL;
	for(int i=0; i<n; i++)
	{
		cin >> temp;
		if(i == 0)
		{
			root = new BKTreeNode(temp);
		}
		else
		{
			insertBKTreeNode(root, temp);
		}
	} 
	autocorrect_set.clear();
	cin >> temp;
	autoCorrect(root, temp);
	cout << autocorrect_set.size() << endl;
	for(auto it: autocorrect_set)
	{
		cout << it << endl;
	}
	return 0;
}