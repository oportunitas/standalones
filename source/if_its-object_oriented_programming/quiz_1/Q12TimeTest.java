// File: Q12TimeTest.java
import java.util.Scanner;
public class Q12TimeTest {
	public static void main(String[] Args) {
		Scanner cin = new Scanner(System.in);
		
		// Testing inputs given in the problem
		double[][] testcases = 
		{
			{9, 00},
			{3, 00},
			{18, 00},
			{1, 00},
			{2, 30},
			{4, 41}
		};
		
		for (int i = 0; i < testcases.length; ++i) {
			// Get the degrees from hour to min hand
			double degBetweenHands = Q12Time.getDegBetweenHands(
					testcases[i][0], testcases[i][1]);
			
			// Print the rounded degree difference from hour to minute handle CCW
			System.out.printf(
					"Deg from hour to minute in %02d:%02d is %d degrees\n",
					(int)testcases[i][0], (int)testcases[i][1],
					Math.round(degBetweenHands / 2) * 2);
			System.out.println();
		}
		
		// Free mode
		while (true) {
			// Ask user to input hour and minute
			System.out.print("Input Hour: ");
			double hour = Double.parseDouble(cin.nextLine());
			System.out.print("Input Min: ");
			double min = Double.parseDouble(cin.nextLine());
			
			double degBetweenHands = Q12Time.getDegBetweenHands(hour, min);
			
			// Print the rounded degree difference from hour to minute handle CCW
			System.out.printf(
					"The degrees between the hour and minute hand is %d degrees\n",
					Math.round(degBetweenHands / 2) * 2);
			System.out.println();
		}
	}
}