//============================================================================
// Name        : Lec8.cpp
// Author      : Yutao Hou
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	/*
	 *
I/O Stream
cin >> extraction
cout << insertion

char c;
cin.get(c)

ifstream ifs;
ifs.get(c);

low level character I/O

LF linefeed '\n' 0x0A
CR carriage-return '\r' 0x0D

open file three step

// 1
#include <fstream>

// 2
infsteam fin;
fin.open();
if (fin.fail()) {
}

// 3
fin.close();

'\n' : new line character
"\n" : empty line


put
cannot put string

putback(char)


Inheritance and output
istream
cin, ifstream

ostream
cout, ofstream

default arguments

<< and get
remove '\n'

Detecting the end of a file
eof single character

while(fin >> next)
while(!fin.

cctype

toupper('a') return 'A'
toupper('a') return 'A'

isspace()
' ', '\t', '\n'
#include <cctype>
using namespace std;


ch8

two type of string
C-String: array of character
String class

c-string
null character, null terminator

Hexdecimal
tedious





	 */
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
