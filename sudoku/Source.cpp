#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

class Sudoku
{
private: 
	char board[10][10];
	int change[10][10];

public:
	Sudoku();
	void init_Board();
	void print_Board();
};

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
	
	cout << endl;
	cout << "\x1B[31m" << "ABV" << "\033[0m";

	return 0;
}