//============================================================================
// Name        : MyLab2.cpp
// Author      : Yutao Hou
//============================================================================

#include <iostream>
using namespace std;

void exercise_1();
double add(double d1, double d2);
int add(int m, int n);
void add(char array1[], char array2[]);

void exercise_2();
void read_letter();

void exercise_3();
void calculate_grade();

int main()
{

	exercise_1();

	exercise_2();

	exercise_3();

	return 0;
}

void exercise_1()
{
	string str_yes = "yes";
	string yes_no;
	cout << "Would you like add two doubles?(yes/no)" << endl;
	cin >> yes_no;
	if (!yes_no.empty())
	{
		if (yes_no.compare(str_yes) == 0)
		{
			double d1, d2;
			cout << "Please input the first double:" << endl;
			cin >> d1;

			cout << "Please input the second double:" << endl;
			cin >> d2;

			cout << "The result is : " << add(d1, d2) << endl;

		}
	}

	yes_no = "";

	cout << "Would you like add two integers?(yes/no)" << endl;
	cin >> yes_no;
	if (!yes_no.empty())
	{
		if (yes_no.compare(str_yes) == 0)
		{
			int m, n;
			cout << "Please input the first integer:" << endl;
			cin >> m;

			cout << "Please input the second integer:" << endl;
			cin >> n;

			cout << "The result is : " << add(m, n) << endl;

		}
	}

	yes_no = "";

	cout << "Would you like add two character arrays?(yes/no)" << endl;
	cin >> yes_no;
	if (!yes_no.empty())
	{
		if (yes_no.compare(str_yes) == 0)
		{
			// if user input more than 11 chars, application will crash.
			char array1[12], array2[12];
			cout << "Please input the first character array:" << endl;
			cin >> array1;

			cout << "Please input the second character array:" << endl;
			cin >> array2;

			add(array1, array2);

		}
	}
}

double add(double d1, double d2)
{
	return d1 + d2;

}

int add(int m, int n)
{
	return m + n;
}

void add(char array1[], char array2[])
{
	cout << array1 << endl;
	cout << array2 << endl;
}

void exercise_2()
{
	read_letter();
}

void read_letter()
{
	cout << "Please input some letters (\".\" means ending)" << endl;
	char ch, array[10];
	int size = 0;
	cin >> ch;
	while (ch != '.')
	{
		array[size] = ch;
		size++;

		// if size >= 10, exit
		if (size >= 10)
		{
			break;
		}
		cin >> ch;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		cout << array[i];
	}
	cout << endl;
}

void exercise_3()
{
	calculate_grade();

}

void calculate_grade()
{
	double val[2][5];

	cout << "Please enter five HW scores [0 - 100]:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> val[0][i];

		// check value
		if (val[0][i] < 0)
		{
			val[0][i] = 0;
		}

		if (val[0][i] > 100)
		{
			val[0][i] = 100;
		}
	}

	cout << "Please enter five Lab scores [0 - 100]:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> val[1][i];

		// check value
		if (val[1][i] < 0)
		{
			val[1][i] = 0;
		}

		if (val[1][i] > 100)
		{
			val[1][i] = 100;
		}
	}

	double best_hw = 0;
	double worst_hw = 100;
	double avg_hw = 0;
	/*
	 Pseudo-code
	 if val[0][i] > best_hw, set best_hw val[0][i]
	 if val[0][i] < worst_hw, set worst_hw val[0][i]

	 sum up the scores in loop
	 */
	for (int i = 0; i < 5; i++)
	{
		avg_hw = avg_hw + val[0][i];
		if (val[0][i] > best_hw)
		{
			best_hw = val[0][i];
		}
		if (val[0][i] < worst_hw)
		{
			worst_hw = val[0][i];
		}
	}
	avg_hw = avg_hw / 5;

	double best_lab = 0;
	double worst_lab = 100;
	double avg_lab = 0;
	/*
	 if val[0][i] > best_lab, set best_lab val[0][i]
	 if val[0][i] < worst_lab, set worst_lab val[0][i]

	 sum up the scores in loop
	 */
	for (int i = 0; i < 5; i++)
	{
		avg_lab = avg_lab + val[1][i];
		if (val[0][i] > best_lab)
		{
			best_lab = val[1][i];
		}
		if (val[0][i] < worst_lab)
		{
			worst_lab = val[1][i];
		}
	}
	avg_lab = avg_lab / 5;

	double avg[5];
	double overall;

	for (int i = 0; i < 5; i++)
	{
		avg[i] = (val[0][i] + val[1][i]) / 2;
		overall = overall + avg[i];
	}
	overall = overall / 5;

	bool is_passed;
	string msg;

	if (avg_hw >= 50 && avg_lab >= 50)
	{
		is_passed = true;
		msg = "Congratulations! You passed the class";

	}
	else
	{
		is_passed = false;
		if (avg_hw < 50 && avg_lab < 50)
		{
			msg =
					"I'm sorry to inform you that you failed the class, because your performances in HW and Lab were <50%. Try again next semester.";
		}
		else if (avg_hw < 50)
		{
			msg =
					"I'm sorry to inform you that you failed the class, because your performance in HW was <50%. Try again next semester.";
		}
		else
		{
			msg =
					"I'm sorry to inform you that you failed the class, because your performance in Lab was <50%. Try again next semester.";
		}
	}

	cout.setf(ios::fixed); 		//for fixed point notation
	cout.setf(ios::showpoint);	// for showing the decimal points
	cout.precision(2);		// for showing two decimal places

	cout << "\t";
	for (int i = 0; i < 5; i++)
	{
		cout << i;
		cout.width(8);		// set the output width to be 8
	}
	cout << endl;

	cout << "\t";
	for (int i = 0; i < 33; i++)
	{
		cout << "*";
	}
	cout << endl;

	cout << "HW ";
	for (int i = 0; i < 5; i++)
	{
		cout.width(8);
		cout << val[0][i];
	}

	cout << "\t";
	cout << "BEST HW: " << best_hw << " WORST HW: " << worst_hw << " AVG HW: "
			<< avg_hw;
	cout << endl;

	cout << "LAB";
	for (int i = 0; i < 5; i++)
	{
		cout.width(8);
		cout << val[1][i];
	}
	cout << "\t";
	cout << "BEST LAB: " << best_lab << " WORST LAB: " << worst_lab
			<< " AVG LAB: " << avg_lab;
	cout << endl;

	cout << "AVG";
	for (int i = 0; i < 5; i++)
	{
		cout.width(8);
		cout << avg[i];
	}
	cout << "\t";
	cout << "Overall : " << overall;
	cout << endl;

	cout << msg << endl;

}
