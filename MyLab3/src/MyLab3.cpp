/*
 * MyLab3.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: yutao
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;
const int SINGLE_ARRAY_SIZE = 50;

void exercise_1();
int count_char(ifstream& in_stream);
char upper_case(char ch);

void exercise_2();
void read_integers(int a[], int max_size, int& real_size);
void fill_array_with_file(ifstream& in_stream, int array[], int size,
		int& real_size);
void sort(int a[], int size);
void swap(int a[], int size, int index_1, int index_2);
void swap(int& a, int& b);
void count_array(int array[], int size, int c_array[], int& c_array_real_size);
void print_count(int c_array[], int c_array_size, int array[], int size, ofstream& fout);

void exercise_3();
void read_write(ifstream& fin1, ifstream& fin2, ofstream& fout);
int count_int(ifstream& in_stream);
void merge(int r[], int r_size, int a[], int a_size, int b[], int b_size);

void print_array(const int a[], int size);

int main()
{
//	exercise_1();
	exercise_2();
//	exercise_3();

	return 0;
}

void exercise_1()
{
	ifstream in_stream;
	ofstream out_stream;

	in_stream.open("LabInput3-1.txt");

	if (in_stream.fail())
	{
		cout << "Input file open fail" << endl;
		exit(1);
	}

	out_stream.open("LabInput3-1-output.txt");
	if (out_stream.fail())
	{
		cout << "Output file open fail" << endl;
		exit(1);
	}

	int l = count_char(in_stream);
	cout << "char amount: " << l << endl;
	char array[l];
	int i = 0;
	while (i < l && in_stream >> array[i])
	{
		i++;
	}

	for (i = 0; i < l; i++)
	{
		out_stream << upper_case(array[i]) << endl;
		cout << upper_case(array[i]) << endl;
	}

	in_stream.close();
	out_stream.close();

}

int count_char(ifstream& in_stream)
{
	cout << "count_char..." << endl;
	int count = 0;
	char next;
	while (in_stream >> next)
	{
		count++;
	}
	in_stream.clear();
	in_stream.seekg(0, ios::beg);

	return count;
}

int count_int(ifstream& in_stream)
{
	cout << "count_int..." << endl;
	int count = 0;
	int next;
	while (in_stream >> next)
	{
		count++;
	}
	in_stream.clear();
	in_stream.seekg(0, ios::beg);

	return count;
}

char upper_case(char ch)
{

	if (ch >= 'a' && ch <= 'z')
	{
		return ch - 'a' + 'A';
	}

	return ch;
}

void exercise_2()
{
	int array[SINGLE_ARRAY_SIZE];
	int c_array[SINGLE_ARRAY_SIZE];
	int size = 0;
	int c_array_size;
	string file_name;

	char ch;

	cout << "Select a option to execute." << endl;
	cout << "(1) input with keyboard" << endl;
	cout << "(2) input with file" << endl;
	cout << "(3) end the program" << endl;
	cout << "Please input 1, 2 or 3:" << endl;

	cin >> ch;
	if (ch == '3')
	{
		return;
	}
	else if (ch == '1')
	{
		cout << "Please input up to " << SINGLE_ARRAY_SIZE
				<< " integers to Array a" << endl;
		cout << "-1 means end input." << endl;
		read_integers(array, SINGLE_ARRAY_SIZE, size);

	}
	else if (ch == '2')
	{
		cout << "Input file name: " << endl;
		cin >> file_name;
		ifstream in_stream;
		in_stream.open(file_name.c_str());
		if (in_stream.fail())
		{
			cout << "Input file open fail" << endl;
			exit(1);
		}

		fill_array_with_file(in_stream, array, SINGLE_ARRAY_SIZE, size);
//		print_array(array, size);
//		cout << size << endl;
		in_stream.close();
	}
	else
	{
		cout << "Please input a valid number 1, 2 or 3" << endl;
	}

	sort(array, size);
//	print_array(array, size);

	count_array(array, size, c_array, c_array_size);
//	print_array(c_array, c_array_size);

	ofstream fout;
	fout.open("LabInput3-2-output.txt");
	if (fout.fail())
	{
		cout << "Output file open fail" << endl;
		exit(1);
	}

	print_count(c_array, c_array_size, array, size, fout);

	fout.close();

}

void sort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = a[i], min_index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				min_index = j;
			}
		}

		swap(a, size, i, min_index);
	}

}

void swap(int a[], int size, int index_1, int index_2)
{
	// do not need to swap
	if (index_1 == index_2)
	{
		return;
	}

	if (index_1 >= size || index_2 >= size)
	{
		return;
	}

	if (index_1 < 0 || index_2 < 0)
	{
		return;
	}

	swap(a[index_1], a[index_2]);

}

void swap(int& a, int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void count_array(int array[], int size, int c_array[], int& c_array_real_size)
{
	int l = 0;
	for (int i = 0; i < size; i++)
	{
		bool exist = false;
		for (int j = 0; j < l; j++)
		{
			if (c_array[j] == array[i])
			{
				exist = true;
				break;
			}

		}

		if (!exist)
		{
			c_array[l++] = array[i];
		}
	}
	c_array_real_size = l;
}

void read_integers(int a[], int max_size, int& real_size)
{

	int input, i;
	for (i = 0; i < max_size; i++)
	{
		cin >> input;
		if (cin.good())
		{
			if (input == -1)
			{
				real_size = i;
				return;
			}
			else
			{
				a[i] = input;
			}
		}
		else
		{
			cin.clear();
			cout << "Please input a number" << endl;
		}
	}
	real_size = i;
}

void fill_array_with_file(ifstream& in_stream, int array[], int size,
		int& real_size)
{
	int i = 0;
	while (i < size && !in_stream.eof())
	{
		in_stream >> array[i];
		i++;
	}
	real_size = i;
//	cout << real_size << endl;
}

void exercise_3()
{
	ifstream fin1;
	ifstream fin2;
	ofstream fout;

	fin1.open("LabInput3-3-1.txt");
	if (fin1.fail())
	{
		cout << "Input file1 open fail" << endl;
		exit(1);
	}

	fin2.open("LabInput3-3-2.txt");
	if (fin2.fail())
	{
		cout << "Input file2 open fail" << endl;
		exit(1);
	}

	fout.open("LabInput3-3-3.txt");
	if (fout.fail())
	{
		cout << "Output file open fail" << endl;
		exit(1);
	}

	read_write(fin1, fin2, fout);


	fin1.close();
	fin2.close();
	fout.close();

}

void read_write(ifstream& fin1, ifstream& fin2, ofstream& fout)
{
	int i = 0;
	int l1 = count_int(fin1);
	cout << "amount: " << l1 << endl;
	int array1[l1];

	while (i < l1 && fin1 >> array1[i])
	{
		i++;
	}

	print_array(array1, l1);

	int l2 = count_int(fin2);
	cout << "amount: " << l2 << endl;
	int array2[l2];
	i = 0;
	while (i < l2 && fin2 >> array2[i])
	{
		i++;
	}
	print_array(array2, l2);

	int l3 = l1 + l2;
	int r[l3];
	merge(r, l3, array1, l1, array2, l2);
	print_array(r, l3);

	for (i = 0; i < l3; i++) {
		fout << setw(i) << r[i] << endl;
	}

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


void print_count(int c_array[], int c_array_size, int array[], int size, ofstream& fout)
{

	cout << "N" << setw(8) << "Count" << endl;
	fout << "N" << setw(8) << "Count" << endl;
	for (int i = c_array_size - 1; i >= 0; i--)
	{
		int n = c_array[i];
		int count = 0;

		for (int j = 0; j < size; j++)
		{
			if (array[j] == n)
			{
				count++;
			}

		}
		cout << n << setw(6) << count << endl;
		fout << n << setw(6) << count << endl;

	}

}

void print_array(const int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}
