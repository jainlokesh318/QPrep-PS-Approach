#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE

#include "solution.cpp"

void test_queen_move()
{
	vector< vector<char> > board{
				{'.','.','.','.','.'},
                {'.','.','.','.','.'},
                {'.','.','.','.','.'},
                {'.','Q','.','.','.'}
             };
    chess chess_board(board);
    assert (chess_board.move()==8);
    vector< vector<char> > board1{
    			{'.','.','.','.','.'},
                {'.','.','Q','.','.'},
                {'.','.','.','.','.'},
                {'.','.','.','.','.'}
             };
    chess chess_board1(board1);
    assert (chess_board1.move() == 6);
}
void test_bishop_move()
{
	vector< vector<char> > board{
				{'.','.','.','.','.'},
                {'.','.','.','.','.'},
                {'.','.','.','.','.'},
                {'.','B','.','.','.'}
             };
    chess chess_board(board);
    assert (chess_board.move() == 15);
    vector< vector<char> > board1{
    			{'.','.','.','.','.'},
                {'.','.','B','.','.'},
                {'.','.','.','.','.'},
                {'.','.','.','.','.'}
             };
    chess chess_board1(board1);
    assert (chess_board1.move() == 13);
}
void test_rook_move()
{
	vector< vector<char> > board{
				{'.','.','.','.','.'},
                {'.','.','.','.','.'},
                {'.','.','.','.','.'},
                {'.','R','.','.','.'}
             };
    chess chess_board(board);
    assert (chess_board.move() == 12);
    vector< vector<char> > board1{
    			{'.','.','.','.','.'},
                {'.','.','R','.','.'},
                {'.','.','.','.','.'},
                {'.','.','.','.','.'}
             };
    chess chess_board1(board1);
    assert (chess_board1.move() == 12);
}
void test_knight_move()
{
	vector< vector<char> > board{
				{'.','.','.','.','.'},
                {'.','.','.','.','.'},
                {'.','.','.','.','.'},
                {'.','K','.','.','.'}
             };
    chess chess_board(board);
    assert (chess_board.move() == 16);
    vector< vector<char> > board1{
    			{'.','.','.','.','.'},
                {'.','.','K','.','.'},
                {'.','.','.','.','.'},
                {'.','.','.','.','.'}
             };
    chess chess_board1(board1);
    assert (chess_board1.move() == 13);
}
void test_special_move()
{
	vector< vector<char> > board{
				{'.','.','.','.','.'},
                {'.','.','.','.','.'},
                {'.','.','.','.','.'},
                {'.','S','.','.','.'}
             };
    chess chess_board(board);
    assert (chess_board.move() == 6);
    vector< vector<char> > board1{
    			{'.','.','.','.','.'},
                {'.','.','S','.','.'},
                {'.','.','.','.','.'},
                {'.','.','.','.','.'}
             };
    chess chess_board1(board1);
    assert (chess_board1.move() == 14);
}
void test_complex_move()
{
	vector< vector<char> > board{
				{'.','.','.','.','.'},
                {'.','.','.','.','.'},
                {'.','.','K','.','.'},
                {'.','B','.','.','.'}
             };
   	chess chess_board(board);
    assert (chess_board.move() == 11);
    vector< vector<char> > board1{
    			{'.','.','.','.','.'},
                {'.','.','R','.','.'},
                {'.','.','.','.','.'},
                {'.','.','K','.','.'}
             };
    chess chess_board1(board1);
    assert (chess_board1.move() == 10);
}
int main()
{
	test_queen_move();
	test_bishop_move();
	test_rook_move();
	test_knight_move();
	test_special_move();
	test_complex_move();

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

