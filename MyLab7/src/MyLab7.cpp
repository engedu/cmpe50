//============================================================================
// Name        : MyLab7.cpp
// Author      : Yutao Hou
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class SeatMgr
{
public:
	SeatMgr(int size);
	void display(ostream& out);
	bool check_seat(char seat[]);
	bool check_full();
	void assign_seat(char seat[]);

	~SeatMgr();
private:
	int rowSize;
	char** seats;
	int digit_to_row(char d);
	int digit_to_column(char d);
};
void exercise_1();
void auto_test();

int main()
{

	auto_test();

	return 0;
}

void auto_test()
{
	cout << "Input from the console or an input file?(1 for console, 2 for file)\n";
	int n;
	cin >> n;
	if (n == 1) {
		exercise_1();
	} else {
		cout << "Please input file name:\n";
		string file_name;
		cin >> file_name;

		ifstream fin;
		fin.open(file_name.c_str());
		if (fin.fail()) {
			cout << "file open fail\n";
			exit(1);
		}

		int rowSize;
		fin >> rowSize;
		fin.get(); // ignore the new line character.
		SeatMgr seat_mgr(rowSize);
		while (true)
		{
			seat_mgr.display(cout);
			char seat[4];
			fin.getline(seat, 4);
			if (seat[0] == 'e' || seat[0] == 'E')
			{
				cout << "exit\n";
				break;
			}

			if (seat_mgr.check_seat(seat))
			{
				seat_mgr.assign_seat(seat);
				cout << seat << " Seat assigned\n";
			}
			else
			{
				cout << seat << " Seat not available\n";
			}

			if (seat_mgr.check_full())
			{
				cout << "Seat full exit\n";
				break;
			}
		}

		fin.close();
	}


}
void exercise_1()
{
	int rowSize;
	cout << "How many rows does the plane have?\n";
	cin >> rowSize;
	cin.get(); // ignore the new line character.
	SeatMgr seat_mgr(rowSize);
	while (true)
	{
		seat_mgr.display(cout);
		cout << "Which seat would you like? (end to exit)\n";
		char seat[4];
		cin.getline(seat, 4);
		if (seat[0] == 'e' || seat[0] == 'E')
		{
			cout << "exit\n";
			break;
		}

		if (seat_mgr.check_seat(seat))
		{
			seat_mgr.assign_seat(seat);
			cout << "Seat assigned\n";
		}
		else
		{
			cout << "Seat not available\n";
		}

		if (seat_mgr.check_full())
		{
			cout << "Seat full exit\n";
			break;
		}
	}
}

SeatMgr::SeatMgr(int size)
{
	rowSize = size;
	seats = new char*[rowSize];
	for (int i = 0; i < rowSize; i++)
	{
		seats[i] = new char[4];
		seats[i][0] = 'A';
		seats[i][1] = 'B';
		seats[i][2] = 'C';
		seats[i][3] = 'D';
	}
}
void SeatMgr::display(ostream& out)
{
	for (int i = 0; i < rowSize; i++)
	{
		out << i + 1;
		for (int j = 0; j < 4; j++)
		{
			out << " " << seats[i][j];
		}
		out << endl;
	}
}

bool SeatMgr::check_seat(char seat[])
{
	int row = digit_to_row(seat[0]);
	if (row < 1 || row > rowSize)
	{
		return false;
	}

	int column = digit_to_column(seat[1]);
	return seats[row - 1][column] != 'X';
}

bool SeatMgr::check_full()
{
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (seats[i][j] != 'X')
			{
				return false;
			}
		}
	}
	return true;
}

void SeatMgr::assign_seat(char seat[])
{
	int row = digit_to_row(seat[0]);

	int column = digit_to_column(seat[1]);
	seats[row - 1][column] = 'X';
}
int SeatMgr::digit_to_row(char d)
{
	return d - '0';
}
int SeatMgr::digit_to_column(char d)
{
	if (d <= 'z' && d >= 'a')
	{
		return d - 'a';
	}
	else
	{
		return d - 'A';
	}

}
SeatMgr::~SeatMgr()
{
	for (int i = 0; i < rowSize; i++)
	{
		delete[] seats[i];
	}
	delete[] seats;
}

