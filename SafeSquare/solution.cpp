#include<bits/stdc++.h>
using namespace std;

struct chess {
    vector<vector<char>> board;
    int rows,cols;
    vector<vector<int>> mark;

    chess(vector<vector<char> > brd) {
        rows = brd.size();
        cols = brd[0].size();

        for (int i = 0; i < rows; ++i) {
            vector<char> t1(brd[i]);
            vector<int> tmp(cols, 0);
            board.push_back(t1);
            mark.push_back(tmp);
        }
    }

    void moveUp(int a, int b, int n, int m)
{
    for(int i = a-1; i >= 0; i--)
    {
        if(board[i][b] != '.')
            break;
        mark[i][b] = -1;
    }
}

void moveDown(int a, int b, int n, int m)
{
    for(int i = a+1; i < n; i++)
    {
        if(board[i][b] != '.')
            break;
        mark[i][b] = -1;
    }
}

void moveLeft(int a, int b, int n, int m)
{
    for(int i = b-1; i >= 0; i--)
    {
        if(board[a][i] != '.')
            break;
        mark[a][i] = -1;
    }
}

void moveRight(int a, int b, int n, int m)
{
    for(int i = b+1; i < m; i++)
    {
        if(board[a][i] != '.')
            break;
        mark[a][i] = -1;
    }
}

void moveDiagonalUpLeft(int a, int b, int n, int m)
{
    int x = b;
    for(int i = a-1; i >= 0; i--)
    {
        x--;
        if(x >= 0)
        {
            if(board[i][x] != '.')
                break;
            mark[i][x] = -1;
        }
    }
}

void moveDiagonalUpRight(int a, int b, int n, int m)
{
    int x = b;
    for(int i = a-1; i >= 0; i--)
    {
        x++;
        if(x < m)
        {
            if(board[i][x] != '.')
                break;
            mark[i][x] = -1;
        }
    }
}

void moveDiagonalDownLeft(int a, int b, int n, int m)
{
    int x = b;
    for(int i = a+1; i < n; i++)
    {
        x--;
        if(x >= 0)
        {
            if(board[i][x] != '.')
                break;
            mark[i][x] = -1;
        }
    }
}

void moveDiagonalDownRight(int a, int b, int n, int m)
{
    int x = b;
    for(int i = a+1; i < n; i++)
    {
        x++;
        if(x < m)
        {
            if(board[i][x] != '.')
                break;
            mark[i][x] = -1;
        }
    }
}

void knightUp(int a, int b, int n, int m)
{
    if(a-2 >= 0)
    {
        if(b-1 >= 0)
            mark[a-2][b-1] = -1;
        if(b+1 < m)
            mark[a-2][b+1] = -1;
    }
}

void knightDown(int a, int b, int n, int m)
{
    if(a+2 < n)
    {
        if(b-1 >= 0)
            mark[a+2][b-1] = -1;
        if(b+1 < m)
            mark[a+2][b+1] = -1;
    }
}

void knightLeft(int a, int b, int n, int m)
{
    if(b-2 >= 0)
    {
        if(a-1 >= 0)
            mark[a-1][b-2] = -1;
        if(a+1 < n)
            mark[a+1][b-2] = -1;
    }
}

void knightRight(int a, int b, int n, int m)
{
    if(b+2 < m)
    {
        if(a-1 >= 0)
            mark[a-1][b+2] = -1;
        if(a+1 < n)
            mark[a+1][b+2] = -1;
    }
}

void rook_move(int a, int b, int n, int m)
{
    mark[a][b] = -1;
    moveUp(a, b, n, m);
    moveDown(a, b, n, m);
    moveLeft(a, b, n, m);
    moveRight(a, b, n, m);
}


void bishop_move(int a, int b, int n, int m)
{
    mark[a][b] = -1;
    moveDiagonalUpLeft(a, b, n, m);
    moveDiagonalUpRight(a, b, n, m);
    moveDiagonalDownLeft(a, b, n, m);
    moveDiagonalDownRight(a, b, n, m);
}

void knight_move(int a, int b, int n, int m)
{
    mark[a][b] = -1;
    knightUp(a, b, n, m);
    knightDown(a, b, n, m);
    knightLeft(a, b, n, m);
    knightRight(a, b, n, m);
}

void special_move(int a, int b, int n, int m)
{
    n--;
    m--;
    int row = min(a, n-a);
    int col = min(b, m-b);
    row = min(row, col);
    col = min(row, col);
    for(int i = col; i <= m-col; i++)
        mark[row][i] = -1;
    for(int i = col; i <= m-col; i++)
        mark[n-row][i] = -1;

    for(int i = row; i <= n-row; i++)
        mark[i][col] = -1;
    for(int i = row; i <= n-row; i++)
        mark[i][m-col] = -1;
}
    // TODO: CRIO_TASK_MODULE_SAFE_SQUARE
    // Input:
    //   1) chess board matrix
    // Task:
    //   1) Implement Rook move
    //   2) Implement Bishop move
    //   3) Implement Queens move
    //   4) Implement knight's move
    //   5) Special move
    // Output:
    //   Count the number of safe square and return it

    int move() {
        int cancel = 0;
    int n = board.size();
    int m = board[0].size();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 'R')
                rook_move(i, j, n, m);
            else if(board[i][j] == 'B')
                bishop_move(i, j, n, m);
            else if(board[i][j] == 'Q')
            {
                rook_move(i, j, n, m);
                bishop_move(i, j, n, m);
            }
            else if(board[i][j] == 'K')
                knight_move(i, j, n, m);
            else if(board[i][j] == 'S')
                special_move(i, j, n, m);
        }
    }
    //cout << "\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
      //   cout << mark[i][j] << " ";
            if(mark[i][j] == 0)
                cancel++;
        }

        //cout << "\n";
    }

    return cancel;
}


};
