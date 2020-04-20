#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE

#include "solution.cpp"

int main()
{

    int rows,cols;
    vector<vector<char>> board;
	cin >> rows >> cols;
	board.resize(rows,vector<char>(cols));
	for(int i = 0 ; i< rows ; i++) {
		for(int j = 0 ;j < cols ; j++) {
			cin >> board[i][j];
		}
	}
    chess chess_board(board);

	cout << chess_board.move() << endl;
	return 0;
}

