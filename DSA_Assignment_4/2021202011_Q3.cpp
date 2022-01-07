#include<iostream>
using namespace std;
typedef long long int ll;

// 1 <= N, q <= 10 ^ 5
// 1 <= A[i] <= 10 ^ 12

class TrieNode
{
public:
	TrieNode *left;
	TrieNode *right;
	bool isLeaf;
};

void insertTrie(TrieNode *head, ll key)
{
	TrieNode *curr_node = head;
	/* 10^12 means 40 bits in binary form */
	for(int i=62; i>=0; i--)
	{
		/* find ith bit of the number (0 or 1) */
		int bit = (key >> i) & (1);

		/* if the bit is 0, then go to left branch which represents 0 */
		if(bit == 0)
		{
			/* if node not created, create node */
			if(curr_node->left == NULL)
			{
				curr_node->left = new TrieNode();
			}
			curr_node = curr_node->left;
		}
		/* if the bit is 1, then go to right branch which represents 1 */
		else
		{
			/* if node not created, create node */
			if (curr_node->right == NULL)
			{
				curr_node->right = new TrieNode();
			}
			curr_node = curr_node->right;
		}
	}
}

ll findMaxXor(TrieNode *head, ll query)
{
	TrieNode *curr_node = head;
	ll curr_xor = 0;
	for(int i=62; i>=0; i--)
	{
		/* find ith bit of the query number */
		int bit = (query >> i) & (1);
		/* if ith bit is '0', search for '1' to get maximum xor, we'll find 1 in right branch. */
		/* so, try to go in right branch, if right branch does not exists, anyway we need to go to left branch */
		if(bit == 0)
		{
			if(curr_node->right != NULL)
			{
				/* increment by (2^i), bcoz at place i, (0 xor 1) =1, so, at ith bit it will produce 1*/
				ll increment = (1 << i);
				curr_xor += increment;
				curr_node = curr_node->right;
			}
			else
			{
				curr_node = curr_node->left;
			}
		} 
		/* if bit is 1 */
		else
		{
			if(curr_node->left != NULL)
			{
				ll increment = (1 << i);
				curr_xor += increment;
				curr_node = curr_node->left;
			}
			else
			{
				curr_node = curr_node->right;
			}
		}
	}
	return curr_xor;
}

int main()
{
	int n, q;
	cin >> n >> q;
	TrieNode *root = new TrieNode();
	ll temp;
	for(int i=0; i<n; i++)
	{
		cin >> temp;
		insertTrie(root, temp);
	}
	for(int i=0; i<q; i++)
	{
		cin >> temp;
		ll xor_res = findMaxXor(root, temp);
		cout << xor_res << endl;
	}
	return 0;
}