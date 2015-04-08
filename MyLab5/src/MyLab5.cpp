#include <iostream>
#include <fstream>
using namespace std;

// Exercise 1
class StudentRecord
{
private:
	double quiz_1;
	double quiz_2;
	double midterm;
	double final_exam;
	double average_score;

public:
	StudentRecord();
	// Default Instructor
	// Initialize all the members to 0.0

	void set_quiz_1(double q1);
	double get_quiz_1();

	void set_quiz_2(double q2);
	double get_quiz_2();

	void set_midterm(double mid);
	double get_midterm();

	void set_final_exam(double final);
	double get_final_exam();

	void set_average_score(double average);
	double get_average_score();

	void calculate_average_score();

	void output(ostream& outs);

};

void exercise_1();

// Exercise 2
class CounterType
{
private:
	int count;

public:
	CounterType();
	// Default Instructor
	// Initialize count to 0

	CounterType(int c);
	// Initialize count to c

	void increase();
	// increase the count by 1

	void decrease();
	// decrease the count by 1

	int get_count();

	void output(ostream& outs);

};

void exercise_2();

int main()
{
	exercise_1();
	exercise_2();
	return 0;
}

void exercise_1() {
	StudentRecord record;
	cout << "Student record using default constructor:\n";
	record.output(cout);

	double input = 0.0;
	cout << "Input a student record:\n";
	cout << "Input quiz 1 score(0~10):\n";
	cin >> input;
	record.set_quiz_1(input);

	cout << "Input quiz 2 score(0~10):\n";
	cin >> input;
	record.set_quiz_2(input);

	cout << "Input midterm score(0~100):\n";
	cin >> input;
	record.set_midterm(input);

	cout << "Input final exam score(0~100):\n";
	cin >> input;
	record.set_final_exam(input);

	cout << "Input weighted average numeric score(0~100):\n";
	cin >> input;
	record.set_average_score(input);

	cout << "Student record after set:\n";
	record.output(cout);

	record.calculate_average_score();
	cout << "Student record after calculate:\n";
	record.output(cout);
}

StudentRecord::StudentRecord() : quiz_1(0), quiz_2(0), midterm(0), final_exam(0), average_score(0)
{

}

void StudentRecord::set_quiz_1(double q1)
{
	quiz_1 = q1;
}

void StudentRecord::set_quiz_2(double q2)
{
	quiz_2 = q2;
}

void StudentRecord::set_midterm(double mid)
{
	midterm = mid;
}

void StudentRecord::set_final_exam(double final)
{
	final_exam = final;
}

void StudentRecord::set_average_score(double average)
{
	average_score = average;
}

void StudentRecord::calculate_average_score()
{
	average_score = (quiz_1 + quiz_2) / 10 * 100 / 2 * 0.25 + midterm * 0.25 + final_exam * 0.5;
}

void StudentRecord::output(ostream& outs)
{
	outs.setf(ios::fixed);
	outs.setf(ios::showpoint);
	outs.precision(2);

	outs << "quiz 1: " << quiz_1 << endl;
	outs << "quiz 2: " << quiz_2 << endl;
	outs << "midterm: " << midterm << endl;
	outs << "final exam: " << final_exam << endl;
	outs << "average score: " << average_score << endl;

}


void exercise_2() {

	cout << "\nExercise 2\n";
	cout << "declare counter_1 with count = 0, counter_2 with count = 10\n";
	CounterType counter_1, counter_2(10);

	cout << "\ntest counter_1\n";
	cout << "increase counter_1 twice, then counter_1.";
	counter_1.increase();
	counter_1.increase();
	counter_1.output(cout);

	cout << "decrease once, then counter_1.";
	counter_1.decrease();
	counter_1.output(cout);

	cout << "\ntest counter_2\n";
	cout << "increase counter_2 twice, then counter_2.";
	counter_2.increase();
	counter_2.increase();
	counter_2.output(cout);

	cout << "decrease once, then counter_2.";
	counter_2.decrease();
	counter_2.output(cout);

	cout << "\ntest negative value\n";
	cout << "declare a CounterType with count = -1\n";
	counter_1 = CounterType(-1);
	cout << "decrease when count = 0\n";
	counter_1.decrease();

	cout << "\ntest increase overflow...\n";
	for (long i = 0; i < 10000000000000000L; i++) {
		counter_1.increase();
		if (counter_1.get_count() == 0) {
			cout << "increased " << i + 1 << " times" << endl;
			break;
		}
	}
}

CounterType::CounterType() : count(0)
{

}

CounterType::CounterType(int c)
{
	if (c < 0)
	{
		cout << "Count cannot be negative. set it to 0\n";
		c = 0;
//		exit(1);
	}
	count = c;
}

void CounterType::increase()
{
	count++;
	// overflow
	if (count < 0)
	{
		cout << "Count cannot be negative. set it to 0\n";
		count = 0;
//		exit(1);
	}
}

void CounterType::decrease()
{
	count--;
	if (count < 0)
	{
		cout << "Count cannot be negative. set it to 0\n";
		count = 0;
//		exit(1);
	}
}

int CounterType::get_count()
{
	return count;
}

void CounterType::output(ostream& outs)
{
	outs << "count: " << count << endl;
}
/* output Exercise 1:
Student record using default constructor:
quiz 1: 0.00
quiz 2: 0.00
midterm: 0.00
final exam: 0.00
average score: 0.00
Input a student record:
Input quiz 1 score(0~10):
8
Input quiz 2 score(0~10):
9
Input midterm score(0~100):
80
Input final exam score(0~100):
90
Input weighted average numeric score(0~100):
60
Student record after set:
quiz 1: 8.00
quiz 2: 9.00
midterm: 80.00
final exam: 90.00
average score: 60.00
Student record after calculate:
quiz 1: 8.00
quiz 2: 9.00
midterm: 80.00
final exam: 90.00
average score: 86.25


output Exercise 2:
declare counter_1 with count = 0, counter_2 with count = 10

test counter_1
increase counter_1 twice, then counter_1.count: 2
decrease once, then counter_1.count: 1

test counter_2
increase counter_2 twice, then counter_2.count: 12
decrease once, then counter_2.count: 11

test negative value
declare a CounterType with count = -1
Count cannot be negative. set it to 0
decrease when count = 0
Count cannot be negative. set it to 0

test increase overflow...
Count cannot be negative. set it to 0
increased 2147483648 times


 */







