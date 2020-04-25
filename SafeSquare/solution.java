import java.util.*;
import java.lang.Math;

class solution{
	char matrix[][]= new char[101][101];
	int mat[][]= new int[101][101];
	int n,m;
	Scanner inp= new Scanner(System.in);
	public void readInput()
	{
		int i,j;
		n=inp.nextInt();
		m=inp.nextInt();
		for(i=1;i<=n;i++)
		{
			String s=inp.next();
			for(j=1;j<=m;j++)
			{
				matrix[i][j]=s.charAt(j-1);
			}
		}
	}
	public void readInputTest(char testRead[][],int row,int col)
	{
		n=row;
		m=col;
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=col;j++)
			{
				matrix[i][j]=testRead[i-1][j-1];
			}
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

    public int move()
	{
	}
}
