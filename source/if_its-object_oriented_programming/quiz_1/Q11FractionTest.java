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
		
		int[] r1 = Q11Fraction.getSum(1, 2, 1, 3);
		System.out.printf("%d/%d + %d/%d = %d/%d \n", 1, 2, 1, 3, r1[0], r1[1]);
		int[] r2 = Q11Fraction.getSum(1, 3, 3, 4);
		System.out.printf("%d/%d + %d/%d = %d/%d \n", 1, 3, 3, 4, r2[0], r2[1]);
		int[] r3 = Q11Fraction.getProduct(1, 2, 2, 3);
		System.out.printf("%d/%d + %d/%d = %d/%d \n", 1, 2, 2, 3, r3[0], r3[1]);
		int[] r4 = Q11Fraction.getProduct(1, 4, 2, 3);
		System.out.printf("%d/%d + %d/%d = %d/%d \n", 1, 4, 2, 3, r4[0], r4[1]);
		System.out.println();
		
		// Free mode, Run the fraction calculator indefinitely
		while (true) {
			// Ask user to input 2 fractions to calculate
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
			
			// Get the result, {r} for result
			int[][] r = Q11Fraction.getSumAndProduct(e1, d1, e2, d2);
			
			// Ask user to print sum
			String prompt;
			System.out.print("find sum? (Y/N): ");
			prompt = cin.nextLine();
			if (prompt.equals("y") || prompt.equals("Y")) {
				System.out.printf("%d/%d + %d/%d = %d/%d \n", e1, d1, e2, d2, r[0][0], r[0][1]);
			}
			
			// Ask user to print product
			System.out.print("find product? (Y/N): ");
			prompt = cin.nextLine();
			if (prompt.equals("y") || prompt.equals("Y")) {
				System.out.printf("%d/%d * %d/%d = %d/%d \n", e1, d1, e2, d2, r[1][0], r[1][1]);
			}
			
			System.out.println();
		}
	}
}