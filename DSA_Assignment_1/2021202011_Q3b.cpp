#include<iostream>
using namespace std;

int m1_int[10000][10000];
int m2_int[10000][10000];
int m3_int[10000][10000];
int tup1_int[10000000][3];
int tup2_int[10000000][3];
int tup3_int[10000000][3];

float m1_float[2000][2000];
float m2_float[2000][2000];
float m3_float[2000][2000];
float tup1_float[1000000][3];
float tup2_float[1000000][3];
float tup3_float[1000000][3];

double m1_double[2000][2000];
double m2_double[2000][2000];
double m3_double[2000][2000];
double tup1_double[1000000][3];
double tup2_double[1000000][3];
double tup3_double[1000000][3];

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

void transpose_int(int rows, int cols)
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
		/* storing matrix 1 in tuple format */
		tup1_int[0][0] = rows; tup1_int[0][1] = cols; tup1_int[0][2] = n1;
		int k=1;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m1_int[i][j] != 0)
				{
					tup1_int[k][0] = i;
					tup1_int[k][1] = j;
					tup1_int[k][2] = m1_int[i][j];
					k++;
				}
			}
		}

		/* swapping rows and cols in tuple */
		for(int k=0; k<=n1; k++)
		{
			int temp = tup1_int[k][0];
			tup1_int[k][0] = tup1_int[k][1];
			tup1_int[k][1] = temp;
		}

		cout << endl << "Result in sparse Matrix is: " << endl;
		/* printing the result tuple */
		for(int k=1; k<=n1; k++)
		{
			cout << "row: " << tup1_int[k][0] << " col: " << tup1_int[k][1] << " val: " << tup1_int[k][2] << endl; 
		}

		/* storing result tuple in m3 */
		for(int k=1; k<=n1; k++)
		{
			int r=tup1_int[k][0];
			int c=tup1_int[k][1];
			int val=tup1_int[k][2];
			m3_int[r][c] = val;
		}
		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_int", cols, rows);
	}
}

void transpose_float(int rows, int cols)
{
	int n1=0;
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

	cout << n1 << endl;

	if(n1 == 0)
	{
		print_zero_matrix(cols, rows);
	}
	else
	{
		/* storing matrix 1 in tuple format */
		tup1_float[0][0] = rows; tup1_float[0][1] = cols; tup1_float[0][2] = n1;
		int k=1;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m1_float[i][j] != float(0))
				{
					tup1_float[k][0] = i;
					tup1_float[k][1] = j;
					tup1_float[k][2] = m1_float[i][j];
					k++;
				}
			}
		}

		/* swapping rows and cols in tuple */
		for(int k=0; k<=n1; k++)
		{
			float temp = tup1_float[k][0];
			tup1_float[k][0] = tup1_float[k][1];
			tup1_float[k][1] = temp;
		}

		cout << endl << "Result in sparse Matrix is: " << endl;
		/* printing the result tuple */
		for(int k=1; k<=n1; k++)
		{
			cout << "row: " << tup1_float[k][0] << " col: " << tup1_float[k][1] << " val: " << tup1_float[k][2] << endl; 
		}

		/* storing result tuple in m3 */
		for(int k=1; k<=n1; k++)
		{
			int r=tup1_float[k][0];
			int c=tup1_float[k][1];
			float val=tup1_float[k][2];
			m3_float[r][c] = val;
		}

		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_float", cols, rows);
	}
}

void transpose_double(int rows, int cols)
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
		/* storing matrix 1 in tuple format */
		tup1_double[0][0] = rows; tup1_double[0][1] = cols; tup1_double[0][2] = n1;
		int k=1;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m1_double[i][j] != double(0))
				{
					tup1_double[k][0] = i;
					tup1_double[k][1] = j;
					tup1_double[k][2] = m1_double[i][j];
					k++;
				}
			}
		}

		/* swapping rows and cols in tuple */
		for(int k=0; k<=n1; k++)
		{
			double temp = tup1_double[k][0];
			tup1_double[k][0] = tup1_double[k][1];
			tup1_double[k][1] = temp;
		}

		cout << endl << "Result in sparse Matrix is: " << endl;
		/* printing the result tuple */
		for(int k=1; k<=n1; k++)
		{
			cout << "row: " << tup1_double[k][0] << " col: " << tup1_double[k][1] << " val: " << tup1_double[k][2] << endl; 
		}

		/* storing result tuple in m3 */
		for(int k=1; k<=n1; k++)
		{
			int r=tup1_double[k][0];
			int c=tup1_double[k][1];
			double val=tup1_double[k][2];
			m3_double[r][c] = val;
		}

		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_double", cols, rows);
	}
}

void addition_int(int rows, int cols)
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
		/* storing matrix 1 in tuple format */
		tup1_int[0][0] = rows; tup1_int[0][1] = cols; tup1_int[0][2] = n1;
		int k=1;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m1_int[i][j] != 0)
				{
					tup1_int[k][0] = i;
					tup1_int[k][1] = j;
					tup1_int[k][2] = m1_int[i][j];
					k++;
				}
			}
		}

		/* storing matrix 2 in tuple format */
		tup2_int[0][0] = rows; tup2_int[0][1] = cols; tup2_int[0][2] = n2;
		k=1;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m2_int[i][j] != 0)
				{
					tup2_int[k][0] = i;
					tup2_int[k][1] = j;
					tup2_int[k][2] = m2_int[i][j];
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
				if(tup1_int[i][0]==tup2_int[j][0] && tup1_int[i][1]==tup2_int[j][1])
				{
					int sum = tup1_int[i][2] + tup2_int[j][2];
					tup3_int[k][0] = tup1_int[i][0]; 
					tup3_int[k][1] = tup1_int[i][1];
					tup3_int[k][2] = sum;
					k++;
					flag = true;
				}
			}
			if(flag == false)
			{
				tup3_int[k][0] = tup1_int[i][0]; 
				tup3_int[k][1] = tup1_int[i][1];
				tup3_int[k][2] = tup1_int[i][2];
				k++;
			}
		}
		for(int i=1; i<=n2; i++)
		{
			bool flag = false;
			for(int j=1; j<=n1; j++)
			{
				if(tup2_int[i][0]==tup1_int[j][0] && tup2_int[i][1]==tup1_int[j][1])
				{
					flag = true;
				}
			}
			if(flag == false)
			{
				tup3_int[k][0] = tup2_int[i][0]; 
				tup3_int[k][1] = tup2_int[i][1];
				tup3_int[k][2] = tup2_int[i][2];
				k++;
			}
		}

		cout << endl << "Result in sparse Matrix is: " << endl;
		/* storing result tuple in matrix 3 */
		int n3=k-1;
		tup3_int[0][0]=rows; tup3_int[0][1]=cols; tup3_int[0][2]=n3;
		for(int k=1; k<=n3; k++)
		{
			cout << "row: " << tup3_int[k][0] << " col: " << tup3_int[k][1] << " val: " << tup3_int[k][2] << endl;
		}

		for(int k=1; k<=n3; k++)
		{
			int r=tup3_int[k][0];
			int c=tup3_int[k][1];
			int val=tup3_int[k][2];
			m3_int[r][c]=val;
		}
		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_int", rows, cols);
	}
}

void addition_float(int rows, int cols)
{
	int n1=0, n2=0;
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
		/* storing matrix 1 in tuple format */
		tup1_float[0][0] = rows; tup1_float[0][1] = cols; tup1_float[0][2] = n1;
		int k=1;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m1_float[i][j] != 0)
				{
					tup1_float[k][0] = i;
					tup1_float[k][1] = j;
					tup1_float[k][2] = m1_float[i][j];
					k++;
				}
			}
		}

		/* storing matrix 2 in tuple format */
		tup2_float[0][0] = rows; tup2_float[0][1] = cols; tup2_float[0][2] = n2;
		k=1;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m2_float[i][j] != 0)
				{
					tup2_float[k][0] = i;
					tup2_float[k][1] = j;
					tup2_float[k][2] = m2_float[i][j];
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
				if(tup1_float[i][0]==tup2_float[j][0] && tup1_float[i][1]==tup2_float[j][1])
				{
					float sum = tup1_float[i][2] + tup2_float[j][2];
					tup3_float[k][0] = tup1_float[i][0]; 
					tup3_float[k][1] = tup1_float[i][1];
					tup3_float[k][2] = sum;
					k++;
					flag = true;
				}
			}
			if(flag == false)
			{
				tup3_float[k][0] = tup1_float[i][0]; 
				tup3_float[k][1] = tup1_float[i][1];
				tup3_float[k][2] = tup1_float[i][2];
				k++;
			}
		}
		for(int i=1; i<=n2; i++)
		{
			bool flag = false;
			for(int j=1; j<=n1; j++)
			{
				if(tup2_float[i][0]==tup1_float[j][0] && tup2_float[i][1]==tup1_float[j][1])
				{
					flag = true;
				}
			}
			if(flag == false)
			{
				tup3_float[k][0] = tup2_float[i][0]; 
				tup3_float[k][1] = tup2_float[i][1];
				tup3_float[k][2] = tup2_float[i][2];
				k++;
			}
		}

		cout << endl << "Result in sparse Matrix is: " << endl;
		/* storing result tuple in matrix 3 */
		int n3=k-1;
		tup3_float[0][0]=rows; tup3_float[0][1]=cols; tup3_float[0][2]=n3;
		for(int k=1; k<=n3; k++)
		{
			cout << "row: " << tup3_float[k][0] << " col: " << tup3_float[k][1] << " val: " << tup3_float[k][2] << endl;
		}

		for(int k=1; k<=n3; k++)
		{
			int r=tup3_float[k][0];
			int c=tup3_float[k][1];
			float val=tup3_float[k][2];
			m3_float[r][c]=val;
		}
		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_float", rows, cols);
	}
}

void addition_double(int rows, int cols)
{
	int n1=0, n2=0;
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
		/* storing matrix 1 in tuple format */
		tup1_double[0][0] = rows; tup1_double[0][1] = cols; tup1_double[0][2] = n1;
		int k=1;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m1_double[i][j] != 0)
				{
					tup1_double[k][0] = i;
					tup1_double[k][1] = j;
					tup1_double[k][2] = m1_double[i][j];
					k++;
				}
			}
		}

		/* storing matrix 2 in tuple format */
		tup2_double[0][0] = rows; tup2_double[0][1] = cols; tup2_double[0][2] = n2;
		k=1;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(m2_double[i][j] != 0)
				{
					tup2_double[k][0] = i;
					tup2_double[k][1] = j;
					tup2_double[k][2] = m2_double[i][j];
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
				if(tup1_double[i][0]==tup2_double[j][0] && tup1_double[i][1]==tup2_double[j][1])
				{
					double sum = tup1_double[i][2] + tup2_double[j][2];
					tup3_double[k][0] = tup1_double[i][0]; 
					tup3_double[k][1] = tup1_double[i][1];
					tup3_double[k][2] = sum;
					k++;
					flag = true;
				}
			}
			if(flag == false)
			{
				tup3_double[k][0] = tup1_double[i][0]; 
				tup3_double[k][1] = tup1_double[i][1];
				tup3_double[k][2] = tup1_double[i][2];
				k++;
			}
		}
		for(int i=1; i<=n2; i++)
		{
			bool flag = false;
			for(int j=1; j<=n1; j++)
			{
				if(tup2_double[i][0]==tup1_double[j][0] && tup2_double[i][1]==tup1_double[j][1])
				{
					flag = true;
				}
			}
			if(flag == false)
			{
				tup3_double[k][0] = tup2_double[i][0]; 
				tup3_double[k][1] = tup2_double[i][1];
				tup3_double[k][2] = tup2_double[i][2];
				k++;
			}
		}

		cout << endl << "Result in sparse Matrix is: " << endl;
		/* storing result tuple in matrix 3 */
		int n3=k-1;
		tup3_double[0][0]=rows; tup3_double[0][1]=cols; tup3_double[0][2]=n3;
		for(int k=1; k<=n3; k++)
		{
			cout << "row: " << tup3_double[k][0] << " col: " << tup3_double[k][1] << " val: " << tup3_double[k][2] << endl;
		}

		for(int k=1; k<=n3; k++)
		{
			int r=tup3_double[k][0];
			int c=tup3_double[k][1];
			double val=tup3_double[k][2];
			m3_double[r][c]=val;
		}
		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_double", rows, cols);
	}
}

void multiplication_int(int row1, int col1, int row2, int col2)
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
		/* storing matrix 1 in tuple format */
		tup1_int[0][0] = row1; tup1_int[0][1] = col1; tup1_int[0][2] = n1;
		int k=1;
		for(int i=0; i<row1; i++)
		{
			for(int j=0; j<col1; j++)
			{
				if(m1_int[i][j] != 0)
				{
					tup1_int[k][0] = i;
					tup1_int[k][1] = j;
					tup1_int[k][2] = m1_int[i][j];
					k++;
				}
			}
		}

		/* storing matrix 2 in tuple format */
		tup2_int[0][0] = row2; tup2_int[0][1] = col2; tup2_int[0][2] = n2;
		k=1;
		for(int i=0; i<row2; i++)
		{
			for(int j=0; j<col2; j++)
			{
				if(m2_int[i][j] != 0)
				{
					tup2_int[k][0] = i;
					tup2_int[k][1] = j;
					tup2_int[k][2] = m2_int[i][j];
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
				int res_row = tup1_int[i][0];
				int res_col = tup2_int[j][1];
				if(tup1_int[i][1] == tup2_int[j][0])
				{
					int tmp=0;
					tmp = tup1_int[i][2] * tup2_int[j][2];
					cout << tmp << endl;
					bool flag = false;
					for(k=1; k<=n3; k++)
					{
						if(tup3_int[k][0] == res_row && tup3_int[k][1] == res_col)
						{
							cout << "Prev: " << tup3_int[k][2] << endl;
							tup3_int[k][2] = tup3_int[k][2] + tmp;
							cout << "After: " << tup3_int[k][2] << endl;
							flag = true;
						}
					}
					if(flag == false)
					{
						n3++;
						tup3_int[n3][0] = res_row;
						tup3_int[n3][1] = res_col;
						tup3_int[n3][2] = tmp;
					}
				}
				
			}
		}

		tup3_int[0][0]=row1; tup3_int[0][1]=col2; tup3_int[0][2]=n3;
		cout << endl << "Result in sparse Matrix is: " << endl;
		for(int k=1; k<=n3; k++)
		{
			cout << "row: " << tup3_int[k][0] << " col: " << tup3_int[k][1] << " val: " << tup3_int[k][2] << endl;
		}

		/* storing the result tuple inside matrix m3 */
		for(int k=1; k<=n3; k++)
		{
			int r = tup3_int[k][0];
			int c = tup3_int[k][1];
			int val = tup3_int[k][2];
			m3_int[r][c] = val;
		}
		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_int", row1, col2);
	}
}

void multiplication_float(int row1, int col1, int row2, int col2)
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
		/* storing matrix 1 in tuple format */
		tup1_float[0][0] = row1; tup1_float[0][1] = col1; tup1_float[0][2] = n1;
		int k=1;
		for(int i=0; i<row1; i++)
		{
			for(int j=0; j<col1; j++)
			{
				if(m1_float[i][j] != 0)
				{
					tup1_float[k][0] = i;
					tup1_float[k][1] = j;
					tup1_float[k][2] = m1_float[i][j];
					k++;
				}
			}
		}

		/* storing matrix 2 in tuple format */
		tup2_float[0][0] = row2; tup2_float[0][1] = col2; tup2_float[0][2] = n2;
		k=1;
		for(int i=0; i<row2; i++)
		{
			for(int j=0; j<col2; j++)
			{
				if(m2_float[i][j] != 0)
				{
					tup2_float[k][0] = i;
					tup2_float[k][1] = j;
					tup2_float[k][2] = m2_float[i][j];
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
				int res_row = tup1_float[i][0];
				int res_col = tup2_float[j][1];
				if(tup1_float[i][1] == tup2_float[j][0])
				{
					float tmp=0;
					tmp = tup1_float[i][2] * tup2_float[j][2];
					// cout << tmp << endl;
					bool flag = false;
					for(k=1; k<=n3; k++)
					{
						if(tup3_float[k][0] == res_row && tup3_float[k][1] == res_col)
						{
							tup3_float[k][2] = tup3_float[k][2] + tmp;
							flag = true;
						}
					}
					if(flag == false)
					{
						n3++;
						tup3_float[n3][0] = res_row;
						tup3_float[n3][1] = res_col;
						tup3_float[n3][2] = tmp;
					}
				}
				
			}
		}

		tup3_float[0][0]=row1; tup3_float[0][1]=col2; tup3_float[0][2]=n3;
		cout << endl << "Result in sparse Matrix is: " << endl;
		for(int k=1; k<=n3; k++)
		{
			cout << "row: " << tup3_float[k][0] << " col: " << tup3_float[k][1] << " val: " << tup3_float[k][2] << endl;
		}

		/* storing the result tuple inside matrix m3 */
		for(int k=1; k<=n3; k++)
		{
			int r = tup3_float[k][0];
			int c = tup3_float[k][1];
			float val = tup3_float[k][2];
			m3_float[r][c] = val;
		}
		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_float", row1, col2);
	}
}

void multiplication_double(int row1, int col1, int row2, int col2)
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
		/* storing matrix 1 in tuple format */
		tup1_double[0][0] = row1; tup1_double[0][1] = col1; tup1_double[0][2] = n1;
		int k=1;
		for(int i=0; i<row1; i++)
		{
			for(int j=0; j<col1; j++)
			{
				if(m1_double[i][j] != 0)
				{
					tup1_double[k][0] = i;
					tup1_double[k][1] = j;
					tup1_double[k][2] = m1_double[i][j];
					k++;
				}
			}
		}

		/* storing matrix 2 in tuple format */
		tup2_double[0][0] = row2; tup2_double[0][1] = col2; tup2_double[0][2] = n2;
		k=1;
		for(int i=0; i<row2; i++)
		{
			for(int j=0; j<col2; j++)
			{
				if(m2_double[i][j] != 0)
				{
					tup2_double[k][0] = i;
					tup2_double[k][1] = j;
					tup2_double[k][2] = m2_double[i][j];
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
				int res_row = tup1_double[i][0];
				int res_col = tup2_double[j][1];
				if(tup1_double[i][1] == tup2_double[j][0])
				{
					double tmp=0;
					tmp = tup1_double[i][2] * tup2_double[j][2];
					// cout << tmp << endl;
					bool flag = false;
					for(k=1; k<=n3; k++)
					{
						if(tup3_double[k][0] == res_row && tup3_double[k][1] == res_col)
						{
							tup3_double[k][2] = tup3_double[k][2] + tmp;
							flag = true;
						}
					}
					if(flag == false)
					{
						n3++;
						tup3_double[n3][0] = res_row;
						tup3_double[n3][1] = res_col;
						tup3_double[n3][2] = tmp;
					}
				}
				
			}
		}

		tup3_double[0][0]=row1; tup3_double[0][1]=col2; tup3_double[0][2]=n3;
		cout << endl << "Result in sparse Matrix is: " << endl;
		for(int k=1; k<=n3; k++)
		{
			cout << "row: " << tup3_double[k][0] << " col: " << tup3_double[k][1] << " val: " << tup3_double[k][2] << endl;
		}

		/* storing the result tuple inside matrix m3 */
		for(int k=1; k<=n3; k++)
		{
			int r = tup3_double[k][0];
			int c = tup3_double[k][1];
			double val = tup3_double[k][2];
			m3_double[r][c] = val;
		}
		// cout << endl << "Result in 2D Array is: " << endl;
		// print_matrix("m3_double", row1, col2);
	}
}

int main()
{
	
	cout << "We are using Array Data Structure" << endl;
	
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
			cout << "The Resultant Matrix is " << endl;
			transpose_int(rows, cols);
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
			cout << "The Resultant Matrix is " << endl;
			addition_int(rows, cols);
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
				cout << "The Resultant Matrix is " << endl;
				multiplication_int(row1, col1, row2, col2);
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

			cout << "The Resultant Matrix is " << endl;
			transpose_float(rows, cols);
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
			cout << "The Resultant Matrix is " << endl;
			addition_float(rows, cols);
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
				cout << "The Resultant Matrix is " << endl;
				multiplication_float(row1, col1, row2, col2);
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

			cout << "The Resultant Matrix is " << endl;
			transpose_double(rows, cols);
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
			cout << "The Resultant Matrix is " << endl;
			addition_double(rows, cols);
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
				cout << "The Resultant Matrix is " << endl;
				multiplication_double(row1, col1, row2, col2);
				cout << endl << "Result in 2D Array is: " << endl;
				print_matrix("m3_double", row1, col2);
			}	
		}
	}
	
	return 0;
}