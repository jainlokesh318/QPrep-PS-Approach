
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
    }


};
