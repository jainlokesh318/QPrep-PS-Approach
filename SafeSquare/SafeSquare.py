from solution import *

# DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE


def main():


    (n, m) = [int(x) for x in input().split()]
    mat = [input().strip() for i in range(n)]

    board = chess(mat)

    print(board.move())
    #print_mat(mat)
    #print_mat(board.result)


if __name__ == '__main__':
    main()
