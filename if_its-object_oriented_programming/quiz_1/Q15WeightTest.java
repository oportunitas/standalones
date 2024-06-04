// File: Q15WeightTest.java
import java.util.Scanner;
public class Q15WeightTest {
	/**
	 * This class is used to test Q15Weight, by giving a free use mode
	 * for the user to input a pound weight value, and being able to display
	 * either or both of the values in pounds or in kilograms
	 */
	public static void main(String[] Args) {
		Scanner cin = new Scanner(System.in);
		String input;
		
		// Free mode, run indefinitely
		while (true) {
			// Ask user to input pound value
			System.out.print("Please input the weight in pounds\t\t: ");
			double poundVal = Double.parseDouble(cin.nextLine());
			
			// Create a new instance of Q15Weight to store and or find values
			Q15Weight myWeight = new Q15Weight(poundVal);
			
			// Ask user to print either or both pound and kilogram values
			System.out.print("Do you want to know the pound value?(Y/N)\t: ");
			input = cin.nextLine();
			if (input.equals("y")|| input.equals("Y")) {
				System.out.printf("The pound value is\t\t: %f\n", myWeight.getPounds());
			}
			System.out.print("Do you want to know the kilogram value?(Y/N)\t: ");
			input = cin.nextLine();
			if (input.equals("y")|| input.equals("Y")) {
				System.out.printf("The kilogram value is\t\t: %f\n", myWeight.getKilograms());
			}
		}
	}
}