import java.io.*;
import java.util.*;

// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE



class SameersChoice {
	void testValidNumberPattern() {
		solution solve = new solution();
		boolean number1 = solve.isValidNumberPlate("TN-12-1234");
		boolean number2 = solve.isValidNumberPlate("TN-12-A-1234");
		boolean number3 = solve.isValidNumberPlate("TN-12-AB-1234");
		boolean number4 = solve.isValidNumberPlate("TN-12-ABC-1234");
		
		assert number1 == true;
		assert number2 == true;
		assert number3 == true;
		assert number4 == true;

		boolean number5 = solve.isValidNumberPlate("TN-12-ABCD-1234");
		boolean number6 = solve.isValidNumberPlate("OLA1234");
		boolean number7 = solve.isValidNumberPlate("TN-12-12345");
		boolean number8 = solve.isValidNumberPlate("UT-12-abcd");
		boolean number9 = solve.isValidNumberPlate("UT-12--4578");

		assert number5 == false;
		assert number6 == false;
		assert number7 == false;
		assert number8 == false;
		assert number9 == false;

	}	

	void testNumberPattern() {
		solution solve = new solution();
		String number1[] = solve.isDesignatedAndFindMinimumByFourthPart("3145", "31-23-45");
		String number2[] = solve.isDesignatedAndFindMinimumByFourthPart("3245", "31-23-45");
		String number3[] = solve.isDesignatedAndFindMinimumByFourthPart("3135", "31-23-45");
		String number4[] = solve.isDesignatedAndFindMinimumByFourthPart("3235", "31-23-45");

		assert number1[0].equals("yes") == true;
		assert number2[0].equals("yes") == true;
		assert number3[0].equals("yes") == true;
		assert number4[0].equals("yes") == true;

		number1 = solve.isDesignatedAndFindMinimumByFourthPart("4435", "31-23-45");
		number2 = solve.isDesignatedAndFindMinimumByFourthPart("4445", "31-23-45");
		number3 = solve.isDesignatedAndFindMinimumByFourthPart("4415", "31-23-45");
		String expected1 = "3135";
		String expected2 = "3145";
		String expected3 = "3135";

		assert expected1.equals(number1[1]) == true;
		assert expected2.equals(number2[1]) == true;
		assert expected3.equals(number3[1]) == true;



	}

	void testPalindrome() {
		solution solve = new solution();
		assert solve.isPalindrome("1221") == true;
		assert solve.isPalindrome("2112") == true;
		assert solve.isPalindrome("1111") == true;
		assert solve.isPalindrome("2121") == false;
		assert solve.isPalindrome("2221") == false;
		assert solve.isPalindrome("2212") == false;
	}

	public static void main(String args[]) {
		
		SameersChoice sameer = new  SameersChoice();

		sameer.testValidNumberPattern();
		sameer.testNumberPattern();
		sameer.testPalindrome();

		Scanner scanner = new Scanner(System.in);
		ArrayList<Integer> finalPlates = new ArrayList<Integer>();
		int noOfPatterns = scanner.nextInt();
		String vehicleType[] = new String[noOfPatterns];
		String regPattern[] = new String[noOfPatterns];
		for(int i  = 0 ; i < noOfPatterns ; i++) {
			vehicleType[i] = scanner.next();
			regPattern[i] = scanner.next();
		}
		int noOfPlates = scanner.nextInt();
		String plate[] = new String[noOfPlates];
		String vehicle[] = new String[noOfPlates];
		for(int i = 0 ; i < noOfPlates ; i++) {
			plate[i] = scanner.next();
			vehicle[i] = scanner.next();
		}
		solution solve = new solution();
		solve.luckyNumber(noOfPatterns,noOfPlates,vehicleType,regPattern,plate,vehicle);
	}

}

