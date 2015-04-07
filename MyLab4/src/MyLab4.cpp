//============================================================================
// Name        : MyLab4.cpp
// Author      : Yutao Hou
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

void exercise_1();
void exercise_2();

void read_array(char input[], int size);
void print_array(char array[], int size);
bool check(string& sentence, int& position, string src, string dest);
bool check_end(char ch);

int main()
{
	exercise_1();
	exercise_2();
	return 0;
}

void exercise_1()
{
	char input[MAX_SIZE + 1];
	cout << "Please enter:" << endl;
	read_array(input, MAX_SIZE + 1);
	print_array(input, MAX_SIZE + 1);
}

void read_array(char input[], int size)
{
	bool skip_space = false;
	int i = 0;
	char ch;
	cin.get(ch);

	while (i < size - 2 && ch != '.')
	{

		if (isspace(ch))
		{
			if (i == 0)
			{
				skip_space = true;
			}
			else
			{
				if (!skip_space)
				{
					input[i] = ' ';
					skip_space = true;
					i++;
				}
			}
		}
		else
		{
			if (i == 0)
			{
				input[i] = toupper(ch);

			}
			else
			{
				input[i] = tolower(ch);
			}
			i++;
			skip_space = false;
		}

		cin.get(ch);

	}
	input[i] = '.';
	i++;
	input[i] = '\0';
	cin.clear();
}

void print_array(char array[], int size)
{
	int i = 0;
	while (i < size && array[i] != '\0')
	{
		cout << array[i];
		i++;
	}
	cout << endl;
}
void exercise_2()
{

	while (true)
	{
		string sentence;

		cout << "Please input a sentence. Done/done means exit:" << endl;
		getline(cin, sentence);

		size_t found1, found2;
		found1 = sentence.find("done");
		found2 = sentence.find("Done");
		if (found1 != string::npos || found2 != string::npos)
		{
			cout << "exit" << endl;
			return;
		}
		int position = 0;


		while(check(sentence, position, "she", "she or he"));
		position = 0;
		while(check(sentence, position, "he", "she or he"));
		position = 0;
		while(check(sentence, position, "He", "She or he"));
		position = 0;
		while(check(sentence, position, "She", "She or he"));

		position = 0;
		while(check(sentence, position, "him", "her or him"));
		position = 0;
		while(check(sentence, position, "her", "her or him"));

		position = 0;
		while(check(sentence, position, "his", "her(s), or his"));
		position = 0;
		while(check(sentence, position, "her(s)", "her(s), or his"));
		position = 0;
		while(check(sentence, position, "His", "Her(s), or his"));
		position = 0;
		while(check(sentence, position, "her(s)", "Her(s), or his"));

		cout << "Suggestion:" << endl;
		cout << sentence << endl;
	}
}

//void check(string& sentence, int& position, string src, string dest)
//{
//	size_t found;
//	found = sentence.find(src, position);
//
//	if (found != string::npos)
//	{
//		cout << "found \"" << src << "\" then replace with \"" << dest << "\""
//				<< endl;
//		sentence.replace(found, src.size(), dest);
//		position = found + dest.size();
//	}
//}

bool check(string& sentence, int& position, string src, string dest)
{
	size_t found, found1, found2;

	found = false;
//	int size = sentenc
	int size1 = src.size();
	int size2 = dest.size();

	found1 = sentence.find(src, position);
	found2 = sentence.find(dest, position);

	if (found1 != string::npos)
	{

		if (found2 != string::npos && found1 == found2)
		{
			// skip
			position = found1 + size2;

		}
		else
		{

			// try to do whole-word search
//			cout << "found1: " << found1 << endl;
//			cout << "size1:" << size1 << " " << "size2:" << size2 << endl;
//
//			cout << "sentence.size():" << sentence.size() << endl;
			if (found1 == 0)
			{
//				cout << "h1" << endl;
				if ((found1 + size1) == sentence.size())
				{
//					cout << "h12" << endl;
					found = true;
				}
				else
				{
					if (check_end(sentence.at(found1 + size1)))
					{
//						cout << "h13" << endl;
						found = true;
					}
				}
			}
			else
			{
				if (check_end(sentence.at(found1 - 1)))
				{
//					cout << "h21" << endl;
					if ((found1 + size1) == sentence.size())
					{
//						cout << "h23" << endl;
						found = true;
					}
					else
					{
						if (check_end(sentence.at(found1 + size1)))
						{
//							cout << "h24" << endl;
							found = true;
						}
					}
				}
			}

//			found = true;
			if (found)
			{
				cout << "found \"" << src << "\" then replace with \"" << dest
						<< "\"" << endl;
				sentence.replace(found1, size1, dest);
				position = found1 + size2;
			} else {
				position = found1 + size1;
			}


		}

		return true;

	}
	return false;
}

bool check_end(char ch) {
	return (ch == ' ' || ch == ',' || ch == '.');
}
// output
/*

Please enter:
   noW  iS   thE    TiMe  fOr  aLl
         gOOD MEN TO  ComE TO   tHe
  		aId
oF


   ThE  CounTRY.
Now is the time for all good men to come to the aid of the country.
Please input a sentence. Done/done means exit:
Suggestion:

Please input a sentence. Done/done means exit:
See an adviser, talk to him, and listen to him. She will help you, then thank her.
found "She" then replace with "She or he"
found "him" then replace with "her or him"
found "him" then replace with "her or him"
found "her" then replace with "her or him"
Suggestion:
See an adviser, talk to her or him, and listen to her or him. She or he will help you, then thank her or him.
Please input a sentence. Done/done means exit:
done
exit

 */

