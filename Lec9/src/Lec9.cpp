//============================================================================
// Name        : Lec9.cpp
// Author      : Yutao Hou
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	string string_o = "hell";
	char c_string[] = string_o.c_str();

	// 8.1, 8.2
	// march 3rd midterm
	// 20 questions
	// 4:30 pm - 5:30pm
	// one cheatsheet
	// close book
	/*
	c-string

declare
char my_message[20] = "Hi There"
char short_string[] = "abc";
char short_string[] = {'a', 'b', 'c'};
char short_string[] = {'a', 'b', 'c', '\0'}
char short_string[4] = {'a', 'b', 'c', '\0'}
char s_string[]; // 0 byte is allocate

do not change '\0'

loop

	*/
	char our_string[] = "Hi MOM!";
	int SIZE = 7;
	int index = 0;
	while (our_string[index] != '\0' && index < SIZE) {
		our_string[index] = 'X';
		index++;
	}

	/*
	 assignment of c-strings
	 #include <cstring>
	 char a_string[11];
	 strcpy(a_string, "Hello");
	 char array length = string length + 1;

	 strcpy does not check the length of array
	 strncpy(dest,
	 *strncpy(dest, src, 9)
	 strcmp(str1, str2)
	 strncmp(str1, str2, size)
	 a > A
	 char c = 0;
	 char c = '\0';
	 c = 0x41;
	 c = 'A';

	strnlen(a_string, SIZE);
	strncat

	cin stop at space

	cin.getline(a, 80);
	cin read up to 79 = 80 - 1;
	ifstream.getline(a, 80)
	*cin.getline(String_VAR
	#include <cstdlib>
	atoi
	atol
	atof

	next Thursday review



	 */

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	return 0;

}
