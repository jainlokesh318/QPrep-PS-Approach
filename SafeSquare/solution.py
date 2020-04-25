def print_mat(mat):
    n = len(mat)
    m = len(mat[0])
    for i in range(n):
        for j in range(m):
            print(mat[i][j], end=" ")
        print('')

class chess:
    def __init__(self, mat):


    # TODO: CRIO_TASK_MODULE_SAFE_SQUARE
    # Input:
    #   1) chess board matrix
    # Task:
    #   1) Implement Rook move
    #   2) Implement Bishop move
    #   3) Implement Queens move
    #   4) Implement knight's move
    #   5) Special move
    # Output:
    #   Count the number of safe square and return it

    def move(self):
