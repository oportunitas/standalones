// File: Q16FractionTest.java
import java.util.Scanner;
public class Q16FractionTest {
	public static void main(String[] Args) {
		Scanner cin = new Scanner(System.in);
		
		// Asks user to input enumerator and denominator for f1
		System.out.print("ef1: ");
		int ef1 = Integer.parseInt(cin.nextLine());
		System.out.print("df1: ");
		int df1 = Integer.parseInt(cin.nextLine());
		Q16Fraction f1 = new Q16Fraction(ef1, df1);
		
		// Asks user to input enumerator and denomintor for f2
		System.out.print("ef2: ");
		int ef2 = Integer.parseInt(cin.nextLine());
		System.out.print("df2: ");
		int df2 = Integer.parseInt(cin.nextLine());
		Q16Fraction f2 = new Q16Fraction(ef2, df2);
		
		// Print f1 + f2 and f1 * f2
		System.out.println(f2.getProduct(f1));
		System.out.println(f2.getSum(f1));
	}
}