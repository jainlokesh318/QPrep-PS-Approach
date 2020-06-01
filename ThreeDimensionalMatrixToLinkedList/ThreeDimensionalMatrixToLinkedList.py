from Solution import *

# DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE

def test_functionality():
    mat = [
              [
                  [1,2],
                  [3,4]
              ],
              [
                  [5,6],
                  [7,8]
              ]
          ]

    lst = matrix_to_linked_list(mat)
    assert lst.extract_neightbors() == [5, 5, 2, 2, 3, 3]
    assert lst.right.extract_neightbors() == [6, 6, 1, 1, 4, 4]


def main():
    test_functionality()

    (layers, rows, cols) = [int(x) for x in input().strip().split()]
    mat = [[[int(x) for x in input().strip().split()] for i in range(rows)] for j in range(layers)] 
    #print(mat)

    lst = matrix_to_linked_list(mat)


    head = lst
    for i in range(layers):
       rest_layer = head.back
       print_two_d_matrix(head, rows, cols)
       head = rest_layer
   

def print_two_d_matrix(head, n, m): 
    for i in range(n):
        rest = head.down
        for j in range(m):
            one_node = head.extract_neightbors()
            s = ' '.join([str(x) for x in one_node])
            print(s)#, end=' ')
            head = head.right
            
        head = rest
    
if __name__ == '__main__':
    main()
