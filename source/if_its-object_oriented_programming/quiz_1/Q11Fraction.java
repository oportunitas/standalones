// File: Q11Fraction.java

public class Q11Fraction {
	// Getters
	private static int getMax(int n1, int n2) {
		return (n1 > n2) ? n1 : n2;
	}
	private static int getMin(int n1, int n2) {
		return (n1 < n2) ? n1 : n2;
	}
	private static int getGCD(int n1, int n2) {
		/**
		 * Recursively find the Greatest Common Divisor between n1 and n2.
		 * n1 must be greater than n2 for this to work (Eucledian Algorithm).
		 * 
		 * If either n1 or n2 is the GCD of n1 and n2, then the return value will be
		 * (n2, 0), in which will return the value of the current n2 in the next iteration.
		 * 
		 * But, if neither n1 or n2 is the GCD of n1 and n2, then do the function again
		 * but in this case, use n2 as the new n1, and n1 mod n2 as the new n2.
		 *  
		 * Eventually, the function will find a combination of n2 and n1 mod n2 in which the
		 * n1 mod n2 remainder value will be an integer fraction of n1. This means that the
		 * condition satisfies the requirements in paragraph 2 of this comment, which will
		 * return n1 mod n2 as the GCD.
		 */
		if (n2 == 0) {
			return n1;
		} else {
			return getGCD(n2, (n1 % n2));
		}
	}
	private static int[] getSum(int e1, int d1, int e2, int d2) {
		// Get sum of 2 fractions using pre-defined rules, with gcd division
		int es = (e1 * d2) + (e2 * d1);
		int ds = d1 * d2;
		
		int gcd = getGCD(getMax(es, ds), getMin(es, ds));
		
		es /= gcd;
		ds /= gcd;
		
		// return an array containing es and ds
		int[] res = {es, ds};
		return res;
	}
	private static int[] getProduct(int e1, int d1, int e2, int d2) {
		// Get product of 2 fractions using pre-defined rules, with gcd division
		int ep = e1 * e2;
		int dp = d1 * d2;
		
		int gcd = getGCD(getMax(ep, dp), getMin(ep, dp));
		
		ep /= gcd;
		dp /= gcd;
		
		// return an array containing ep and dp
		int res[] = {ep, dp};
		return res;
	}
	public static int[][] getSumAndProduct(int e1, int d1, int e2, int d2) {
		int[] sum = getSum(e1, d1, e2, d2);
		int[] product = getProduct(e1, d1, e2, d2);
		
		// Use a matrix to store the result of the equations
		int[][] res = {sum, product};
		return res;
	}
}