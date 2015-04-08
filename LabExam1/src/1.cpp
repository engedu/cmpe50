//============================================================================
// Name        : LabExam1.cpp
// Author      : Yutao Hou
// Version     :
// Copyright   : 
//============================================================================

#include <iostream>
using namespace std;

const int SINGLE_ARRAY_SIZE = 10;
void exercise_2();
void month_prompt(int i);

void exercise_3();
void read_integers(int a[], int max_size, int& real_size);
void sort(int a[], int size);
void swap(int a[], int size, int index_1, int index_2);
void swap(int& a, int& b);
void merge(int r[], int r_size, int a[], int a_size, int b[], int b_size);
void print_array(const int a[], int size);

void read_i() {
	int a[10], input, i = 0;
	while (i < 10) {
		cin >> input;
		if (cin.good()) {
			a[i] = input;
			i++;
		} else {
			cin.clear();
			cout << "input" << endl;
		}
	}

}

int main() {
//	read_i();

	// infinite loop read user input, until get 3
	while (true) {
		char ch;

		cout << "Select a program to execute." << endl;
		cout << "(1) execute the exercise 2" << endl;
		cout << "(2) execute the exercise 3" << endl;
		cout << "(3) end the program" << endl;
		cout << "Please input 1, 2 or 3:" << endl;

		cin >> ch;
		if (ch == '3') {
			break;
		} else if (ch == '1') {
			exercise_2();

		} else if (ch == '2') {
			exercise_3();
		} else {
			cout << "Please input a valid number 1, 2 or 3" << endl;
		}
		cout << endl;
	}

	return 0;
}

void exercise_2() {
	double month_expenses[12], annual_expense, monthly_avg, high, low;
	// string month_names[12] = {"JAN", "Feb"};

	annual_expense = 0;
	monthly_avg = 0;

	month_prompt(1);
	cin >> month_expenses[0];
	high = month_expenses[0];
	low = month_expenses[0];
	annual_expense += month_expenses[0];

	// loop to read month expenses, calculate highest, lowest, annual expense.
	for (int i = 1; i < 12; i++) {
		month_prompt(i + 1);
		cin >> month_expenses[i];
		if (month_expenses[i] > high) {
			high = month_expenses[i];
		}

		if (month_expenses[i] < low) {
			low = month_expenses[i];
		}
		annual_expense += month_expenses[i];
	}

	monthly_avg = annual_expense / 12;

	cout << "annual grocery expense: " << annual_expense << endl;
	cout << "highest grocery expense: " << high << endl;
	cout << "lowest grocery expense: " << low << endl;
	cout << "average monthly expense: " << monthly_avg <<endl;

}

void month_prompt(int i) {
	if (i == 1) {
		cout << "Please input the First Month expense" << endl;
	} else if (i == 2) {
		cout << "Please input the Second Month expense" << endl;
	} else if (i == 3) {
		cout << "Please input the Third Month expense" << endl;
	} else {
		cout << "Please input the "<< i << "th Month expense" << endl;
	}
}
void exercise_3() {
	int a[SINGLE_ARRAY_SIZE], b[SINGLE_ARRAY_SIZE], r[SINGLE_ARRAY_SIZE * 2];

	int a_size = 0, b_size = 0;

	cout << "Please input up to " << SINGLE_ARRAY_SIZE << " integers to Array a" << endl;
	cout << "-1 means end input." << endl;
	read_integers(a, SINGLE_ARRAY_SIZE, a_size);

	cout << "Please input up to " << SINGLE_ARRAY_SIZE << " integers to Array b" << endl;
	cout << "-1 means end input." << endl;
	read_integers(b, SINGLE_ARRAY_SIZE, b_size);

	cout << "Array a is : " << endl;
	print_array(a, a_size);
	cout << "Array b is : " << endl;
	print_array(b, b_size);

	sort(a, a_size);
	sort(b, b_size);

	merge(r, a_size + b_size, a, a_size, b, b_size);

	cout << "merged array is: " << endl;
	print_array(r, a_size + b_size);

}

void read_integers(int a[], int max_size, int& real_size) {

	int input, i;
	for (i = 0; i < max_size; i++) {
		cin >> input;
		if (cin.good()) {
			if (input == -1) {
				real_size = i;
				return;
			} else {
				a[i] = input;
			}
		} else {
			cin.clear();
			cout << "Please input a number" << endl;
		}
	}
	real_size = i;
}

void sort(int a[], int size) {
	for (int i = 0; i < size; i++) {
		int min = a[i], min_index = i;
		for (int j = i + 1; j < size; j++) {
			if (a[j] < min) {
				min = a[j];
				min_index = j;
			}
		}

		swap(a, size, i, min_index);
	}

}

void swap(int a[], int size, int index_1, int index_2) {
	// do not need to swap
	if (index_1 == index_2) {
		return;
	}

	if (index_1 >= size || index_2 >= size) {
		return;
	}

	if (index_1 < 0 || index_2 < 0) {
		return;
	}

	swap(a[index_1], a[index_2]);

}

void swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void merge(int r[], int r_size, int a[], int a_size, int b[], int b_size) {
	int i = 0, j = 0, k = 0;

	// pick the smaller one from array a and b, append it to array r;
	while (i < r_size && j < a_size && k < b_size) {
		if (a[j] < b[k]) {
			r[i] = a[j];
			j++;
		} else {
			r[i] = b[k];
			k++;
		}
		i++;
	}

	// check remaining elements in array a, append them to array r;
	while (i < r_size && j < a_size) {
		r[i++] = a[j++];
	}

	// check remaining elements in array b, append them to array r;
	while (i < r_size && k < b_size) {
		r[i++] = b[k++];
	}
}

void print_array(const int a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;
}
/*
output:

Select a program to execute.
(1) execute the exercise 2
(2) execute the exercise 3
(3) end the program
Please input 1, 2 or 3:
4
Please input a valid number 1, 2 or 3

Select a program to execute.
(1) execute the exercise 2
(2) execute the exercise 3
(3) end the program
Please input 1, 2 or 3:
1
Please input the First Month expense
1
Please input the Second Month expense
3
Please input the Third Month expense
5
Please input the 4th Month expense
6
Please input the 5th Month expense
7
Please input the 6th Month expense
4
Please input the 7th Month expense
2
Please input the 8th Month expense
5
Please input the 9th Month expense
6
Please input the 10th Month expense
12
Please input the 11th Month expense
45
Please input the 12th Month expense
67
annual grocery expense: 163
highest grocery expense: 67
lowest grocery expense: 1
average monthly expense: 13.5833

Select a program to execute.
(1) execute the exercise 2
(2) execute the exercise 3
(3) end the program
Please input 1, 2 or 3:
2
Please input up to 10 integers to Array a
-1 means end input.
1
7
2
-1
Please input up to 10 integers to Array b
-1 means end input.
3
6
0
-1
Array a is :
1  7  2
Array b is :
3  6  0
merged array is:
0  1  2  3  6  7

Select a program to execute.
(1) execute the exercise 2
(2) execute the exercise 3
(3) end the program
Please input 1, 2 or 3:
2
Please input up to 10 integers to Array a
-1 means end input.
1
5
6
4
2
8
3
7
4
10
Please input up to 10 integers to Array b
-1 means end input.
45
23
1
2
7
4
9
2
7
3
Array a is :
1  5  6  4  2  8  3  7  4  10
Array b is :
45  23  1  2  7  4  9  2  7  3
merged array is:
1  1  2  2  2  3  3  4  4  4  5  6  7  7  7  8  9  10  23  45

Select a program to execute.
(1) execute the exercise 2
(2) execute the exercise 3
(3) end the program
Please input 1, 2 or 3:
3


*/
