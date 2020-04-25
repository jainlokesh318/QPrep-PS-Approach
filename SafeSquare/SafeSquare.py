from solution import *

# DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE

def test_queens_move():
        matrix = [  ".....",
                    ".....",
                    ".....",
                    ".Q..."
                 ]
        board = chess(matrix)
        assert (board.move() == 8)

        matrix = [  ".....",
                    "..Q..",
                    ".....",
                    "....."
                 ]
        board = chess(matrix)
        assert (board.move() == 6)

def test_knight_move():
        matrix = [  ".....",
                    ".....",
                    ".....",
                    ".K..."
                 ]
        board = chess(matrix)
        assert (board.move() == 16)

        matrix = [  ".....",
                    "..K..",
                    ".....",
                    "....."
                 ]
        board = chess(matrix)
        assert (board.move() == 13)

def test_rook_move():
        matrix = [  ".....",
                    ".....",
                    ".....",
                    ".R..."
                 ]
        board = chess(matrix)
        assert (board.move() == 12)

        matrix = [  ".....",
                    "..R..",
                    ".....",
                    "....."
                 ]
        board = chess(matrix)
        assert (board.move() == 12)

def test_bishop_move():
        matrix = [  ".....",
                    ".....",
                    ".....",
                    ".B..."
                 ]
        board = chess(matrix)
        assert (board.move() == 15)

        matrix = [  ".....",
                    "..B..",
                    ".....",
                    "....."
                 ]
        board = chess(matrix)
        assert (board.move() == 13)

def test_special_move():
        matrix = [  ".....",
                    ".....",
                    ".....",
                    ".S..."
                 ]
        board = chess(matrix)
        assert (board.move() == 6)

        matrix = [  ".....",
                    "..S..",
                    ".....",
                    "....."
                 ]
        board = chess(matrix)
        assert (board.move() == 14)

def test_complex_move():
        matrix = [  ".....",
                    ".....",
                    "..K..",
                    ".B..."
                 ]
        board = chess(matrix)
        assert (board.move() == 11)

        matrix = [  ".....",
                    "..R..",
                    ".....",
                    "..K.."
                 ]
        board = chess(matrix)
        assert (board.move() == 10)

def main():

    test_special_move()
    test_rook_move()
    test_bishop_move()
    test_queens_move()
    test_knight_move()
    test_complex_move()

    (n, m) = [int(x) for x in input().split()]
    mat = [input().strip() for i in range(n)]

    board = chess(mat)

    print(board.move())
    #print_mat(mat)
    #print_mat(board.result)


if __name__ == '__main__':
    main()
