// Type 1: construction of cache
// 1 
// K
// Type 2: get
// 2
// Key
// Type 3: set
// 3
// Key newvalue

/* LFU Cache */

#include<iostream>
#include<map>
using namespace std;

typedef struct Node
{
	int key;
	int value;
	int visited;
	struct Node *prev;
	struct Node *next;
	Node(int k, int v)
	{
		key = k;
		value = v;
		visited = 1;
	}
}Node;

typedef struct DLList
{
	int size;
	Node *head = new Node(0, 0);
	Node *tail = new Node(0, 0);
    
	DLList()
	{
		tail->prev = head;
		head->next = tail;
		size = 0;
	}
    
    void deleteNode(Node* targetNode) 
    {
        targetNode->next->prev = targetNode->prev;
        targetNode->prev->next = targetNode->next;
        size = size - 1;
    }
    
    void addNodeAfterHead(Node *targetNode) 
    {
        targetNode->next = head->next;
        targetNode->prev = head;
        head->next->prev = targetNode;
        head->next = targetNode;
        size = size + 1;
    }
    
}DLList;

class LFUCache {
public:
	map<int, Node*> keyNodeMap;
	map<int, DLList*> frequencyDLListMap;
	int cache_capacity, curr_capacity;
	int min_freq;

	LFUCache(int capacity)
	{
		cache_capacity = capacity;
		curr_capacity = 0;
		min_freq = 0;
	}

	int get(int key)
	{
		/* check if key is already present in map or not */
		if(keyNodeMap.find(key) == keyNodeMap.end())
		{
			return -1;
		}
		else
		{
			/* find the node which needs to be updated */
			Node *targetNode = keyNodeMap[key];
            int curr_freq = targetNode->visited;
            int data = targetNode->value;
            
            /* erase the node from the keyNodeMap */
            keyNodeMap.erase(key);
            
            /* erase the node from the DLList */
            frequencyDLListMap[curr_freq]->deleteNode(targetNode);
            
            /* if it was the last node of the DLList and the list has become empty and the list was of minimum frequency */
            /* increase the min_freq */
            if(curr_freq == min_freq && frequencyDLListMap[curr_freq]->size == 0)
            {
                min_freq = min_freq + 1;
            }
            
            int next_freq = curr_freq + 1;
            DLList *nextFreqDLList;
            
            /* Pointing to the next_freq DLList */
            if(frequencyDLListMap.find(next_freq) == frequencyDLListMap.end())
            {
                nextFreqDLList = new DLList();
            }
            else
            {
                nextFreqDLList = frequencyDLListMap[next_freq];
            }
            
            /* increase the targetNode's visited by 1 */
            targetNode->visited = next_freq;

            /* add the targetNode after head of nextFreqDLList */
            nextFreqDLList->addNodeAfterHead(targetNode);

            /* update the frequencyDLListMap */
            frequencyDLListMap[next_freq] = nextFreqDLList;

            /* update the keyNodeMap */
            keyNodeMap[key] = targetNode;
                        
            return data;
		}
	}

	void put(int key, int value)
	{
		if(cache_capacity == 0)
		{
			return;
		}
		if(keyNodeMap.find(key) != keyNodeMap.end())
        {
        	/* find the node which needs to be updated */
            Node *targetNode = keyNodeMap[key];
            targetNode->value = value;
            
            int curr_freq = targetNode->visited;
            int data = targetNode->value;
            
            /* erase the node from the keyNodeMap */
            keyNodeMap.erase(key);
            
            /* erase the node from the DLList */
            frequencyDLListMap[curr_freq]->deleteNode(targetNode);
            
            /* if it was the last node of the DLList and the list has become empty and the list was of minimum frequency */
            /* increase the min_freq */
            if(curr_freq == min_freq && frequencyDLListMap[curr_freq]->size == 0)
            {
                min_freq = min_freq + 1;
            }
            
            int next_freq = curr_freq + 1;
            DLList *nextFreqDLList;
            
            /* Pointing to the next_freq DLList */
            if(frequencyDLListMap.find(next_freq) == frequencyDLListMap.end())
            {
                nextFreqDLList = new DLList();
            }
            else
            {
                nextFreqDLList = frequencyDLListMap[next_freq];
            }
            
            /* increase the targetNode's visited by 1 */
            targetNode->visited = next_freq;

            /* add the targetNode after head of nextFreqDLList */
            nextFreqDLList->addNodeAfterHead(targetNode);

            /* update the frequencyDLListMap */
            frequencyDLListMap[next_freq] = nextFreqDLList;

            /* update the keyNodeMap */
            keyNodeMap[key] = targetNode;
            
        }
        else 
        {
            if(curr_capacity == cache_capacity)
            {
            	/* find out the minFreqDLList */
                DLList *minFreqList = frequencyDLListMap[min_freq];

                /* find out the LRU Node from the minFreqDLList */
                Node *targetNode = minFreqList->tail->prev;
                
                // cout << "Deleted key: " << targetNode->value << endl;
                
                /* delete the targetNode from the DLList */
                frequencyDLListMap[min_freq]->deleteNode(targetNode);
                
                /* delete the targetNode from the keyNodeMap */
                keyNodeMap.erase(targetNode->key);
                
                /* decrease the curr_capacity of the cache by 1 */
                curr_capacity = curr_capacity - 1;
            }
            
            /* new node gonna be inserted so increase the capacity by 1 */
            curr_capacity = curr_capacity + 1;
            
            /* new node, so it's min_freq will be 1 */
            min_freq = 1;
            
            DLList *newList;
            
            /* preparing the newDLList */
            if(frequencyDLListMap.find(min_freq) != frequencyDLListMap.end())
            {
                newList = frequencyDLListMap[min_freq];
            }
            else
            {
                newList = new DLList();
            }
            
            /* creating the newNode */
            Node *newNode = new Node(key, value);
            
            /* adding the node in the keyNodeMap */
            keyNodeMap[key] = newNode;
                
            /* adding the node after the head of the newDLList */
            newList->addNodeAfterHead(newNode);
            
            /* adding the newList in the frequencyDLListMap */
            frequencyDLListMap[min_freq] = newList;
        }
	}
};

int main()
{
	LFUCache *obj;
	while(true)
	{
		int operation;
		cin >> operation;
		/* capacity fix */
		if(operation == 1)
		{
			int capacity;
			cin >> capacity;
			obj = new LFUCache(capacity);
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
// 	cout << "Enter the Capacity of LFU Cache: ";
// 	cin >> capacity;
// 	cout << endl;
// 	LFUCache *obj = new LFUCache(capacity);
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