import java.util.*;

// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE

class Node {    
    int val;
    Node front;
    Node back;
    Node up;
    Node right;
    Node down;
    Node left;


    Node(int x) {
        this.val = x;
        this.front = null;
        this.back = null;
        this.up  = null;       
        this.right = null;
        this.down = null;
        this.left = null;
    }
    ArrayList<Integer> extractNeighbors() {
        ArrayList<Integer> neighbour = new ArrayList<Integer>();
        neighbour.add(front.val);
        neighbour.add(back.val);
        neighbour.add(left.val);
        neighbour.add(right.val);
        neighbour.add(up.val);
        neighbour.add(down.val);
        return neighbour;
    }
};

class ThreeDimensionalMatrixToLinkedList {
    
    public static void test_functionality(){
    int matrix[][][] = {
        {
            {1,2},
            {3,4}
        },
        {
            {5,6},
            {7,8}
        }
    };
    Node head= new Solution().threeDimensionalMatrixToLinkedList(matrix,2,2,2);
    
    int output[] = {5, 5, 2, 2, 3, 3};
    int output1[] = {6, 6, 1, 1, 4, 4};
    
    ArrayList<Integer> out = new ArrayList<Integer>();
    for(int i = 0 ; i < output.length ; i++) {
        out.add(output[i]);
    }
    ArrayList<Integer> out1 = new ArrayList<Integer>();
    for(int i = 0 ; i < output1.length ; i++) {
        out1.add(output1[i]);
    }
    assert(head.val == 1);
    assert(head.extractNeighbors().equals(out));

    assert(head.right.val == 2);
    assert(head.right.extractNeighbors().equals(out1));

}
    static void print_2d_matrix(Node head, int rows, int cols)
    {
	Node rest;
        StringBuffer sb = new StringBuffer("");
	for (int i = 0; i < rows; ++i) {
	    rest = head.down;
	    for (int j = 0; j < cols; ++j) {
		ArrayList<Integer> neighbors = head.extractNeighbors();
                for (Integer one : neighbors) {
                    sb.append(one);
                    sb.append(" ");
                }
                sb.append("\n");
		head = head.right; 
	    }
	    head = rest;
	}
        System.out.println(sb);
    }

    static void printOutput(Node head,int layer,int row,int column)
    {
	Node rest;

	for(int i=0;i<layer;i++)
	{
	    rest = head.back;
	    print_2d_matrix(head, row, column);
	    head = rest;
	}
    }

    public static void main(String[] args) {
        test_functionality();
        Scanner scanner = new Scanner(System.in);
        int dimx = scanner.nextInt();
        int dimy = scanner.nextInt();
        int dimz = scanner.nextInt();
        int cuboid[][][] = new int[dimx][dimy][dimz];
        for(int i = 0; i < dimx ; i++) {
            for(int j = 0 ; j < dimy ; j++) {
                for(int k = 0 ; k < dimz ; k++) {
                    cuboid[i][j][k] = scanner.nextInt();
                }
            }
        }
        Node head = new Solution().threeDimensionalMatrixToLinkedList(cuboid , dimx , dimy , dimz);
        printOutput(head, dimx, dimy, dimz);
    }
}
