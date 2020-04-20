import java.io.*;
import java.util.*;

// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE



class SameersChoice {

	public static void main(String args[]) {
		
		SameersChoice sameer = new  SameersChoice();


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

