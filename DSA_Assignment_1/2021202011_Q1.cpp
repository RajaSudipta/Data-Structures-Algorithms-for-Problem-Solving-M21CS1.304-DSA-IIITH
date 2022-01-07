// Input format for first question-
// First line will contain the type of operation:
// 1 for exponentiation
// 2 for GCD
// 3 for factorial
// 4 for calculator

// The following line will contain one string in case of calculator and factorial, and two space separated strings in case of GCD and exponentiation.
// Eg:
// input 1:
// 1
// 2 34
// input 2:
// 2 
// 9 15
// input 3:
// 3
// 24
// input 4:
// 4
// 1+2+3*5-2

#include<iostream>
#include<string>
using namespace std;
#define M 1000000007

void reverseStr(string& str)
{
    int len = str.length();
    int dest = len/2;
 
    for (int i = 0; i < dest; i++)
    {
        swap(str[i], str[len-i-1]);
    }
}

long long int string_to_int(string str)
{
	long long int res = 0;
	for(int i=0; i<(int)str.length(); i++)
	{
		int t = (int)(str[i] - '0');
		res = res * 10 + t;
	}
	return res;
}

class BigInt {
public:

	BigInt()
	{

	}

	bool str1_greater_or_equal_to_str2(string str1, string str2)
	{
		int len1 = str1.length();
		int len2 = str2.length();
		if(len1 > len2)
		{
			return true;
		}
		else if(len1 < len2)
		{
			return false;
		}
		else
		{
			for(int i=0; i<len1; i++)
			{
				int t1 = (int)(str1[i] - '0');
				int t2 = (int)(str2[i] - '0');
				if(t1 > t2)
				{
					return true;
				}
				else if(t1 < t2)
				{
					return false;
				}
			}
			/* if both are equal */
			return true;
		}
	}

	string addition(string str1, string str2)
	{
		reverseStr(str1);
		reverseStr(str2);

		int len1 = str1.length();
		int len2 = str2.length();

		int carry = 0;

		string res;

		int min_len = min(len1, len2);

		for(int i=0; i<min_len; i++)
		{
			int t1 = int(str1[i] - '0');
			int t2 = int(str2[i] - '0');
			// cout << t1 << " " << t2 << endl;
			int sum = t1 + t2 + carry;

			int d = sum%10;

			carry = sum/10;

			res = res + to_string(d);
		}

		if(len1 > min_len)
		{
			for(int i=min_len; i<len1; i++)
			{
				int t1 = int(str1[i] - '0');
				int sum = t1 + carry;

				int d = sum%10;

				carry = sum/10;

				res = res + to_string(d);
			}
		}

		if(len2 > min_len)
		{
			for(int i=min_len; i<len2; i++)
			{
				int t2 = int(str2[i] - '0');
				int sum = t2 + carry;

				int d = sum%10;

				carry = sum/10;

				res = res + to_string(d);
			}
		}

		if(carry > 0)
		{
			res = res + to_string(carry);
		}

		reverseStr(res);

		return res;
	}

	/* It is assumed that always integer value of (str1) >= integer value of (str2) */
	string subtraction(string str1, string str2)
	{
		reverseStr(str1);
		reverseStr(str2);

		int len1 = str1.length();
		int len2 = str2.length();
		
		int carry = 0;
		string res = "";

		for(int i=0; i<len2; i++)
		{
			int t1 = (int)(str1[i] - '0');
			int t2 = (int)(str2[i] - '0');
			int diff = t1 - t2 - carry;

			if(diff >= 0)
			{
				carry = 0;
			}
			else
			{
				diff = diff + 10;
				carry = 1;
			}
			res = res + to_string(diff);
		}

		for(int i=len2; i<len1; i++)
		{
			int t1 = (int)(str1[i] - '0');
			int diff = t1 - carry;
			if(diff >= 0)
			{
				carry = 0;
			}
			else
			{
				diff = diff + 10;
				carry = 1;
			}
			res =  res + to_string(diff);
		}

		reverseStr(res);

		/* remove the trailing zeros eg 1000-999 = 0001 */
		int i = 0;
		while(res[i] == '0')
		{
			i++;
		}

		/* all zeros in result */
		if(i==(int)res.length())
		{
			return "0";
		}
		else
		{
			/* cut the trailing zeros by taking substring */
			res = res.substr(i);
			return res;
		}
	}

	string modulus_by_division(string dividend, string divisor)
	{
		string quotient = "0";
		// string remainder = "0"
		while(str1_greater_or_equal_to_str2(dividend, divisor) == true)
		{
			dividend = subtraction(dividend, divisor);
			// cout << dividend << endl;
			quotient = addition(quotient, "1");
		}
		return dividend;
	}

	string gcd_by_modulus(string str1, string str2)
	{
		if(str2 == "0")
		{
			return str1;
		}
		// cout << "gcd(" << str2 << ", " << modulus_by_division(str1, str2) <<")" << endl;
		return gcd_by_modulus(str2, modulus_by_division(str1, str2));
	}

	string multiplication(string str1, string str2)
	{
		int len1 = str1.length();
		int len2 = str2.length();

		if(len1 == 0 || len2 == 0)
		{
			return "0";
		}
		else
		{
			int arr_len = len1+len2;

			int arr[arr_len] = {0};

			int shiftFactor = 0;

			for(int i=len1-1; i>=0; i--)
			{
				int k = arr_len-1-shiftFactor;
				int carry = 0;
				int t1 = (int)(str1[i] - '0');
				for(int j=len2-1; j>=0; j--)
				{
					int t2 = (int)(str2[j] - '0');
					int pdt = t1 * t2 + arr[k] + carry;
					arr[k] = pdt % 10;
					carry = pdt / 10;
					k--;

				}
				if(carry > 0)
				{
					arr[k] = arr[k] + carry;
				}
				shiftFactor++;
			}

			/* cut the trailing zeros */
			int i=0;
			while(arr[i] == 0)
			{
				i++;
			}
			/* all zeros */
			if(i==arr_len)
			{
				return "0";
			}
			else
			{
				string res = "";
				for(; i<arr_len; i++)
				{
					int t = arr[i];
					res = res + to_string(t);
				}
				return res;
			}
		}
	}

	/* 123*456+345-76 */
	void basic_calculator(string &expression)
	{
		/* count all the * , +, - operators */
		int mult_op=0, add_op=0, sub_op=0;
		for(int i=0; i<(int)expression.length(); i++)
		{
			if(expression[i] == '*')
			{
				mult_op++;
			}
			else if(expression[i] == '+')
			{
				add_op++;
			}
			else if(expression[i] == '-')
			{
				sub_op++;
			}
		}

		/* frst execute all multiplication operations bcoz it has highest precedence among '+','-','*' */
		while(mult_op--)
		{
			for(int i=0; i<(int)expression.length(); i++)
			{
				if(expression[i] == '*')
				{
					int op1_end_pos = i-1, op1_start_pos = -1;
					int op2_start_pos = i+1, op2_end_pos = -1;

					/* find out 2nd operand end pos */
					for(int j=i+1; j<(int)expression.length(); j++)
					{
						if(expression[j] == '*' || expression[j] == '+' || expression[j] == '-')
						{
							op2_end_pos = j-1;
							break;
						}
					}
					if(op2_end_pos == -1)
					{
						op2_end_pos = expression.length()-1;
					}
					/* second operand length */
					int operand2_length = (op2_end_pos - op2_start_pos + 1);
					/* trim out the 2nd operand */
					string operand2 = expression.substr(op2_start_pos, operand2_length);

					/* find out 1st operand start pos */
					for(int j=i-1; j>=0; j--)
					{
						if(expression[j] == '*' || expression[j] == '+' || expression[j] == '-')
						{
							op1_start_pos = j+1;
							break;
						}
					}
					if(op1_start_pos == -1)
					{
						op1_start_pos = 0;
					}
					/* 1st operand length */
					int operand1_length = (op1_end_pos - op1_start_pos + 1);
					/* trim out the 1st operand */
					string operand1 = expression.substr(op1_start_pos, operand1_length);

					/* preparing the result */
					string res = "";
					res = multiplication(operand1, operand2);
					int sub_expression_length = (op2_end_pos - op1_start_pos + 1);
					/* a*b+c-d = z+c-d */
					expression.replace(op1_start_pos, sub_expression_length, res);
					break;
				}
			}
		}

		/* Next count all addition and subtraction operator and execute the addition and subtraction 
		in one go since they have the same precdence. But do the operations from Left to Right
		Precedence L -> R */
		int count_add_sub_op = add_op + sub_op;
		while(count_add_sub_op--)
		{
			for(int i=0; i<(int)expression.length(); i++)
			{
				if(expression[i] == '+' || expression[i] == '-')
				{
					int op1_end_pos = i-1, op1_start_pos = -1;
					int op2_start_pos = i+1, op2_end_pos = -1;

					/* find out 2nd operand end pos */
					for(int j=i+1; j<(int)expression.length(); j++)
					{
						if(expression[j] == '*' || expression[j] == '+' || expression[j] == '-')
						{
							op2_end_pos = j-1;
							break;
						}
					}
					if(op2_end_pos == -1)
					{
						op2_end_pos = expression.length()-1;
					}
					/* second operand length */
					int operand2_length = (op2_end_pos - op2_start_pos + 1);
					/* trim out the 2nd operand */
					string operand2 = expression.substr(op2_start_pos, operand2_length);

					/* find out 1st operand start pos */
					for(int j=i-1; j>=0; j--)
					{
						if(expression[j] == '*' || expression[j] == '+' || expression[j] == '-')
						{
							op1_start_pos = j+1;
							break;
						}
					}
					if(op1_start_pos == -1)
					{
						op1_start_pos = 0;
					}
					/* 1st operand length */
					int operand1_length = (op1_end_pos - op1_start_pos + 1);
					/* trim out the 1st operand */
					string operand1 = expression.substr(op1_start_pos, operand1_length);

					/* preparing the result according to addition or subtraction operation */
					string res = "";
					if(expression[i] == '+')
					{
						res = addition(operand1, operand2);
					}
					else if(expression[i] == '-')
					{
						res = subtraction(operand1, operand2);
					}
					
					int sub_expression_length = (op2_end_pos - op1_start_pos + 1);
					/* a*b+c-d = z+c-d */
					expression.replace(op1_start_pos, sub_expression_length, res);
					break;
				}
			}
		}
	}

	string factorial(string str)
	{
		if(str == "0")
		{
			return "1";
		}

		// cout << "Calculating factorial" << endl;
		string res = "1";
		string one = "1";
		while(true)
		{
			res = multiplication(res, str);
			// cout << res << endl;
			str = subtraction(str, one);
			// cout << str << endl;
			if(str == "0")
			{
				break;
			}
		}
		return res;
	}

	string fast_exponentiation(string base, long long int exp)
	{
	    string res = "1";
	     
	    while (exp > 0)
	    {
	        if (exp % 2 == 1)
	        {
	            res = multiplication(res, base);
	        }   
	        exp = exp / 2;
	        base = multiplication(base, base);
	    }
	    return res;
	}

	string normal_exponentiation(string base, string exp)
	{
		string res = "1";
		string one = "1";
		string counter = exp;
		while(true)
		{
			res = multiplication(res, base);
			counter = subtraction(counter, one);
			if(counter == "0")
			{
				break;
			}
		}
		return res;
	}

	long long int calculate_modulus(string n1, long long int n2)
	{
		long long int res = 0;
		for(int i=0; i<(int)(n1.length()); i++)
		{
			long long int temp = (long long int)(n1[i] - '0');
			res = (res*10 + temp) % n2;
		}
		return res;
	}

	long long int gcd(long long int num1, long long int num2)
	{
		if(num2 == 0)
		{
			return num1;
		}
		else
		{
			return gcd(num2, num1 % num2);
		}
	}

	long long int calculate_gcd(string n1, long long int n2)
	{
		if(n1 == "0" && n2 == 0)
		{
			return 0;
		}
		else if(n1 == "0" && n2 != 0)
		{
			return n2;
		}
		else if(n1 != "0" && n2 == 0)
		{
			return stoi(n1);
		}

		long long int num1 = calculate_modulus(n1, n2);
		long long int num2 = n2;
		long long int res = gcd(num1, num2);
		return res;
	}

	string binaryGCD(string a, string b)
	{
		if(b == "0")
		{
			return a;
		}
		if(a == "0")
		{
			return b;
		}
		string commonMultipleOf2 = "1";

		while((a.length()>0 && b.length() > 0) && (a[a.length()-1] == '0' && b[b.length()-1] == '0'))
		{
			commonMultipleOf2 = multiplication(commonMultipleOf2, "2");
			a.pop_back();
			b.pop_back();
		}

		while(a.length() > 0 && a[a.length()-1] == '0')
		{
			a.pop_back();
		}

		while(b.length() != 0)
		{
			while(b.length() > 0 && b[b.length()-1] == '0')
			{
				b.pop_back();
			}
			string temp = subtraction(a, b);
			a=b;
			b=temp;
			if(str1_greater_or_equal_to_str2(b,a) == true)
			{
				string tempSwap = a;
				a = b;
				b = tempSwap;
			}
		}

		string res = multiplication(a, commonMultipleOf2);
		return res;
	}
};

int main()
{
	while(true)
	{
		int operation;
		cin >> operation;

		BigInt obj = BigInt();

		/* Exponentiation */
		if(operation == 1)
		{
			/* Base will be a bigint and exponent will be < 2^63 which means we can use long long int for exponent part */
			string base; 
			long long int exp;
			cin >> base >> exp;
			string fast_exponentiation_res = obj.fast_exponentiation(base, exp);
			cout << fast_exponentiation_res << endl;
		}

		/* GCD */
		else if(operation == 2)
		{
			string n1;
			string n2;
			cin >> n1 >> n2;
			string max_value = "9223372036854775807";

			bool flag_n1 = obj.str1_greater_or_equal_to_str2(max_value, n1);
			bool flag_n2 = obj.str1_greater_or_equal_to_str2(max_value, n2);

			/* both n1 and n2 are in long long int range */
			if(flag_n1 == true && flag_n2 == true)
			{
				string num1 = n2;
				long long int num2 = string_to_int(n1);
				long long int gcd_res = obj.calculate_gcd(num1, num2);
				cout << gcd_res << endl;
			}
			/* n1 is in long long int range, n2 is not in long long int range */
			else if(flag_n1 == true && flag_n2 == false)
			{
				string num1 = n2;
				long long int num2 = string_to_int(n1);
				long long int gcd_res = obj.calculate_gcd(num1, num2);
				cout << gcd_res << endl;
			}
			/* n2 is in long long int range, n1 is not in long long int range */
			else if(flag_n1 == false && flag_n2 == true)
			{
				string num1 = n1;
				long long int num2 = string_to_int(n2);
				long long int gcd_res = obj.calculate_gcd(num1, num2);
				cout << gcd_res << endl;
			}
			/* neither n1 nor n2 is in long long int range */
			else
			{
				string gcd_res = obj.binaryGCD(n1, n2);
				cout << gcd_res << endl;
			}

		}

		/* Factorial */
		else if(operation == 3)
		{
			string str;
			cin >> str;
			string factorial_res = obj.factorial(str);
			cout << factorial_res << endl; 
		}

		/* Calculator */
		else if(operation == 4)
		{
			string expression;
			cin >> expression;
			obj.basic_calculator(expression);
			cout << expression << endl;
		}
		else
		{
			cout << "Wrong Input!!" << endl;
			break;
		}
	}
	
	return 0;
}



// int main()
// {
// 	int operation;
// 	cout << "Enter type of Operation [Exponentiation(1) / GCD(2) / Factorial(3) / Calculator(4)]: ";
// 	cin >> operation;

// 	BigInt obj = BigInt();

// 	/* Exponentiation */
// 	if(operation == 1)
// 	{
// 		/* Base will be a bigint and exponent will be < 2^63 which means we can use long long int for exponent part */
// 		string base; 
// 		long long int exp;
// 		cout << "Enter the base and exponent separated by space: ";
// 		cin >> base >> exp;
// 		string fast_exponentiation_res = obj.fast_exponentiation(base, exp);
// 		cout << "Exponentiation Result = " << fast_exponentiation_res << endl;
// 	}

// 	/* GCD */
// 	else if(operation == 2)
// 	{
// 		string n1;
// 		string n2;
// 		cout << "Enter two numbers separated by space: ";
// 		cin >> n1 >> n2;
// 		string max_value = "9223372036854775807";

// 		bool flag_n1 = obj.str1_greater_or_equal_to_str2(max_value, n1);
// 		bool flag_n2 = obj.str1_greater_or_equal_to_str2(max_value, n2);

// 		/* both n1 and n2 are in long long int range */
// 		if(flag_n1 == true && flag_n2 == true)
// 		{
// 			string num1 = n2;
// 			long long int num2 = string_to_int(n1);
// 			long long int gcd_res = obj.calculate_gcd(num1, num2);
// 			cout << "GCD Result = " << gcd_res << endl;
// 		}
// 		/* n1 is in long long int range, n2 is not in long long int range */
// 		else if(flag_n1 == true && flag_n2 == false)
// 		{
// 			string num1 = n2;
// 			long long int num2 = string_to_int(n1);
// 			long long int gcd_res = obj.calculate_gcd(num1, num2);
// 			cout << "GCD Result = " << gcd_res << endl;
// 		}
// 		/* n2 is in long long int range, n1 is not in long long int range */
// 		else if(flag_n1 == false && flag_n2 == true)
// 		{
// 			string num1 = n1;
// 			long long int num2 = string_to_int(n2);
// 			long long int gcd_res = obj.calculate_gcd(num1, num2);
// 			cout << "GCD Result = " << gcd_res << endl;
// 		}
// 		/* neither n1 nor n2 is in long long int range */
// 		else
// 		{
// 			string gcd_res = obj.gcd_by_modulus(n1, n2);
// 			cout << "GCD Result = " << gcd_res << endl;
// 		}

		
// 		// long long int n2;
// 		// cout << "Enter two numbers separated by space: ";
// 		// cin >> n1 >> n2;
// 		// long long int gcd_res = obj.calculate_gcd(n1, n2);
// 		// // string gcd_res = obj.gcd_by_modulus(n1, n2);
// 		// cout << "GCD Result = " << gcd_res << endl;
// 	}

// 	/* Factorial */
// 	else if(operation == 3)
// 	{
// 		string str;
// 		cout << "Enter the number: ";
// 		cin >> str;
// 		string factorial_res = obj.factorial(str);
// 		cout << "Factorial Result = " << factorial_res << endl; 
// 	}

// 	/* Calculator */
// 	else if(operation == 4)
// 	{
// 		string expression;
// 		cout << "Enter the Expression: ";
// 		cin >> expression;
// 		obj.basic_calculator(expression);
// 		cout << "Calculator Result = " << expression << endl;
// 	}
// 	// else if(operation == 5)
// 	// {
// 	// 	string str1, str2;
// 	// 	cout << "Enter two numbers: ";
// 	// 	cin >> str1 >> str2;
// 	// 	string modulus_res = obj.modulus_by_division(str1, str2);
// 	// 	cout << "Modulus Result = " << modulus_res << endl;
// 	// }
// 	else
// 	{
// 		cout << "Wrong Input!!" << endl;
// 	}


// 	// string str1, str2;
// 	// cin >> str1 >> str2;
	

// 	// string addition_res = obj.addition(str1, str2);
// 	// cout << str1 << " + " << str2 << " = " << addition_res << endl;

// 	// string subtraction_res = obj.subtraction(str1, str2);
// 	// cout << str1 << " - " << str2 << " = " << subtraction_res << endl;

// 	// string multiplication_res = obj.multiplication(str1, str2);
// 	// cout << str1 << " * " << str2 << " = " << multiplication_res << endl;
	

// 	// string normal_exponentiation_res = obj.normal_exponentiation(str1, str2);
// 	// cout << str1 << "^" << str2 << " = " << normal_exponentiation_res << endl;


// 	return 0;
// }