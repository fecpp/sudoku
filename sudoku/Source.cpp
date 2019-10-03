#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <Windows.h>

using namespace std;

class Sudoku {
private: 
	char board[10][10];
	int change[10][10];

public:
	Sudoku(); //constructer fun 
	void init_Board(); //initiate the board as per Q1 requirement 
	void print_Board(); //print the board in console
	void save_Board(); //save the current board to txt file
};

//read a board from a txt file
void read_Board() {
	//need to add resource file to our sln first, otherwise need to type out the extire directory.
	//file must be placed under the same directory as the sln file
	//right-click Resource File -> Add -> Existing Item...
	ifstream infile;
	infile.open("mysudoku.txt");

	if (infile.fail()) {
		cerr << "File does not exist in solution" << endl;
		exit(1);
	}

	string rawBoard; // to store the entire string, deal with it later 
	rawBoard.assign((istreambuf_iterator<char>(infile)), (istreambuf_iterator<char>()));

	cout << rawBoard << endl;
}


//save the current board to a txt file
void Sudoku::save_Board() {
	ofstream outfile("mySudoku.txt");
	if (outfile.is_open()) {

		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				if (change[i][j] == 1) {
					outfile << "g" << board[i][j] << ",";
				}
				else outfile << board[i][j] << ",";
			}
		}
		outfile.close();
	}
	else cout << "Unable to open text file";
}

Sudoku::Sudoku() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			board[i][j] = ' ';
			change[i][j] = 0;
		}
	}
}

void Sudoku::init_Board() {
	board[1][1] = '9'; board[1][4] = '6'; board[1][6] = '3'; board[1][7] = '1'; board[1][8] = '2'; board[1][9] = '8';
	board[2][1] = '8'; board[2][4] = '7'; board[2][6] = '1'; board[2][7] = '5'; board[2][8] = '3'; board[2][9] = '9';
	board[3][1] = '1'; board[3][3] = '3'; board[3][4] = '8'; board[3][5] = '9'; board[3][8] = '6';
	board[4][1] = '4'; board[4][2] = '9'; board[4][3] = '2'; board[4][5] = '6'; board[4][7] = '8';
	board[5][2] = '1'; board[5][4] = '3'; board[5][5] = '8'; board[5][7] = '8';
	board[6][2] = '3'; board[6][3] = '8'; board[6][4] = '9'; board[6][5] = '1'; board[6][6] = '2'; board[6][7] = '6'; board[6][8] = '5'; board[6][9] = '4';
	board[7][4] = '2'; board[7][5] = '7'; board[7][6] = '9'; board[7][7] = '3'; board[7][9] = '1';
	board[8][1] = '3'; board[8][2] = '7'; board[8][6] = '8'; board[8][7] = '2';
	board[9][1] = '2'; board[9][3] = '9'; board[9][4] = '1'; board[9][5] = '3'; board[9][6] = '6'; board[9][8] = '8'; board[9][9] = '5';

	change[4][5] = 1;
}

/*
void setcolor(unsigned short color) {                                                   
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}
*/

void Sudoku::print_Board() {
	cout << "   | 1 2 3 | 4 5 6 | 7 8 9 " << endl;
	cout << "---+-------+-------+-------" << endl;
	for (int i = 1; i <= 9; i++) {
		cout << " " << char(i+64) << " | ";
		for (int j = 1; j <= 9; j++) {
			if (change[i][j] == 1) {
				cout << "\x1B[31m" << board[i][j] << "\033[0m" << " "; //print in red
			}
			else cout << board[i][j] << " ";
			if (j % 3 == 0) cout << "| ";
		}
		cout << endl;
		if (i % 3 == 0) cout << "---+-------+-------+-------" << endl;
	}
}

int main() {

	Sudoku game;

	game.init_Board();
	game.print_Board();
	game.save_Board();
	cout << endl << "\x1B[31m" << "ABC" << "\033[0m" << endl;

	read_Board();



	return 0;
}