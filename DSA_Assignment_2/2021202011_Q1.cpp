#include<iostream>
#include<string>
using namespace std;

template<class T>
class Node {
public:
	T data;
	Node *left;
	Node *right;
	// int height;
	int count;

	Node(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
		count = 1;
	}

	// ~Node();
};

template<class T>
class AVLTree {
public:
	Node<T> *root;
	Node<T> *lb;
	Node<T> *ub;

	AVLTree() {
		root = NULL;
		lb = NULL;
		ub = NULL;
	}
	 
	// ~AVLTree();

	T getMax(T x, T y) {
		if(x >= y) {
			return x;
		} else {
			return y;
		}
	}

	int height(Node<T> *temp) {
		if(temp == NULL) {
			return -1;
		} else {
			return (max(height(temp->left), height(temp->right)) + 1);
		}
	}

	Node<T> *rightRotate(Node<T> *root) {
		Node<T> *l = root->left;
		Node<T> *lr = l->right;
		l->right = root;
		root->left = lr;
		return l;
	}	

	Node<T> *leftRotate(Node<T> *root) {
		Node<T> *r = root->right;
		Node<T> *rl = r->left;
		r->left = root;
		root->right = rl;
		return r;
	}	

	Node<T> *getMinValueNode(Node<T> *root) {
		Node<T> *temp = root;
		while(temp->left != NULL) {
			temp = temp->left;
		}
		return temp;
	}

	void inorder(Node<T> *root) {
		if(root == NULL) {
			return;
		} else {
			inorder(root->left);
			cout << root->data << "(" << root->count << ")" << "->";
			inorder(root->right);
		}
	}

	int getBalanceFactor(Node<T>* root) {
	    if (root == NULL) {
	        return -1;
	    } else {
	    	return (height(root->left) - height(root->right));
	    }
	}

	Node<T> *insert(Node<T> *root, T data) {
		Node<T> *newNode = new Node<T>(data);
		if(root == NULL) {
			root = newNode;
			return root;
		} 
		if(root->data == data) {
			root->count = root->count + 1;
			return root;
		}
		if(data > root->data) {
			root->right = insert(root->right, data);
		} else {
			root->left = insert(root->left, data);
		}

		int balance_factor = getBalanceFactor(root);
		/* LL imbalance */
		if(balance_factor > 1 && newNode->data < root->left->data) {
			return (rightRotate(root));
		}
		/* LR imbalance */
		if(balance_factor > 1 && newNode->data > root->left->data) {
			root->left = leftRotate(root->left);
			return (rightRotate(root));
		}
		/* RR imbalance */
		if(balance_factor < -1 && newNode->data > root->right->data) {
			return (leftRotate(root));
		}
		/* RL imbalance */
		if(balance_factor < -1 && newNode->data < root->right->data) {
			root->right = rightRotate(root->right);
			return (leftRotate(root));
		}
		return root;
	}

	Node<T> *search(Node<T> *root, T data) {
		if(root == NULL) {
			return NULL;
		} else {
			if(root->data == data) {
				return root;
			} else if(data > root->data) {
				return search(root->right, data);
			} else {
				return search(root->left, data);
			}
		}
	}

	int count_occurrences_of_element(Node<T> *root, T data) {
		if(root == NULL) {
			return 0;
		} else {
			if(root->data == data) {
				return (root->count);
			} else if (data < root->data) {
				return (count_occurrences_of_element(root->left, data));
			} else {
				return (count_occurrences_of_element(root->right, data));
			}
		}
	}

	Node<T> *deleteNode(Node<T> *root, T data) {
		if(root == NULL) {
			return NULL;
		}
		if(root->data == data) {
			if(root->count >= 2) {
				(root->count)--;
				return root;
			} else {
				if(root->left == NULL && root->right == NULL) {
					delete(root);
					return NULL;
				} else if(root->left == NULL && root->right != NULL) {
					Node<T> *temp = root->right;
					delete(root);
					return temp;
				} else if(root->left != NULL && root->right == NULL) {
					Node<T> *temp = root->left;
					delete(root);
					return temp;
				} else {
					Node<T> *temp = getMinValueNode(root->right);
					root->count = temp->count;
					root->data = temp->data;
					root->right = deleteNode(root->right, temp->data);
				}
			}
		} else if(data > root->data) {
			root->right = deleteNode(root->right, data);
		} else {
			root->left = deleteNode(root->left, data);
		}

		/* if only one node was there before deletion */
		if(root == NULL) {
			return root;
		}

		int balance_factor = getBalanceFactor(root);
		int bf_left = getBalanceFactor(root->left);
		int bf_right = getBalanceFactor(root->right);

		/* LL imbalance */
		if(balance_factor > 1 && bf_left >=0) {
			return (rightRotate(root));
		} 
		/* RR imbalance */
		if(balance_factor < -1 && bf_right <= 0) {
			return (leftRotate(root));
		}
		/* LR imbalance */
		if(balance_factor > 1 && bf_left < 0) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		/* RL imbalance */
		if(balance_factor < -1 && bf_right > 0) {
			root->right = rightRotate(root->right);
			return (leftRotate(root));
		}
		return root;
	}

	Node<T>* lower_bound(Node<T>* root, T data) {
		if(root == NULL) {
			return lb;
		} 
		if(root->data < data) {
			return lower_bound(root->right, data);
		}
		if(root->data >= data) {
			lb = root;
			return lower_bound(root->left, data);
		}
	}

	Node<T>* upper_bound(Node<T>* root, T data) {
		if(root == NULL) {
			return ub;
		} 
		if(root->data <= data) {
			return upper_bound(root->right, data);
		}
		if(root->data > data) {
			ub = root;
			return upper_bound(root->left, data);
		}
	}

	int count_number_of_elements_in_range(Node<T>* root, T low, T high) {
		if(root == NULL) {
			return 0;
		}
		if(root->data == low && root->data == high) {
			return (root->count);
		}
		if(root->data >= low && root->data <= high) {
			int l = count_number_of_elements_in_range(root->left, low, high);
			int r = count_number_of_elements_in_range(root->right, low, high);
			return ((root->count) + l + r);
		}
		if(root->data > high) {
			return count_number_of_elements_in_range(root->left, low, high);
		}
		if(root->data < low) {
			return count_number_of_elements_in_range(root->right, low, high);
		}
	}


	Node<T>* kth_largest_element(Node<T>* root, int k) {
		if(root == NULL) {
			return NULL;
		}
		Node<T> *r = kth_largest_element(root->right, k);
		if(r != NULL) {
			return r;
		}
		
		k = k - (root->count);
		if(k <= 0) {
			return root;
		}
		return kth_largest_element(root->left, k);
	}  

	T absoluteValue(T num) {
		return (num > 0)? num : -num;
		// return (num > T())? num : -num;
	}

	Node<T>* closest_element(Node<T>* root, T data) {
		if(root == NULL) {
			return NULL;
		}
		Node<T>* closestNode = root;
		T min_diff = abs(root->data - data);
		// cout << min_diff << endl;
		while(root != NULL) {
			T curr_diff = absoluteValue(root->data - data);
			if(curr_diff < min_diff) {
				min_diff = curr_diff;
				closestNode = root;
			}
			if(data == root->data) {
				break;
			} else if(data > root->data) {
				root = root->right;
			} else {
				root = root->left;
			}
		}
		return closestNode;
	}
}; 

int main() {
	cout << "<<<<<<<<<<<<<<<<<<<<<<< AVL TREE >>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	AVLTree<int>* obj = new AVLTree<int>();
	// obj->root = obj->insert(obj->root, 1);
	// obj->root = obj->insert(obj->root, 2);
	// obj->print2D(obj->root, 5);

	while(true) {
		int operation, n1, n2;
		Node<int>* temp;
		cout << endl << "||||||||||||||||||||||||||| START |||||||||||||||||||||||" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Delete" << endl;
		cout << "3. Search" << endl;
		cout << "4. Count occurrence of an element" << endl;
		cout << "5. Lower bound of an element" << endl;
		cout << "6. Upper bound of an element" << endl;
		cout << "7. Closest Element to some value" << endl;
		cout << "8. Kth largest element" << endl;
		cout << "9. Count number of elements in a range" << endl;
		cout << "10. Inorder Traversal" << endl;
		cout << "11. EXIT" << endl;
		cout << "|||||||||||||||||| Choose option[1-10] |||||||||||||||||| => ";
		cin >> operation;
		switch(operation) {
			case 1:
			cout << "Enter Value: "; 
			cin >> n1;
			obj->root = obj->insert(obj->root, n1);
			break;

			case 2:
			cout << "Enter Value: "; 
			cin >> n1;
			temp = obj->search(obj->root, n1);
	        if (temp != NULL) {
	        	obj->root = obj->deleteNode(obj->root, n1);
	        	cout << n1 << " Deleted" << endl;
	        } else {
	       		cout << "Value NOT found" << endl;
	        }
			break;

			case 3:
			cout << "Enter Value: "; 
			cin >> n1;
			temp = obj->search(obj->root, n1);
	        if (temp != NULL) {
	        	cout << "Found!!" << endl;
	        } else {
	       		cout << "Value NOT found" << endl;
	        }
			break;

			case 4:
			cout << "Enter Value: "; 
			cin >> n1;
			cout << obj->count_occurrences_of_element(obj->root, n1) << endl;
			break;

			case 5:
			cout << "Enter value: ";
			cin >> n1;
			temp = obj->lower_bound(obj->root, n1);
			if(temp == NULL) {
				cout << "Lower bound does not exist" << endl;
			} else {
				cout << "Lower bound = " << temp->data << endl;
			}
			break;

			case 6:
			cout << "Enter value: ";
			cin >> n1;
			temp = obj->upper_bound(obj->root, n1);
			if(temp == NULL) {
				cout << "Upper bound does not exist" << endl;
			} else {
				cout << "Upper bound = " << temp->data << endl;
			}
			break;

			case 7:
			cout << "Enter value: ";
			cin >> n1; 
			temp = obj->closest_element(obj->root, n1);
			if(temp == NULL) {
				cout << "Closest does not exist" << endl;
			} else {
				cout << "Closest Element = " << temp->data << endl;
			}
			break;

			case 8:
			cout << "Enter value: ";
			cin >> n1; 
			temp = obj->kth_largest_element(obj->root, n1);
			if(temp == NULL) {
				cout << "Kth Largest element does not exist" << endl;
			} else {
				cout << "Kth largest Element = " << temp->data << endl;
			}
			break;

			case 9:
			cout << "Enter lower bound: ";
			cin >> n1;
			cout << "Enter upper bound: ";
			cin >> n2;
			cout << obj->count_number_of_elements_in_range(obj->root, n1, n2) << endl;
			break;

			case 10:
			obj->inorder(obj->root);
			break;

			case 11:
			exit(0);
			break;
			default:
			cout << "Please choose correct option!![1-10]" << endl;
			break;
		}
	}

	return 0;
}