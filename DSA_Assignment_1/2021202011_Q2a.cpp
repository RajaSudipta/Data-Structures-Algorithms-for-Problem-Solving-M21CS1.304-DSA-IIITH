// Type 1: construction of cache
// 1 
// K
// Type 2: get
// 2
// Key
// Type 3: set
// 3
// Key newvalue

/* LRU Cache */

#include<iostream>
#include<map>
using namespace std;

typedef struct DLLNode
{
	int key;
	int value;
	struct DLLNode *prev;
	struct DLLNode *next;
	DLLNode(int k, int v)
	{
		key = k;
		value = v;
		prev = NULL;
		next = NULL;
	}
}DLLNode;

class LRUCache
{
public:
	int capacity;
	map<int, DLLNode*> m;

	DLLNode *head = new DLLNode(0, 0);
	DLLNode *tail = new DLLNode(0, 0);
	
	/* constructor for initializing capacity */
	LRUCache(int _capacity)
	{
		capacity = _capacity;
		head->next = tail;
		tail->prev = head;
	}

	/* function for getting value of a key */
	int get(int key)
	{
		/* key not found in cache */
		if(m.find(key) == m.end())
		{
			return -1;
		}
		else
		{
			DLLNode *temp = m[key];
			int data = temp->value;

			/* delete the node from the DLL */
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete(temp);
			temp = NULL;

			/* create new node with (key, value) and insert just after head */
			DLLNode *newNode = new DLLNode(key, data);
			newNode->next = head->next;
			newNode->prev = head;
			head->next->prev = newNode;
			head->next = newNode;

			/* update the newNode address in the map */
			m[key] = newNode;

			return data;
		}
	}

	/* function for putiing (key, value) */
	void put(int key, int data)
	{
		if(capacity == 0)
		{
			return;
		}
		/* key already present in the map */
		if(m.find(key) != m.end())
		{
			DLLNode *temp = m[key];

			/* delete the node from the DLL */
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete(temp);
			temp = NULL;

			/* create new node with (key, value) and insert just after head */
			DLLNode *newNode = new DLLNode(key, data);
			newNode->next = head->next;
			newNode->prev = head;
			head->next->prev = newNode;
			head->next = newNode;

			/* update the newNode address in the map */
			m[key] = newNode;
		}
		/* if key is not present in the map */
		else
		{
			/* if map size is under capacity of cache */
			if((int)m.size() < capacity)
			{
				/* create new node with (key, value) and insert just after head */
				DLLNode *newNode = new DLLNode(key, data);
				newNode->next = head->next;
				newNode->prev = head;
				head->next->prev = newNode;
				head->next = newNode;

				/* update the newNode address in the map */
				m[key] = newNode;
			}
			/* map size has reached capacity */
			else
			{
				/* delete the LRU Node before tail Node */
				DLLNode *temp = tail->prev;
				temp->prev->next = tail;
				tail->prev = temp->prev;
				m.erase(temp->key); // delete the node from the map 
				delete(temp);
				temp = NULL;

				/* create new node with (key, value) and insert just after head */
				DLLNode *newNode = new DLLNode(key, data);
				newNode->next = head->next;
				newNode->prev = head;
				head->next->prev = newNode;
				head->next = newNode;

				/* update the newNode address in the map */
				m[key] = newNode; 
			}
		}
	}
};

int main()
{
	LRUCache *obj;
	while(true)
	{
		int operation;
		cin >> operation;
		/* capacity fix */
		if(operation == 1)
		{
			int capacity;
			cin >> capacity;
			obj = new LRUCache(capacity);
		}
		/* get key */
		else if(operation == 2)
		{
			int key;
			cin >> key;
			int res = obj->get(key);
			cout << res << endl;
		}
		else if(operation == 3)
		{
			int key, value;
			cin >> key >> value;
			obj->put(key, value);
		}
		else
		{
			cout << "Wrong input" << endl;
			break;
		}
	}
	return 0;
}




// int main()
// {
// 	int capacity;
// 	// cout << "Enter the Capacity of LRU Cache: ";
// 	cin >> capacity;
// 	cout << endl;
// 	LRUCache *obj = new LRUCache(capacity);
// 	while(true)
// 	{
// 		int type;
// 		cout << "Choice operation [ put(1) / get(2) / exit(3)] : " << endl;
// 		cin >> type;
// 		if(type == 1)
// 		{
// 			int key, value;
// 			cout << "Enter key and value separated by space [example:(x y)]: ";
// 			cin >> key >> value;
// 			obj->put(key, value);
// 		}
// 		else if(type == 2)
// 		{
// 			int key;
// 			cout << "Enter the key: ";
// 			cin >> key;
// 			int res = obj->get(key);
// 			cout << res << endl;
// 		}
// 		else if(type == 3)
// 		{
// 			break;
// 		}
// 		else
// 		{
// 			cout << "Wrong input!!" << endl;
// 		}
// 	}
// 	return 0;
// }