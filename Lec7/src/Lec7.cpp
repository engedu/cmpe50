//============================================================================
// Name        : Lec7.cpp
// Author      : Yutao Hou
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	double dval = 7.985;
	cout.precision(2);
	cout << dval; //7.99 round up

	double dval2 = 3456.45;
	cout.precision(1);
	cout << dval2; // 3456.5

	/*
	#include <iomanip>
	manipulator setw
	only affect the next cout
	*/
	cout << "Start";

	// setprecision
	cout << setw(5) << dval << setprecision(1) << setw(8) << dval2;

	/*
	stream names as arguments
	must be call-by-reference
	void make_neat(ifstream& messy_file, ofstream& neat_file);
	 */

	/*
	The End of the file
	textedit hidden <CR> <linefeed> <eof>
	while (in_stream >> next) {
	}
	*/
	double next, sum = 0;
	ifstream in_stream;
	in_stream.open("in");
	int count = 0;
	while(in_stream >> next) {
		sum += next;
		count++;
	}

	/*
	the end of console input
	 */
	int next_c;
	cin >> next_c;
	while (next_c > 0) {
		cin >> next_c;
	}

	/*
	default right alignment
	 */

	/*
	 * close file later.
	 */

	/*
	 * character io
	 * '1', '0'
	 *
	 */
	char c;
	c = '1';
	c = 1;
	// ASCII American Standard Code for Information Interchange
	char array[10] = "55";
	/*
	 * Do not perform automatic conversions
	 * member function get
	 *
	 */
//	char c;
	cin.get(c); // instead of cin >> c;

	/*
	 * char c;
	 * while() {
	 * 	cin >>c;
	 * 	cout << c;
	 *
	 * }
	 *
	 * char c;
	 * while() {
	 * cin.get(c);
	 * cout << c;
	 *
	 * }
	 * <CR> 0x0D
	 * carriage-return
	 * <linefeed> 0x0A
	 * <eof>
	 *Today is
	 *
	 * Unix/Linux: LF
	 * MS Windos: CR+LF
	 *
	 */

	return 0;
}

void make_neat(ifstream& messy_file, ofstream& neat_file) {

}

