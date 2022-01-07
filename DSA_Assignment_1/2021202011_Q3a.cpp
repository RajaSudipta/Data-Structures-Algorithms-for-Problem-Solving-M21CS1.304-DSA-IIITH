#include<iostream>
using namespace std;

int m1_int[10000][10000];
int m2_int[10000][10000];
int m3_int[10000][10000];

float m1_float[2000][2000];
float m2_float[2000][2000];
float m3_float[2000][2000];

double m1_double[2000][2000];
double m2_double[2000][2000];
double m3_double[2000][2000];

struct Node
{
	int row;
	int col;
	int val;
	struct Node *next;
	Node()
	{
		row=-1;
		col=-1;
		val=-1;
		next=NULL;
	}
};

struct NodeFloat
{
	int row;
	int col;
	float val;
	struct NodeFloat *next;
	NodeFloat()
	{
		row=-1;
		col=-1;
		val=-1;
		next=NULL;
	}
};

struct NodeDouble
{
	int row;
	int col;
	double val;
	struct NodeDouble *next;
	NodeDouble()
	{
		row=-1;
		col=-1;
		val=-1;
		next=NULL;
	}
};

void print_zero_matrix(int rows, int cols)
{
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			cout << 0 << " ";
		}
		cout << endl;
	}
}

void print_matrix(string str, int rows, int cols)
{
	if(str == "m1_int")
	{
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				cout << m1_int[i][j] << " ";
			}
			cout << endl;
		}
	}

	else if(str == "m2_int")
	{
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				cout << m2_int[i][j] << " ";
			}
			cout << endl;
		}
	}
	else if(str == "m3_int")
	{
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				cout << m3_int[i][j] << " ";
			}
			cout << endl;
		}
	}
	else if(str == "m1_float")
	{
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				cout << m1_float[i][j] << " ";
			}
			cout << endl;
		}
	}

	else if(str == "m2_float")
	{
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				cout << m2_float[i][j] << " ";
			}
			cout << endl;
		}
	}
	else if(str == "m3_float")
	{
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				cout << m3_float[i][j] << " ";
			}
			cout << endl;
		}
	}
	if(str == "m1_double")
	{
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				cout << m1_double[i][j] << " ";
			}
			cout << endl;
		}
	}

	else if(str == "m2_double")
	{
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				cout << m2_double[i][j] << " ";
			}
			cout << endl;
		}
	}
	else if(str == "m3_double")
	{
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				cout << m3_double[i][j] << " ";
			}
			cout << endl;
		}
	}
}

struct Node *convert_to_LL_int(string str, int rows, int cols)
{
	if(str=="m1_int")
	{
		struct Node *head = NULL;
		struct Node *temp = head;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m1_int[i][j] != 0)
				{
					struct Node *newNode = new Node();
					newNode->row = i;
					newNode->col = j;
					newNode->val = m1_int[i][j];

					if(head==NULL)
					{
						head = newNode;
						temp = head;
					}
					else
					{
						temp->next = newNode;
						temp = newNode;
					}
				}
			}
		}
		return head;
	}
	else if(str=="m2_int")
	{
		struct Node *head = NULL;
		struct Node *temp = head;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m2_int[i][j] != 0)
				{
					struct Node *newNode = new Node();
					newNode->row = i;
					newNode->col = j;
					newNode->val = m2_int[i][j];

					if(head==NULL)
					{
						head = newNode;
						temp = head;
					}
					else
					{
						temp->next = newNode;
						temp = newNode;
					}
				}
			}
		}
		return head;
	}
	else if(str=="m3_int")
	{
		struct Node *head = NULL;
		struct Node *temp = head;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m3_int[i][j] != 0)
				{
					struct Node *newNode = new Node();
					newNode->row = i;
					newNode->col = j;
					newNode->val = m3_int[i][j];

					if(head==NULL)
					{
						head = newNode;
						temp = head;
					}
					else
					{
						temp->next = newNode;
						temp = newNode;
					}
				}
			}
		}
		return head;
	}
	return NULL;
}

struct NodeFloat *convert_to_LL_float(string str, int rows, int cols)
{
	if(str=="m1_float")
	{
		struct NodeFloat *head = NULL;
		struct NodeFloat *temp = head;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m1_float[i][j] != 0)
				{
					struct NodeFloat *newNode = new NodeFloat();
					newNode->row = i;
					newNode->col = j;
					newNode->val = m1_float[i][j];

					if(head==NULL)
					{
						head = newNode;
						temp = head;
					}
					else
					{
						temp->next = newNode;
						temp = newNode;
					}
				}
			}
		}
		return head;
	}
	else if(str=="m2_float")
	{
		struct NodeFloat *head = NULL;
		struct NodeFloat *temp = head;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m2_float[i][j] != 0)
				{
					struct NodeFloat *newNode = new NodeFloat();
					newNode->row = i;
					newNode->col = j;
					newNode->val = m2_float[i][j];

					if(head==NULL)
					{
						head = newNode;
						temp = head;
					}
					else
					{
						temp->next = newNode;
						temp = newNode;
					}
				}
			}
		}
		return head;
	}
	else if(str=="m3_float")
	{
		struct NodeFloat *head = NULL;
		struct NodeFloat *temp = head;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m3_float[i][j] != 0)
				{
					struct NodeFloat *newNode = new NodeFloat();
					newNode->row = i;
					newNode->col = j;
					newNode->val = m3_float[i][j];

					if(head==NULL)
					{
						head = newNode;
						temp = head;
					}
					else
					{
						temp->next = newNode;
						temp = newNode;
					}
				}
			}
		}
		return head;
	}
	return NULL;
}

struct NodeDouble *convert_to_LL_double(string str, int rows, int cols)
{
	if(str=="m1_double")
	{
		struct NodeDouble *head = NULL;
		struct NodeDouble *temp = head;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m1_double[i][j] != 0)
				{
					struct NodeDouble *newNode = new NodeDouble();
					newNode->row = i;
					newNode->col = j;
					newNode->val = m1_double[i][j];

					if(head==NULL)
					{
						head = newNode;
						temp = head;
					}
					else
					{
						temp->next = newNode;
						temp = newNode;
					}
				}
			}
		}
		return head;
	}
	else if(str=="m2_double")
	{
		struct NodeDouble *head = NULL;
		struct NodeDouble *temp = head;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m2_double[i][j] != 0)
				{
					struct NodeDouble *newNode = new NodeDouble();
					newNode->row = i;
					newNode->col = j;
					newNode->val = m2_double[i][j];

					if(head==NULL)
					{
						head = newNode;
						temp = head;
					}
					else
					{
						temp->next = newNode;
						temp = newNode;
					}
				}
			}
		}
		return head;
	}
	else if(str=="m3_double")
	{
		struct NodeDouble *head = NULL;
		struct NodeDouble *temp = head;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m3_double[i][j] != 0)
				{
					struct NodeDouble *newNode = new NodeDouble();
					newNode->row = i;
					newNode->col = j;
					newNode->val = m3_double[i][j];

					if(head==NULL)
					{
						head = newNode;
						temp = head;
					}
					else
					{
						temp->next = newNode;
						temp = newNode;
					}
				}
			}
		}
		return head;
	}
	return NULL;
}

void transpose_LL_int(int rows, int cols)
{
	int n1=0;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(m1_int[i][j] != 0)
			{
				n1++;
			}
		}
	}
	if(n1 == 0)
	{
		print_zero_matrix(cols, rows);
	}
	else
	{
		struct Node *head = convert_to_LL_int("m1_int", rows, cols);
		struct Node *temp = head;
		while(temp != NULL)
		{
			int t = temp->row;
			temp->row = temp->col;
			temp->col = t;
			temp = temp->next;
		}
		cout << endl << "Result in sparse Matrix is: " << endl;
		temp = head;
		while(temp!=NULL)
		{
			cout << "row: " << temp->row << " col: " << temp->col << " val: " << temp->val << endl; 
			m3_int[temp->row][temp->col] = temp->val;
			temp = temp->next; 
		}
		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_int", cols, rows);
	}
}

void transpose_LL_float(int rows, int cols)
{
	int n1=0;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(m1_float[i][j] != float(0))
			{
				n1++;
			}
		}
	}
	if(n1 == 0)
	{
		print_zero_matrix(cols, rows);
	}
	else
	{
		struct NodeFloat *head = convert_to_LL_float("m1_float", rows, cols);
		struct NodeFloat *temp = head;
		while(temp != NULL)
		{
			int t = temp->row;
			temp->row = temp->col;
			temp->col = t;
			temp = temp->next;
		}
		cout << endl << "Result in sparse Matrix is: " << endl;
		temp = head;
		while(temp!=NULL)
		{
			cout << "row: " << temp->row << " col: " << temp->col << " val: " << temp->val << endl; 
			m3_float[temp->row][temp->col] = temp->val;
			temp = temp->next; 
		}
		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_float", cols, rows);
	}
}

void transpose_LL_double(int rows, int cols)
{
	int n1=0;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(m1_double[i][j] != double(0))
			{
				n1++;
			}
		}
	}
	if(n1 == 0)
	{
		print_zero_matrix(cols, rows);
	}
	else
	{
		struct NodeDouble *head = convert_to_LL_double("m1_double", rows, cols);
		struct NodeDouble *temp = head;
		while(temp != NULL)
		{
			int t = temp->row;
			temp->row = temp->col;
			temp->col = t;
			temp = temp->next;
		}
		cout << endl << "Result in sparse Matrix is: " << endl;
		temp = head;
		while(temp!=NULL)
		{
			cout << "row: " << temp->row << " col: " << temp->col << " val: " << temp->val << endl; 
			m3_double[temp->row][temp->col] = temp->val;
			temp = temp->next; 
		}
		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_double", cols, rows);
	}
}


void addition_LL_int(int rows, int cols)
{
	int n1=0, n2=0;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(m1_int[i][j] != 0)
			{
				n1++;
			}
		}
	}

	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(m2_int[i][j] != 0)
			{
				n2++;
			}
		}
	}

	if(n1==0 && n2==0)
	{
		print_zero_matrix(rows, cols);
	}
	else if(n1 == 0)
	{
		print_matrix("m2_int", rows, cols);
	}
	else if(n2 == 0)
	{
		print_matrix("m1_int", rows, cols);
	}
	else
	{
		struct Node *head1 = convert_to_LL_int("m1_int", rows, cols);
		struct Node *head2 = convert_to_LL_int("m2_int", rows, cols);

		struct Node *head3 = NULL;

		struct Node *temp1 = head1;
		struct Node *temp2 = head2;
		struct Node *temp3 = head3;

		/* traverse the first LL */
		while(temp1 != NULL)
		{
			temp2 = head2;
			bool flag = false;
			int sum=0;
			struct Node *newNode = new Node();
			while(temp2 != NULL)
			{
				if(temp1->row == temp2->row && temp1->col == temp2->col)
				{
					sum = temp1->val + temp2->val;
					newNode->row = temp1->row;
					newNode->col = temp1->col;
					newNode->val = sum;
					flag = true;
					break;
				}
				temp2 = temp2->next;
			}
			if(flag == true)
			{
				if(head3 == NULL)
				{
					head3 = newNode;
					temp3 = head3;
				}
				else
				{
					temp3->next = newNode;
					temp3 = newNode;
				}
			}
			else
			{
				newNode->row = temp1->row;
				newNode->col = temp1->col;
				newNode->val = temp1->val;
				if(head3 == NULL)
				{
					head3 = newNode;
					temp3 = head3;
				}
				else
				{
					temp3->next = newNode;
					temp3 = newNode;
				}
			}
			temp1 = temp1->next;
		}

		/* traverse the second LL */
		temp1 = head1;
		temp2 = head2;
		while(temp2 != NULL)
		{
			temp1 = head1;
			bool flag = false;
			struct Node *newNode = new Node();
			while(temp1 != NULL)
			{
				/* already calculated while prev iteration */
				if(temp2->row == temp1->row && temp2->col == temp1->col)
				{
					flag = true;
					break;
				}
				temp1 = temp1->next;
			}
			if(flag == false)
			{
				newNode->row = temp2->row;
				newNode->col = temp2->col;
				newNode->val = temp2->val;
				if(head3 == NULL)
				{
					head3 = newNode;
					temp3 = head3;
				}
				else
				{
					temp3->next = newNode;
					temp3 = newNode;
				}
			}
			temp2 = temp2->next;
		}
		cout << endl << "Result in sparse Matrix is: " << endl;
		temp3 = head3;
		while(temp3 != NULL)
		{
			cout << "row: " << temp3->row << " col: " << temp3->col << " val: " << temp3->val << endl;
			m3_int[temp3->row][temp3->col] = temp3->val;
			temp3 = temp3->next;
		}
		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_int", rows, cols);

	}
}

void addition_LL_float(int rows, int cols)
{
	int n1=0, n2=0;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(m1_float[i][j] != 0)
			{
				n1++;
			}
		}
	}

	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(m2_float[i][j] != 0)
			{
				n2++;
			}
		}
	}

	if(n1==0 && n2==0)
	{
		print_zero_matrix(rows, cols);
	}
	else if(n1 == 0)
	{
		print_matrix("m2_float", rows, cols);
	}
	else if(n2 == 0)
	{
		print_matrix("m1_float", rows, cols);
	}
	else
	{
		struct NodeFloat *head1 = convert_to_LL_float("m1_float", rows, cols);
		struct NodeFloat *head2 = convert_to_LL_float("m2_float", rows, cols);

		struct NodeFloat *head3 = NULL;

		struct NodeFloat *temp1 = head1;
		struct NodeFloat *temp2 = head2;
		struct NodeFloat *temp3 = head3;

		/* traverse the first LL */
		while(temp1 != NULL)
		{
			temp2 = head2;
			bool flag = false;
			float sum=0;
			struct NodeFloat *newNode = new NodeFloat();
			while(temp2 != NULL)
			{
				if(temp1->row == temp2->row && temp1->col == temp2->col)
				{
					sum = temp1->val + temp2->val;
					newNode->row = temp1->row;
					newNode->col = temp1->col;
					newNode->val = sum;
					flag = true;
					break;
				}
				temp2 = temp2->next;
			}
			if(flag == true)
			{
				if(head3 == NULL)
				{
					head3 = newNode;
					temp3 = head3;
				}
				else
				{
					temp3->next = newNode;
					temp3 = newNode;
				}
			}
			else
			{
				newNode->row = temp1->row;
				newNode->col = temp1->col;
				newNode->val = temp1->val;
				if(head3 == NULL)
				{
					head3 = newNode;
					temp3 = head3;
				}
				else
				{
					temp3->next = newNode;
					temp3 = newNode;
				}
			}
			temp1 = temp1->next;
		}

		/* traverse the second LL */
		temp1 = head1;
		temp2 = head2;
		while(temp2 != NULL)
		{
			temp1 = head1;
			bool flag = false;
			struct NodeFloat *newNode = new NodeFloat();
			while(temp1 != NULL)
			{
				/* already calculated while prev iteration */
				if(temp2->row == temp1->row && temp2->col == temp1->col)
				{
					flag = true;
					break;
				}
				temp1 = temp1->next;
			}
			if(flag == false)
			{
				newNode->row = temp2->row;
				newNode->col = temp2->col;
				newNode->val = temp2->val;
				if(head3 == NULL)
				{
					head3 = newNode;
					temp3 = head3;
				}
				else
				{
					temp3->next = newNode;
					temp3 = newNode;
				}
			}
			temp2 = temp2->next;
		}

		cout << endl << "Result in sparse Matrix is: " << endl;
		temp3 = head3;
		while(temp3 != NULL)
		{
			cout << "row: " << temp3->row << " col: " << temp3->col << " val: " << temp3->val << endl;
			m3_float[temp3->row][temp3->col] = temp3->val;
			temp3 = temp3->next;
		}
		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_float", rows, cols);

	}
}

void addition_LL_double(int rows, int cols)
{
	int n1=0, n2=0;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(m1_double[i][j] != 0)
			{
				n1++;
			}
		}
	}

	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(m2_double[i][j] != 0)
			{
				n2++;
			}
		}
	}

	if(n1==0 && n2==0)
	{
		print_zero_matrix(rows, cols);
	}
	else if(n1 == 0)
	{
		print_matrix("m2_double", rows, cols);
	}
	else if(n2 == 0)
	{
		print_matrix("m1_double", rows, cols);
	}
	else
	{
		struct NodeDouble *head1 = convert_to_LL_double("m1_double", rows, cols);
		struct NodeDouble *head2 = convert_to_LL_double("m2_double", rows, cols);

		struct NodeDouble *head3 = NULL;

		struct NodeDouble *temp1 = head1;
		struct NodeDouble *temp2 = head2;
		struct NodeDouble *temp3 = head3;

		/* traverse the first LL */
		while(temp1 != NULL)
		{
			temp2 = head2;
			bool flag = false;
			double sum=0;
			struct NodeDouble *newNode = new NodeDouble();
			while(temp2 != NULL)
			{
				if(temp1->row == temp2->row && temp1->col == temp2->col)
				{
					sum = temp1->val + temp2->val;
					newNode->row = temp1->row;
					newNode->col = temp1->col;
					newNode->val = sum;
					flag = true;
					break;
				}
				temp2 = temp2->next;
			}
			if(flag == true)
			{
				if(head3 == NULL)
				{
					head3 = newNode;
					temp3 = head3;
				}
				else
				{
					temp3->next = newNode;
					temp3 = newNode;
				}
			}
			else
			{
				newNode->row = temp1->row;
				newNode->col = temp1->col;
				newNode->val = temp1->val;
				if(head3 == NULL)
				{
					head3 = newNode;
					temp3 = head3;
				}
				else
				{
					temp3->next = newNode;
					temp3 = newNode;
				}
			}
			temp1 = temp1->next;
		}

		/* traverse the second LL */
		temp1 = head1;
		temp2 = head2;
		while(temp2 != NULL)
		{
			temp1 = head1;
			bool flag = false;
			struct NodeDouble *newNode = new NodeDouble();
			while(temp1 != NULL)
			{
				/* already calculated while prev iteration */
				if(temp2->row == temp1->row && temp2->col == temp1->col)
				{
					flag = true;
					break;
				}
				temp1 = temp1->next;
			}
			if(flag == false)
			{
				newNode->row = temp2->row;
				newNode->col = temp2->col;
				newNode->val = temp2->val;
				if(head3 == NULL)
				{
					head3 = newNode;
					temp3 = head3;
				}
				else
				{
					temp3->next = newNode;
					temp3 = newNode;
				}
			}
			temp2 = temp2->next;
		}

		cout << endl << "Result in sparse Matrix is: " << endl;
		temp3 = head3;
		while(temp3 != NULL)
		{
			cout << "row: " << temp3->row << " col: " << temp3->col << " val: " << temp3->val << endl;
			m3_double[temp3->row][temp3->col] = temp3->val;
			temp3 = temp3->next;
		}
		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_double", rows, cols);

	}
}

void multiplication_LL_int(int row1, int col1, int row2, int col2)
{
	int n1=0, n2=0;
	for(int i=0; i<row1; i++)
	{
		for(int j=0; j<col1; j++)
		{
			if(m1_int[i][j] != 0)
			{
				n1++;
			}
		}
	}

	for(int i=0; i<row2; i++)
	{
		for(int j=0; j<col2; j++)
		{
			if(m2_int[i][j] != 0)
			{
				n2++;
			}
		}
	}

	if(n1==0 || n2==0)
	{
		print_zero_matrix(row1, col2);
	}
	else
	{
		struct Node *head1 = convert_to_LL_int("m1_int", row1, col1);
		struct Node *head2 = convert_to_LL_int("m2_int", row2, col2);

		struct Node *head3 = NULL;

		struct Node *temp1 = head1;
		struct Node *temp2 = head2;
		struct Node *temp3 = head3;

		while(temp1 != NULL)
		{
			temp2 = head2;
			while(temp2 != NULL)
			{
				struct Node *newNode = new Node();
				/* multiplication posssible */
				if(temp1->col == temp2->row)
				{
					int product = temp1->val * temp2->val;					
					bool flag = false;
					struct Node *tt = head3;
					while(tt != NULL)
					{
						if(tt->row == temp1->row && tt->col == temp2->col)
						{
							tt->val = tt->val + product;
							flag = true;
							break;
						}
						tt = tt->next;
					}
					if(flag == false)
					{
						newNode->row = temp1->row;
						newNode->col = temp2->col;
						newNode->val = product;
						if(head3 == NULL)
						{
							head3 = newNode;
							temp3 = head3;
						}
						else
						{
							temp3->next = newNode;
							temp3 = newNode;
						}
					}
				}
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}

		cout << endl << "Result in sparse Matrix is: " << endl;
		temp3 = head3;
		while(temp3 != NULL)
		{
			cout << "row: " << temp3->row << " col: " << temp3->col << " val: " << temp3->val << endl;
			m3_int[temp3->row][temp3->col] = temp3->val;
			temp3 = temp3->next; 
		}
		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_int", row1, col2);
	}
}

void multiplication_LL_float(int row1, int col1, int row2, int col2)
{
	int n1=0, n2=0;
	for(int i=0; i<row1; i++)
	{
		for(int j=0; j<col1; j++)
		{
			if(m1_float[i][j] != 0)
			{
				n1++;
			}
		}
	}

	for(int i=0; i<row2; i++)
	{
		for(int j=0; j<col2; j++)
		{
			if(m2_float[i][j] != 0)
			{
				n2++;
			}
		}
	}

	if(n1==0 || n2==0)
	{
		print_zero_matrix(row1, col2);
	}
	else
	{
		struct NodeFloat *head1 = convert_to_LL_float("m1_float", row1, col1);
		struct NodeFloat *head2 = convert_to_LL_float("m2_float", row2, col2);

		struct NodeFloat *head3 = NULL;

		struct NodeFloat *temp1 = head1;
		struct NodeFloat *temp2 = head2;
		struct NodeFloat *temp3 = head3;

		while(temp1 != NULL)
		{
			temp2 = head2;
			while(temp2 != NULL)
			{
				struct NodeFloat *newNode = new NodeFloat();
				/* multiplication posssible */
				if(temp1->col == temp2->row)
				{
					float product = temp1->val * temp2->val;					
					bool flag = false;
					struct NodeFloat *tt = head3;
					while(tt != NULL)
					{
						if(tt->row == temp1->row && tt->col == temp2->col)
						{
							tt->val = tt->val + product;
							flag = true;
							break;
						}
						tt = tt->next;
					}
					if(flag == false)
					{
						newNode->row = temp1->row;
						newNode->col = temp2->col;
						newNode->val = product;
						if(head3 == NULL)
						{
							head3 = newNode;
							temp3 = head3;
						}
						else
						{
							temp3->next = newNode;
							temp3 = newNode;
						}
					}
				}
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}

		cout << endl << "Result in sparse Matrix is: " << endl;
		temp3 = head3;
		while(temp3 != NULL)
		{
			cout << "row: " << temp3->row << " col: " << temp3->col << " val: " << temp3->val << endl;
			m3_float[temp3->row][temp3->col] = temp3->val;
			temp3 = temp3->next; 
		}
		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_float", row1, col2);
	}
}

void multiplication_LL_double(int row1, int col1, int row2, int col2)
{
	int n1=0, n2=0;
	for(int i=0; i<row1; i++)
	{
		for(int j=0; j<col1; j++)
		{
			if(m1_double[i][j] != 0)
			{
				n1++;
			}
		}
	}

	for(int i=0; i<row2; i++)
	{
		for(int j=0; j<col2; j++)
		{
			if(m2_double[i][j] != 0)
			{
				n2++;
			}
		}
	}

	if(n1==0 || n2==0)
	{
		print_zero_matrix(row1, col2);
	}
	else
	{
		struct NodeDouble *head1 = convert_to_LL_double("m1_double", row1, col1);
		struct NodeDouble *head2 = convert_to_LL_double("m2_double", row2, col2);

		struct NodeDouble *head3 = NULL;

		struct NodeDouble *temp1 = head1;
		struct NodeDouble *temp2 = head2;
		struct NodeDouble *temp3 = head3;

		while(temp1 != NULL)
		{
			temp2 = head2;
			while(temp2 != NULL)
			{
				struct NodeDouble *newNode = new NodeDouble();
				/* multiplication posssible */
				if(temp1->col == temp2->row)
				{
					double product = temp1->val * temp2->val;					
					bool flag = false;
					struct NodeDouble *tt = head3;
					while(tt != NULL)
					{
						if(tt->row == temp1->row && tt->col == temp2->col)
						{
							tt->val = tt->val + product;
							flag = true;
							break;
						}
						tt = tt->next;
					}
					if(flag == false)
					{
						newNode->row = temp1->row;
						newNode->col = temp2->col;
						newNode->val = product;
						if(head3 == NULL)
						{
							head3 = newNode;
							temp3 = head3;
						}
						else
						{
							temp3->next = newNode;
							temp3 = newNode;
						}
					}
				}
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}

		cout << endl << "Result in sparse Matrix is: " << endl;
		temp3 = head3;
		while(temp3 != NULL)
		{
			cout << "row: " << temp3->row << " col: " << temp3->col << " val: " << temp3->val << endl;
			m3_double[temp3->row][temp3->col] = temp3->val;
			temp3 = temp3->next; 
		}
		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_double", row1, col2);
	}
}

int main()
{
	cout << "We are using LinkedList Data Structure" << endl;
	
	int dataType;
	cout << "Choose Data Type [int(1) / floor(2) / double(3)] : ";
	cin >> dataType;

	/* Integer Datatype */
	if(dataType == 1)
	{
		int type;
		cout << "Choose Type of Operation (Transpose(1) / Addition(2) / Multiplication(3)): ";
		cin >> type;

		/* transpose */
		if(type == 1)
		{
			int rows, cols;
			cout << "Enter rows and columns separated by space: ";
			cin >> rows >> cols;

			cout << "Enter the elements of the matrix " << endl;
			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<cols; j++)
				{
					cin >> m1_int[i][j];
				}
			}
			cout << endl << "The Resultant Matrix is " << endl;
			transpose_LL_int(rows, cols);
			cout << endl << "Result in 2D Array is: " << endl;
			print_matrix("m3_int", cols, rows);
		}

		/* addition */
		else if(type == 2)
		{
			int rows, cols;
			cout << "Enter rows and columns separated by space: ";
			cin >> rows >> cols;

			cout << "Enter the elements of the 1st matrix " << endl;
			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<cols; j++)
				{
					cin >> m1_int[i][j];
				}
			}

			cout << "Enter the elements of the 2nd matrix " << endl;
			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<cols; j++)
				{
					cin >> m2_int[i][j];
				}
			}
			cout << endl << "The Resultant Matrix is " << endl;
			addition_LL_int(rows, cols);
			cout << endl << "Result in 2D Array is: " << endl;
			print_matrix("m3_int", rows, cols);
		}

		/* multiplication */
		else if(type == 3)
		{
			int row1, col1, row2, col2;
			cout << "Enter rows and columns of 1st Marix separated by space: ";
			cin >> row1 >> col1;
			cout << "Enter rows and columns of 2nd Marix separated by space: ";
			cin >> row2 >> col2;
			if(col1 != row2)
			{
				cout << "Matrix Dimension Mismatch!! multiplication not possible" << endl;
			}
			else
			{
				cout << "Enter the elements of the 1st matrix " << endl;
				for(int i=0; i<row1; i++)
				{
					for(int j=0; j<col1; j++)
					{
						cin >> m1_int[i][j];
					}
				}

				cout << "Enter the elements of the 2nd matrix " << endl;
				for(int i=0; i<row2; i++)
				{
					for(int j=0; j<col2; j++)
					{
						cin >> m2_int[i][j];
					}
				}
				cout << endl << "The Resultant Matrix is " << endl;
				multiplication_LL_int(row1, col1, row2, col2);
				cout << endl << "Result in 2D Array is: " << endl;
				print_matrix("m3_int", row1, col2);
			}	
		}
	
	}

	/* float datatype */
	else if(dataType == 2)
	{
		int type;
		cout << "Choose Type of Operation (Transpose(1) / Addition(2) / Multiplication(3)): ";
		cin >> type;

		/* transpose */
		if(type == 1)
		{
			int rows, cols;
			cout << "Enter rows and columns separated by space: ";
			cin >> rows >> cols;

			cout << "Enter the elements of the matrix " << endl;
			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<cols; j++)
				{
					cin >> m1_float[i][j];
				}
			}

			cout << endl << "The Resultant Matrix is " << endl;
			transpose_LL_float(rows, cols);
			cout << endl << "Result in 2D Array is: " << endl;
			print_matrix("m3_float", cols, rows);
		}

		/* addition */
		else if(type == 2)
		{
			int rows, cols;
			cout << "Enter rows and columns separated by space: ";
			cin >> rows >> cols;

			cout << "Enter the elements of the 1st matrix " << endl;
			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<cols; j++)
				{
					cin >> m1_float[i][j];
				}
			}

			cout << "Enter the elements of the 2nd matrix " << endl;
			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<cols; j++)
				{
					cin >> m2_float[i][j];
				}
			}
			cout << endl << "The Resultant Matrix is " << endl;
			addition_LL_float(rows, cols);
			cout << endl << "Result in 2D Array is: " << endl;
			print_matrix("m3_float", rows, cols);
		}

		/* multiplication */
		else if(type == 3)
		{
			int row1, col1, row2, col2;
			cout << "Enter rows and columns of 1st Marix separated by space: ";
			cin >> row1 >> col1;
			cout << "Enter rows and columns of 2nd Marix separated by space: ";
			cin >> row2 >> col2;
			if(col1 != row2)
			{
				cout << "Matrix Dimension Mismatch!! multiplication not possible" << endl;
			}
			else
			{
				cout << "Enter the elements of the 1st matrix " << endl;
				for(int i=0; i<row1; i++)
				{
					for(int j=0; j<col1; j++)
					{
						cin >> m1_float[i][j];
					}
				}

				cout << "Enter the elements of the 2nd matrix " << endl;
				for(int i=0; i<row2; i++)
				{
					for(int j=0; j<col2; j++)
					{
						cin >> m2_float[i][j];
					}
				}
				cout << endl << "The Resultant Matrix is " << endl;
				multiplication_LL_float(row1, col1, row2, col2);
				cout << endl << "Result in 2D Array is: " << endl;
				print_matrix("m3_float", row1, col2);
			}	
		}

	}
	/* double datatype */
	else if(dataType == 3)
	{
		int type;
		cout << "Choose Type of Operation (Transpose(1) / Addition(2) / Multiplication(3)): ";
		cin >> type;

		/* transpose */
		if(type == 1)
		{
			int rows, cols;
			cout << "Enter rows and columns separated by space: ";
			cin >> rows >> cols;

			cout << "Enter the elements of the matrix " << endl;
			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<cols; j++)
				{
					cin >> m1_double[i][j];
				}
			}

			cout << endl << "The Resultant Matrix is " << endl;
			transpose_LL_double(rows, cols);
			cout << endl << "Result in 2D Array is: " << endl;
			print_matrix("m3_double", cols, rows);
		}

		/* addition */
		else if(type == 2)
		{
			int rows, cols;
			cout << "Enter rows and columns separated by space: ";
			cin >> rows >> cols;

			cout << "Enter the elements of the 1st matrix " << endl;
			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<cols; j++)
				{
					cin >> m1_double[i][j];
				}
			}

			cout << "Enter the elements of the 2nd matrix " << endl;
			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<cols; j++)
				{
					cin >> m2_double[i][j];
				}
			}
			cout << endl << "The Resultant Matrix is " << endl;
			addition_LL_double(rows, cols);
			cout << endl << "Result in 2D Array is: " << endl;
			print_matrix("m3_double", rows, cols);
		}

		/* multiplication */
		else if(type == 3)
		{
			int row1, col1, row2, col2;
			cout << "Enter rows and columns of 1st Marix separated by space: ";
			cin >> row1 >> col1;
			cout << "Enter rows and columns of 2nd Marix separated by space: ";
			cin >> row2 >> col2;
			if(col1 != row2)
			{
				cout << "Matrix Dimension Mismatch!! multiplication not possible" << endl;
			}
			else
			{
				cout << "Enter the elements of the 1st matrix " << endl;
				for(int i=0; i<row1; i++)
				{
					for(int j=0; j<col1; j++)
					{
						cin >> m1_double[i][j];
					}
				}

				cout << "Enter the elements of the 2nd matrix " << endl;
				for(int i=0; i<row2; i++)
				{
					for(int j=0; j<col2; j++)
					{
						cin >> m2_double[i][j];
					}
				}
				cout << endl << "The Resultant Matrix is " << endl;
				multiplication_LL_double(row1, col1, row2, col2);
				cout << endl << "Result in 2D Array is: " << endl;
				print_matrix("m3_double", row1, col2);
			}	
		}
	}
	
	return 0;
}