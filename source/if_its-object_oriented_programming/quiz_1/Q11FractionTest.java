// File: Q11FractionTest.java

import java.util.Scanner;

public class Q11FractionTest {
	/**
	 * This class is used to test the Q11Fraction.java file and
	 * and output the results using the given tests
	 */
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		String input;
		
		while (true) {
			System.out.print("e1: ");
			input = cin.nextLine();
			int e1 = Integer.parseInt(input);
			
			System.out.print("d1: ");
			input = cin.nextLine();
			int d1 = Integer.parseInt(input);
			
			System.out.print("e2: ");
			input = cin.nextLine();
			int e2 = Integer.parseInt(input);
			
			System.out.print("d2: ");
			input = cin.nextLine();
			int d2 = Integer.parseInt(input);
			
			// r for result
			int[][] r = Q11Fraction.getSumAndProduct(e1, d1, e2, d2);
			
			// Ask user to print sum and or product
			String prompt;
			System.out.print("find sum? (Y/N): ");
			prompt = cin.nextLine();
			if (prompt.equals("y") || prompt.equals("Y")) {
				System.out.printf("%d/%d + %d/%d = %d/%d \n", e1, d1, e2, d2, r[0][0], r[0][1]);
			}
			System.out.print("find product? (Y/N): ");
			prompt = cin.nextLine();
			if (prompt.equals("y") || prompt.equals("Y")) {
				System.out.printf("%d/%d * %d/%d = %d/%d \n", e1, d1, e2, d2, r[1][0], r[1][1]);
			}
			
			System.out.println();
		}
	}
}