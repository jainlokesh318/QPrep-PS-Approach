import java.util.*;
import java.lang.Math;

// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE

class SafeSquare{

	public static void test_queen_move()
	{
		solution s1=new solution();
		char[][] matrix = {
					{'.','.','.','.','.'},
                    {'.','.','.','.','.'},
                    {'.','.','.','.','.'},
                    {'.','Q','.','.','.'}
                 };
        s1.readInputTest(matrix,4,5);
        assert s1.move() == 8;
        char[][] matrix1 = {
        			{'.','.','.','.','.'},
                    {'.','.','Q','.','.'},
                    {'.','.','.','.','.'},
                    {'.','.','.','.','.'}
                 };
        solution s2=new solution();
        s2.readInputTest(matrix1,4,5);
        assert s2.move() == 6;
	}
	public static void test_bishop_move()
	{
		solution s1=new solution();
		char[][] matrix = {
					{'.','.','.','.','.'},
                    {'.','.','.','.','.'},
                    {'.','.','.','.','.'},
                    {'.','B','.','.','.'}
                 };
        s1.readInputTest(matrix,4,5);
        assert s1.move() == 15;
        char[][] matrix1 = {
        			{'.','.','.','.','.'},
                    {'.','.','B','.','.'},
                    {'.','.','.','.','.'},
                    {'.','.','.','.','.'}
                 };
        solution s2=new solution();
        s2.readInputTest(matrix1,4,5);
        assert s2.move() == 13;
	}
	public static void test_rook_move()
	{
		solution s1=new solution();
		char[][] matrix = {
					{'.','.','.','.','.'},
                    {'.','.','.','.','.'},
                    {'.','.','.','.','.'},
                    {'.','R','.','.','.'}
                 };
        s1.readInputTest(matrix,4,5);
        assert s1.move() == 12;
        char[][] matrix1 = {
        			{'.','.','.','.','.'},
                    {'.','.','R','.','.'},
                    {'.','.','.','.','.'},
                    {'.','.','.','.','.'}
                 };
        solution s2=new solution();
        s2.readInputTest(matrix1,4,5);
        assert s2.move() == 12;
	}
	public static void test_knight_move()
	{
		solution s1=new solution();
		char[][] matrix = {
					{'.','.','.','.','.'},
                    {'.','.','.','.','.'},
                    {'.','.','.','.','.'},
                    {'.','K','.','.','.'}
                 };
        s1.readInputTest(matrix,4,5);
        assert s1.move() == 16;
        char[][] matrix1 = {
        			{'.','.','.','.','.'},
                    {'.','.','K','.','.'},
                    {'.','.','.','.','.'},
                    {'.','.','.','.','.'}
                 };
        solution s2=new solution();
        s2.readInputTest(matrix1,4,5);
        assert s2.move() == 13;
	}
	public static void test_special_move()
	{
		solution s1=new solution();
		char[][] matrix = {
					{'.','.','.','.','.'},
                    {'.','.','.','.','.'},
                    {'.','.','.','.','.'},
                    {'.','S','.','.','.'}
                 };
        s1.readInputTest(matrix,4,5);
        assert s1.move() == 6;
        char[][] matrix1 = {
        			{'.','.','.','.','.'},
                    {'.','.','S','.','.'},
                    {'.','.','.','.','.'},
                    {'.','.','.','.','.'}
                 };
        solution s2=new solution();
        s2.readInputTest(matrix1,4,5);
        assert s2.move() == 14;
	}
	public static void test_complex_move()
	{
		solution s1=new solution();
		char[][] matrix = {
					{'.','.','.','.','.'},
                    {'.','.','.','.','.'},
                    {'.','.','K','.','.'},
                    {'.','B','.','.','.'}
                 };
        s1.readInputTest(matrix,4,5);
        assert s1.move() == 11;
        char[][] matrix1 = {
        			{'.','.','.','.','.'},
                    {'.','.','R','.','.'},
                    {'.','.','.','.','.'},
                    {'.','.','K','.','.'}
                 };
        solution s2=new solution();
        s2.readInputTest(matrix1,4,5);
        assert s2.move() == 10;
	}

    public static void main(String[] args) {
		test_queen_move();
		test_bishop_move();
		test_rook_move();
		test_knight_move();
		test_special_move();
		test_complex_move();

		solution so=new solution();
		so.readInput();
		int ans=so.move();
		System.out.println(ans);
	}
}

