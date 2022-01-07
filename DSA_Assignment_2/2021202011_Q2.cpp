#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int res_arr_size;

template<class K, class V>
class MapNode {
public:
	K key;
	V value;
	MapNode * next;

	MapNode(K key, V value) {
		this->value = value;
		this->key = key;
		next = NULL;
	}

	~MapNode() {
		delete next;
	}
};

template<class K, class V>
class Unordered_map {
public:
	int curr_size;
	int bucketCount;
	// int *p = new int[10];
	MapNode<K, V>** mapNodeArray;

	Unordered_map() {
		bucketCount = 10;
		mapNodeArray = new MapNode<K, V>* [bucketCount];
		curr_size = 0;
		int i=0;
		while(i < bucketCount) {
			mapNodeArray[i] = NULL;
			i++;
		}
	}

	~Unordered_map() {
		int i=0;
		while(i < bucketCount) {
			delete (mapNodeArray[i]);
			i++;
		}
		delete []mapNodeArray;
	}

	// ~Unordered_map() {
	// 	for(int i=0; i<bucketCount; i++) {
	// 		MapNode<K, V> *curr = mapNodeArray[i];
	// 		MapNode<K, V> *next = NULL;
	// 		while(curr != NULL) {
	// 			next = curr->next;
	// 			delete (curr);
	// 			curr = next;
	// 		}
	// 		curr = next = NULL;
	// 	}
	// }

	int size() {
		return curr_size;
	}

	int getBucketIndexAfterHashing(K key) {
		stringstream ss;
		ss << key;
		string s = ss.str();
		int len = s.length();
		long long int prime = 97;
		int hashCode = 0;
		int curr_coefficient = 1;
		for(int i=len-1; i>=0; i--) {
			hashCode = (hashCode + (curr_coefficient * s[i])%bucketCount)%bucketCount;
			curr_coefficient = (prime * curr_coefficient)%bucketCount;
		}
		return (hashCode % bucketCount);
	}

	void insert(K key, V value) {
		int bucketIndex = getBucketIndexAfterHashing(key);
		// cout << "key: " << key << ", " << "bucketIndex: " << bucketIndex<< endl;
		MapNode<K, V>* head = mapNodeArray[bucketIndex];
		bool flag = false;
		while(head != NULL) {
			/* key already present in the map, update it */
			if(head->key == key) {
				head->value = value;
				flag = true;
				return;
			}
			head = head->next;
		}
		/* key not present in the map, insert at the beginning */
		if(flag == false) {
			head = mapNodeArray[bucketIndex];
			MapNode<K, V>* newMapNode = new MapNode<K, V>(key, value);
			newMapNode->next = head;
			head = newMapNode;
			curr_size++;
			mapNodeArray[bucketIndex] = head;
		}

		/* need to implement rehash function if load factor increases */
		float load_factor = (double)(curr_size) / (double)(bucketCount);
		if(load_factor > 0.7) {
			// cout << "rehashing" << endl;
			rehashing();
		}
		return;
	}

	void rehashing() {
		MapNode<K, V>** oldMapNodeArray;
		oldMapNodeArray = mapNodeArray;
		int oldBucketCount = bucketCount;
		bucketCount = 2 * bucketCount;
		mapNodeArray = new MapNode<K, V>* [bucketCount];

		int i = 0;
		while(i < bucketCount) {
			mapNodeArray[i] = NULL;
			i++;
		}
		curr_size = 0;

		i=0;
		while(i < oldBucketCount) {
			// cout << "Inside bucket " << i << endl;
			MapNode<K, V>* head = oldMapNodeArray[i];
			if(head == NULL) {
				// do nothing
			} else {
				while(head != NULL) {
					V value = head->value;
					K key = head->key;
					// cout << "key: " << key << ", value: " << value << endl;
					insert(key, value);
					head = head->next;
				}
			}
			i++;
		}

		for(i=0; i<oldBucketCount; i++) {
			MapNode<K, V>* temp = oldMapNodeArray[i];
			delete (temp);
		}
		delete[] oldMapNodeArray;
	}

	void erase(K key) {
		int bucketIndex = getBucketIndexAfterHashing(key);
		MapNode<K, V>* head = mapNodeArray[bucketIndex];
		if(head == NULL) {
			return ;
		} else {
			MapNode<K, V>* prev = NULL;
			while(head != NULL) {
				if(head->key == key) {
					if(prev != NULL) {
						prev->next = head->next;
					} else {
						prev = head;
						mapNodeArray[bucketIndex] = prev->next;
					}
					head->next = NULL;
					curr_size--;
					delete (head);
				}
				prev = head;
				head = head->next;
			}
		}
	}

	bool find(K key) {
		int bucketIndex = getBucketIndexAfterHashing(key);
		MapNode<K, V>* head = mapNodeArray[bucketIndex];
		if(head == NULL) {
			return false;
		} else {
			while(head != NULL) {
				if(head->key == key) {
					return true;
				}
				head = head->next;
			}
			return false;
		}
	}

	V operator[] (K key) {
		int bucketIndex = getBucketIndexAfterHashing(key);
		MapNode<K, V>* head = mapNodeArray[bucketIndex];
		if(head == NULL) {
			insert(key, V());
			return V();
		} else {
			while(head != NULL) {
				if(head->key == key) {
					V value = head->value;
					return value;
				}
				head = head->next;
			}
			insert(key, V());
			// return NULL;
			return V();
		}
	}
};

int* count_no_of_distinct_elements_in_every_subarray_of_size_k() {
	int n, k;
	cout << "Enter number of elements: ";
	cin >> n;
	cout << "Enter the elements" << endl;
	int arr[n] = {0};
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	cout << "Enter the subarray size: ";
	cin >> k;

	int* res = new int[n];

	if(k > n) {
		return res;
	}

	Unordered_map<int, int> map;
	int count_distinct = 0;

	for(int i=0; i<k; i++) {
		if(map.find(arr[i]) == false) {
			count_distinct++;
		}

		// map[arr[i]]++;
		int temp = map[arr[i]];
		temp++;
		map.insert(arr[i], temp);
	}

	// cout << "1: " << map[1] << endl;
	// cout << "2: " << map[2] << endl;
	// cout << "3: " << map[3] << endl;
	// cout << "4: " << map[4] << endl;

	// cout << "Distinct elements in subarray 1: " << count_distinct << endl;
	res[0] = count_distinct;

	int jj = 1;
	for(int i=k; i<n; i++) {
		int remove_element_index = (i-k);
		int adding_element_index = i;

		// map[arr[remove_element_index]] -= 1;
		int temp = map[arr[remove_element_index]];
		temp--;
		map.insert(arr[remove_element_index], temp);
		if(map[arr[remove_element_index]] == 0) {
			count_distinct--;
		} 

		// map[arr[adding_element_index]] += 1;
		temp = map[arr[adding_element_index]];
		temp++;
		map.insert(arr[adding_element_index], temp);
		if(map[arr[adding_element_index]] == 1) {
			count_distinct++;
		} 

		// cout << "1: " << map[1] << endl;
		// cout << "2: " << map[2] << endl;
		// cout << "3: " << map[3] << endl;
		// cout << "4: " << map[4] << endl;

		res[jj] = count_distinct;
		// cout << "Distinct elements in subarray " << (jj+1) << ": " << count_distinct << endl;
		jj++;
		
	}
	res_arr_size = jj;
	return res;
}

int main() {

	// string str;
	// cout << "Enter data structure for the key: ";
	// cin >> str;
	
	int* res = count_no_of_distinct_elements_in_every_subarray_of_size_k();
	for(int i=0; i<res_arr_size; i++) {
		cout << res[i] << " "; 
	}
	cout << endl;

	// cout << "Unordered Map Implementation" << endl;
	// Unordered_map<string, int> map;
	// map.insert("abc1", 1);
	// map.insert("abc2", 2);
	// map.insert("abc3", 3);
	// map.insert("abc4", 4);
	// map.insert("abc5", 5);
	// map.insert("abc6", 6);
	// map.insert("abc7", 7);
	// map.insert("abc8", 8);

	// cout << "abc2: " << map["abc2"] << endl;
	// cout << "abc5: " << map["abc5"] << endl;

	// cout << "abc10: " << map.find("abc10") << endl;
	// cout << "abc8: " << map.find("abc8") << endl;

	// cout << "size: " << map.size() << endl;

	// cout << "abc10: " << map["abc10"] << endl;

	// cout << "size: " << map.size() << endl;

	// map.erase("abc10");
	// map.erase("abc8");

	// cout << "size: " << map.size() << endl;

	return 0;
}