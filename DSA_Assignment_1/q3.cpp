#include<iostream>
using namespace std;
int m1[10000][10000];
int m2[10000][10000];
int m3[10000][10000];
int tup1[100000][3];
int tup2[100000][3];
int tup3[100000][3];

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
	if(str == "m1")
	{
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				cout << m1[i][j] << " ";
			}
			cout << endl;
		}
	}
	else if(str == "m2")
	{
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				cout << m2[i][j] << " ";
			}
			cout << endl;
		}
	}
	else if(str == "m3")
	{
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				cout << m3[i][j] << " ";
			}
			cout << endl;
		}
	}
}

void transpose(int rows, int cols)
{
	int n1=0;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(m1[i][j] != 0)
			{
				n1++;
			}
		}
	}
	if(n1 == 0)
	{
		print_zero_matrix(rows, cols);
	}
	else
	{
		/* storing matrix 1 in tuple format */
		tup1[0][0] = rows; tup1[0][1] = cols; tup1[0][2] = n1;
		int k=1;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m1[i][j] != 0)
				{
					tup1[k][0] = i;
					tup1[k][1] = j;
					tup1[k][2] = m1[i][j];
					k++;
				}
			}
		}

		/* swapping rows and cols in tuple */
		for(int k=0; k<=n1; k++)
		{
			int temp = tup1[k][0];
			tup1[k][0] = tup1[k][1];
			tup1[k][1] = temp;
		}

		/* printing the result tuple */
		for(int k=1; k<=n1; k++)
		{
			cout << "row: " << tup1[k][0] << " col: " << tup1[k][1] << " val: " << tup1[k][2] << endl; 
		}

		/* storing result tuple in m3 */
		for(int k=1; k<=n1; k++)
		{
			int r=tup1[k][0];
			int c=tup1[k][1];
			int val=tup1[k][2];
			m3[r][c] = val;
		}

		print_matrix("m3", cols, rows);
	}
}

void addition(int rows, int cols)
{
	int n1=0, n2=0;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(m1[i][j] != 0)
			{
				n1++;
			}
		}
	}

	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(m2[i][j] != 0)
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
		print_matrix("m2", rows, cols);
	}
	else if(n2 == 0)
	{
		print_matrix("m1", rows, cols);
	}
	else
	{
		/* storing matrix 1 in tuple format */
		tup1[0][0] = rows; tup1[0][1] = cols; tup1[0][2] = n1;
		int k=1;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m1[i][j] != 0)
				{
					tup1[k][0] = i;
					tup1[k][1] = j;
					tup1[k][2] = m1[i][j];
					k++;
				}
			}
		}

		/* storing matrix 2 in tuple format */
		tup2[0][0] = rows; tup2[0][1] = cols; tup2[0][2] = n2;
		k=1;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m2[i][j] != 0)
				{
					tup2[k][0] = i;
					tup2[k][1] = j;
					tup2[k][2] = m2[i][j];
					k++;
				}
			}
		}

		/* creating the result tuple */
		k=1;
		for(int i=1; i<=n1; i++)
		{
			bool flag = false;
			for(int j=1; j<=n2; j++)
			{
				if(tup1[i][0]==tup2[j][0] && tup1[i][1]==tup2[j][1])
				{
					int sum = tup1[i][2] + tup2[j][2];
					tup3[k][0] = tup1[i][0]; 
					tup3[k][1] = tup1[i][1];
					tup3[k][2] = sum;
					k++;
					flag = true;
				}
			}
			if(flag == false)
			{
				tup3[k][0] = tup1[i][0]; 
				tup3[k][1] = tup1[i][1];
				tup3[k][2] = tup1[i][2];
				k++;
			}
		}
		for(int i=1; i<=n2; i++)
		{
			bool flag = false;
			for(int j=1; j<=n1; j++)
			{
				if(tup2[i][0]==tup1[j][0] && tup2[i][1]==tup1[j][1])
				{
					flag = true;
				}
			}
			if(flag == false)
			{
				tup3[k][0] = tup2[i][0]; 
				tup3[k][1] = tup2[i][1];
				tup3[k][2] = tup2[i][2];
				k++;
			}
		}

		/* storing result tuple in matrix 3 */
		int n3=k-1;
		tup3[0][0]=rows; tup3[0][1]=cols; tup3[0][2]=n3;
		for(int k=1; k<=n3; k++)
		{
			cout << "row: " << tup3[k][0] << " col: " << tup3[k][1] << " val: " << tup3[k][2] << endl;
		}

		for(int k=1; k<=n3; k++)
		{
			int r=tup3[k][0];
			int c=tup3[k][1];
			int val=tup3[k][2];
			m3[r][c]=val;
		}
		print_matrix("m3", rows, cols);
	}
}

void multiplication(int row1, int col1, int row2, int col2)
{
	int n1=0, n2=0;
	for(int i=0; i<row1; i++)
	{
		for(int j=0; j<col1; j++)
		{
			if(m1[i][j] != 0)
			{
				n1++;
			}
		}
	}

	for(int i=0; i<row2; i++)
	{
		for(int j=0; j<col2; j++)
		{
			if(m2[i][j] != 0)
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
		/* storing matrix 1 in tuple format */
		tup1[0][0] = row1; tup1[0][1] = col1; tup1[0][2] = n1;
		int k=1;
		for(int i=0; i<row1; i++)
		{
			for(int j=0; j<col1; j++)
			{
				if(m1[i][j] != 0)
				{
					tup1[k][0] = i;
					tup1[k][1] = j;
					tup1[k][2] = m1[i][j];
					k++;
				}
			}
		}

		/* storing matrix 2 in tuple format */
		tup2[0][0] = row2; tup2[0][1] = col2; tup2[0][2] = n2;
		k=1;
		for(int i=0; i<row2; i++)
		{
			for(int j=0; j<col2; j++)
			{
				if(m2[i][j] != 0)
				{
					tup2[k][0] = i;
					tup2[k][1] = j;
					tup2[k][2] = m2[i][j];
					k++;
				}
			}
		}

		/* creating the result tuple */
		/* n3 is the count of number of tuples in tup3 */
		int n3=0; k=1;
		for(int i=1; i<=n1; i++)
		{
			for(int j=1; j<=n2; j++)
			{
				int res_row = tup1[i][0];
				int res_col = tup2[j][1];
				if(tup1[i][1] == tup2[j][0])
				{
					int tmp=0;
					tmp = tup1[i][2] * tup2[j][2];
					cout << tmp << endl;
					bool flag = false;
					for(k=1; k<=n3; k++)
					{
						if(tup3[k][0] == res_row && tup3[k][1] == res_col)
						{
							tup3[k][2] = tup3[k][2] + tmp;
							flag = true;
						}
					}
					if(flag == false)
					{
						n3++;
						tup3[n3][0] = res_row;
						tup3[n3][1] = res_col;
						tup3[n3][2] = tmp;
					}
				}
				
			}
		}

		tup3[0][0]=row1; tup3[0][1]=col2; tup3[0][2]=n3;

		for(int k=1; k<=n3; k++)
		{
			cout << "row: " << tup3[k][0] << " col: " << tup3[k][1] << " val: " << tup3[k][2] << endl;
		}

		/* storing the result tuple inside matrix m3 */
		for(int k=1; k<=n3; k++)
		{
			int r = tup3[k][0];
			int c = tup3[k][1];
			int val = tup3[k][2];
			m3[r][c] = val;
		}

		print_matrix("m3", row1, col2);
	}
}

int main()
{
	int type;
	cin >> type;

	/* transpose */
	if(type == 1)
	{
		int rows, cols;
		cin >> rows >> cols;

		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				cin >> m1[i][j];
			}
		}
		transpose(rows, cols);
	}
	/* addition */
	else if(type == 2)
	{
		int rows, cols;
		cin >> rows >> cols;

		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				cin >> m1[i][j];
			}
		}

		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				cin >> m2[i][j];
			}
		}

		addition(rows, cols);
	}
	/* multiplication */
	else if(type == 3)
	{
		int row1, col1, row2, col2;
		cin >> row1 >> col1 >> row2 >> col2;
		if(col1 != row2)
		{
			cout << "Matrix Dimension Mismatch!! multiplication not possible" << endl;
		}
		else
		{
			for(int i=0; i<row1; i++)
			{
				for(int j=0; j<col1; j++)
				{
					cin >> m1[i][j];
				}
			}

			for(int i=0; i<row2; i++)
			{
				for(int j=0; j<col2; j++)
				{
					cin >> m2[i][j];
				}
			}
			multiplication(row1, col1, row2, col2);
		}
		
	}
	
	return 0;
}