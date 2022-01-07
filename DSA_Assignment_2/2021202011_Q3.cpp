/*
● deque() - initialize a blank deque. -O(1)
● deque(n,x) - initialize a deque of length n with all values as x. -O(n)
● push_back(x) - append data x at the end. -O(1)
● pop_back() - erase data at the end. -O(1)
● push_front(x) - append data x at the beginning. O(1)
● pop_front() - erase data at the beginning. O(1)
● front() - returns the first element(value) in the deque. O(1)
● back() - returns the last element(value) in the deque. O(1)
● empty() - returns true if deque is empty else returns false. O(1)
● size() - returns the current size of deque. O(1)
● resize(x, d) - changes the size dynamically. If the new size is greater
than the current size of the deque, then fill the empty space with the
default value d. O(n)
● clear() - remove all elements of deque.O(1)
● D[n] - returns the nth element of the deque. O(1)
*/

#include<iostream>
#include<string>
using namespace std;

template <class T>
struct Node
{
	T data;
	struct Node *prev;
	struct Node *next;
	Node()
	{
		data = T();
		prev = NULL;
		next = NULL;
	}
	Node(T value)
	{
		data = value;
		prev = NULL;
		next = NULL;
	}
};

template <class T>
class Deque 
{
public:
	int curr_size;
	bool flag;
	Node<T> *front;
	Node<T> *rear;
	/* initialize a blank deque. -O(1) */
	Deque()
	{
		curr_size = 0;
		front = NULL;
		rear = NULL;
		flag = false;
	}
	/* initialize a deque of length n with all values as x. -O(n) */
	Deque(int n, T x)
	{
		/* calling the empty arguement constructor to make size=0 and front, rear pointers ready */
		curr_size = 0;
		front = NULL;
		rear = NULL;
		for(int i=0; i<n; i++)
		{
			push_back(x);
		}
	}
public:
	/* append data x at the end. -O(1) */
	void push_back(T x)
	{
		Node<T> *newNode = new Node<T>(x);
		// if(rear == NULL)
		if(curr_size == 0)
		{
			rear = newNode;
			front = newNode;
		}
		else
		{
			newNode->prev = rear;
			rear->next = newNode;
			rear = newNode;
		}
		curr_size++;
	}

	/* erase data at the end. -O(1) */
	void pop_back()
	{
		// if(front == NULL)
		if(curr_size == 0)
		{
			cout << "DeQueue is Empty!! Can't pop_back()" << endl;
		}
		else
		{
			// T value = rear->data;
			Node<T> *temp = rear;
			rear = rear->prev;
			/* only 1 node was present, so after deletion the dequeue is empty now, so reset front and rear */
			if(rear == NULL)
			{
				front = NULL;
			}
			else
			{
				rear->next = NULL;
			}
			delete(temp);
			temp = NULL;
			curr_size--;
			// return value;
		}
	}

	/* append data x at the beginning. O(1) */
	void push_front(T x)
	{
		Node<T> *newNode = new Node<T>(x);
		if(curr_size == 0)
		{
			rear = newNode;
			front = newNode;
		}
		else
		{
			newNode->next = front;
			front->prev = newNode;
			front = newNode;
		}
		curr_size++;
	}

	/* erase data at the beginning. O(1) */
	void pop_front()
	{
		if(curr_size == 0)
		{
			cout << "DeQueue is Empty!! Can't pop_back()" << endl;
		}
		else
		{
			Node<T> *temp = front;
			front = front->next;
			/* Only one node was present. So, after deletion reset the front and rear */
			if(front == NULL)
			{
				rear = NULL;
			}
			else
			{
				front->prev = NULL;
			}
			delete(temp);
			temp = NULL;
			curr_size--;
		}
	}

	/* returns the first element(value) in the deque. O(1) */
	T getFront()
	{
		if(curr_size == 0)
		{
			cout << "Queue is Empty!!" << endl;
			flag = false;
			return T();
		}
		else
		{
			flag = true;
			cout << "First element of the Deque is: ";
			return front->data;
		}
	}

	/* returns the last element(value) in the deque. O(1) */
	T getBack()
	{
		if(curr_size == 0)
		{
			cout << "Queue is Empty!!" << endl;
			flag = false;
			return T();
		}
		else
		{
			flag = true;
			cout << "Last element of the Deque is: ";
			return rear->data;
		}
	} 

	/* returns true if deque is empty else returns false. O(1) */
	bool isEmpty() 
	{
		if(curr_size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/* returns the current size of deque. O(1) */
	int size()
	{
		return curr_size;
	}

	/* changes the size dynamically. If the new size is greater
	than the current size of the deque, then fill the empty space with the
	default value d. O(n) */
	/* if x<size then I'm deleting the extra nodes from behind */
	/* else adding extra nodes in back and filling them with d */
	void resize(int x, T d)
	{
		if(x==curr_size)
		{
			// do nothing
		}
		else if(x < curr_size)
		{
			// delete (size-x) nodes from back
			int temp = (curr_size - x);
			for(int i=0; i<temp; i++)
			{
				pop_back();
			}
		}
		else
		{
			// add (x-size) nodes from back
			int temp = (x - curr_size);
			for(int i=0; i<temp; i++)
			{
				push_back(d);
			}
		}
	}

	/* remove all elements of deque.O(1) */
	void clear()
	{
		while(front != NULL)
		{
			Node<T> *temp = front;
			front = front->next;
			delete(temp);
			temp = NULL;
		}
		rear = NULL;
		curr_size = 0;
	}

	/* D[n] - returns the nth element of the deque. O(1) */
	T operator[](int n)
	{
		if(curr_size == 0)
		{
			flag = false;
			cout << "Queue is Empty!!" << endl;
			return T();
		}
		else if(n >= curr_size || n < 0)
		{
			flag = false;
			cout << "Index out of bounds!!" << endl;
			return T();
		}
		else
		{
			T res;
			Node<T> *temp = front;
			for(int i=0; i<n; i++)
			{
				temp = temp->next;
			}
			res = temp->data;
			flag = true;
			return res;
			// cout << "Value at " << n << "th index" << temp->data << endl;
		}
	}

	/* print dequeue */
	void print_dequeue()
	{
		if(curr_size == 0)
		{
			cout << "Dequeue is empty!!" << endl;
		}
		else
		{
			cout << "The elements of the Dequeue are: ";
			Node<T> *temp = front;
			while(temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

};

int main()
{
	Deque<int> *dq;
	dq = new Deque<int>();

	while(true)
	{
		int operation, size, value, res;
		bool ans;
		cout << endl << "||||||||||||||||||||||||||| START |||||||||||||||||||||||" << endl;
		cout << "1. Initialize a blank deque " << endl;
		cout << "2. Initialize a deque of length n with all values as x " << endl;
		cout << "3. Append data x at the end " << endl;
		cout << "4. Erase data at the end " << endl;
		cout << "5. Append data x at the beginning " << endl;
		cout << "6. Erase data at the beginning " << endl;
		cout << "7. Return the first element(value) in the deque " << endl;
		cout << "8. Return the last element(value) in the deque " << endl;
		cout << "9. isEmpty " << endl;
		cout << "10. Current size of deque" << endl;
		cout << "11. Resize the dequeue " << endl;
		cout << "12. Clear the dequeue" << endl;
		cout << "13. Return nth element of the dequeue " << endl;
		cout << "14. Print the elements of the dequeue " << endl;
		cout << "15. Exit" << endl;
		cout << "|||||||||||||||||| Choose option[1-14] |||||||||||||||||| => ";
		cin >> operation;
		switch(operation) 
		{
			case 1:
				dq = new Deque<int>();
				dq->print_dequeue();
				break;
			case 2:
				cout << "Enter length of the Dequeue: ";
				cin >> size;
				cout << "Enter a uniform value x: ";
				cin >> value;
				dq = new Deque<int>(size, value);
				dq->print_dequeue();
				break;
			case 3:
				cout << "Enter the value: ";
				cin >> value;
				dq->push_back(value);
				dq->print_dequeue();
				break;
			case 4:
				dq->pop_back();
				dq->print_dequeue();
				break;
			case 5:
				cout << "Enter the value: ";
				cin >> value;
				dq->push_front(value);
				dq->print_dequeue();
				break;
			case 6:
				dq->pop_front();
				dq->print_dequeue();
				break;
			case 7:
				res = dq->getFront();
				if(dq->flag != false)
				{
					cout << res << endl;
				}
				break;
			case 8:
				res = dq->getBack();
				if(dq->flag != false)
				{
					cout << res << endl;
				}
				break;
			case 9:
				ans = dq->isEmpty();
				if(ans == true)
				{
					cout << "Dequeue is empty!!" << endl;
				}
				else
				{
					cout << "Dequeue is filled!!" << endl;
				}
				break;
			case 10:
				cout << "Size: " << dq->size() << endl;
				break;
			case 11:
				cout << "Enter length: ";
				cin >> size;
				cout << "Enter a uniform value: ";
				cin >> value;
				dq->resize(size, value);
				dq->print_dequeue();
				break;
			case 12:
				dq->clear();
				dq->print_dequeue();
				break;
			case 13:
				int index; 
				cout << "Enter index: ";
				cin >> index;
				res = (*dq)[index];
				if(dq->flag != false)
				{
					cout << "Value at " << index << "th index = "  << res << endl;
				}
				break;
			case 14:
				dq->print_dequeue();
				break;
			case 15:
				exit(0);
				break;
			default:
				cout << "Please choose correct option!![1-14]" << endl;
				break;

		}
	}

	// Deque<string> *dq;
	// dq = new Deque<string>();

	// dq->getFront();


	return 0;
}
