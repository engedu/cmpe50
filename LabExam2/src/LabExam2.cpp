/*
 * 1.cpp
 *
 *  Created on: Mar 17, 2015
 *      Author: Yutao Hou
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void exercise_1();
void exercise_2();
string digit[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
string num[] = {"zero", "one", "two", "three", "four", "five", "six", "seven",
		"eight", "nine"};
void output(ostream& out, string line);

void exercise_3();
class Movie
{
public:
	Movie();
	Movie(string n, string r);
	void set_name(string n);
	void set_rating(string r);
	string get_name();
	string get_rating();
	void addRating(int rate);
	double getAverage();
	void output(ostream& out);

private:
	string name;
	string rating;
	int rate1_number;
	int rate2_number;
	int rate3_number;
	int rate4_number;
	int rate5_number;

};


int main() {
	exercise_1();
	return 0;
}

void exercise_1()
{
	while (true) {
		cout << "Select an exercise: (1) execute exercise 2; (2) execute exercise 3; (3) exit\n";
		int selection = 0;
		cin >> selection;
		if (selection ==  1) {
			exercise_2();
		} else if (selection == 2) {
			exercise_3();
		} else if (selection == 3) {
			break;
		}
	}
}

void exercise_2() {
	ifstream fin;
	ofstream fout;
	fin.open("input2.txt");
	if (fin.fail()) {
		cout << "open file failed\n";
		exit(1);

	}

	fout.open("output2.txt");
	if (fout.fail()) {
		cout << "create file output failed\n";
		exit(1);

	}


	while (!fin.eof()) {
		string line;
		getline(fin, line);
		while (true) {
			bool found = false;
			for (int i = 0; i < 10; i++) {
				int pos = -1;
//				size_t p;
//				npos;
				pos = line.find(digit[i]);

				if (pos >= 0) {
					line.replace(pos, 1, num[i]);
					found = true;
				}


			}

			if (!found) {
				break;
			}

		}
		output(cout, line);
		output(fout, line);

	}

	fin.close();
	fout.close();
}

void output(ostream& out, string line) {
	out << line << endl;
}

void exercise_3() {
	Movie movie1("movie1", "PG"), movie2("movie2", "PG-13");
	movie1.addRating(100);
	movie1.addRating(1);
	movie1.addRating(2);
	movie1.addRating(3);
	movie1.addRating(4);
	movie1.addRating(5);
	movie1.addRating(5);

	movie2.addRating(100);
	movie2.addRating(1);
	movie2.addRating(2);
	movie2.addRating(3);
	movie2.addRating(4);
	movie2.addRating(5);

	movie1.output(cout);
	movie2.output(cout);

}

Movie::Movie() :
		rate1_number(0),
		rate2_number(0),
		rate3_number(0),
		rate4_number(0),
		rate5_number(0)
{

}

Movie::Movie(string n, string r) :
		rate1_number(0),
		rate2_number(0),
		rate3_number(0),
		rate4_number(0),
		rate5_number(0)
{
	name = n;
	rating = r;


}

void Movie::set_name(string n)
{
	name = n;
}

void Movie::set_rating(string r)
{
	rating = r;
}


string Movie::get_name()
{
	return name;
}

string Movie::get_rating()
{
	return rating;

}
void Movie::addRating(int rate)
{
	if (rate < 1 || rate > 5)
	{
		cout << "Movie " << name << "'s rate can not be set to " << rate << ", rate should be between 1 and 5!!!\n";
		return;
	}
	switch (rate) {
	case 1:
		rate1_number++;
		break;
	case 2:
		rate2_number++;
		break;
	case 3:
		rate3_number++;
		break;
	case 4:
		rate4_number++;
		break;
	case 5:
		rate5_number++;
		break;
	}
}

double Movie::getAverage()
{
	return (static_cast<double>(rate1_number)
			+ rate2_number * 2
			+ rate3_number * 3
			+ rate4_number * 4
			+ rate5_number * 5
			) /
			(rate1_number
			+ rate2_number
			+ rate3_number
			+ rate4_number
			+ rate5_number
			);

}

void Movie::output(ostream& out)
{
	out.setf(ios::fixed);
	out.setf(ios::showpoint);
	out.precision(2);

	out << "name: " + name
			+ "    MPAA rating: " + rating
			+ "    average rating: "
			<< getAverage() << endl;

}

/*
input2.txt:
The price of the cup is 4 dollars. But it's on sale today
at 2 for 6 dollars.
If you buy more, you can get 3 for 8 dollars.

output2.txt:
The price of the cup is four dollars. But it's on sale today
at two for six dollars.
If you buy more, you can get three for eight dollars.

console outout:
Select an exercise: (1) execute exercise 2; (2) execute exercise 3; (3) exit
1
The price of the cup is four dollars. But it's on sale today
at two for six dollars.
If you buy more, you can get three for eight dollars.
Select an exercise: (1) execute exercise 2; (2) execute exercise 3; (3) exit
6
Select an exercise: (1) execute exercise 2; (2) execute exercise 3; (3) exit
2
Movie movie1's rate can not be set to 100, rate should be between 1 and 5!!!
Movie movie2's rate can not be set to 100, rate should be between 1 and 5!!!
name: movie1    MPAA rating: PG    average rating: 3.33
name: movie2    MPAA rating: PG-13    average rating: 3.00
Select an exercise: (1) execute exercise 2; (2) execute exercise 3; (3) exit
3


 */





