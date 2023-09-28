// File: Q16Fraction.java
public class Q16Fraction {
	// Fields
	private int e; //enumerator/numerator
	private int d; //denominator
	
	// Constructor
	Q16Fraction(int ie, int id) {
		// ie: input enumerator, id: input denominator
		e = ie;
		d = id;
	}
	
	// Getters
	private int getMax(int n1, int n2) {
		return (n1 > n2) ? n1 : n2;
	}
	private int getMin(int n1, int n2) {
		return (n1 < n2) ? n1 : n2;
	}
	private int getGCD(int n1, int n2) {
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
	
	public int getNumerator() {
		return e;
	}
	public int getDenominator() {
		return d;
	}
	public String getSum(Q16Fraction f) {
		// Get sum of 2 fractions using pre-defined rules, with gcd division
		int es = (e * f.getDenominator()) + (f.getNumerator() * d);
		int ds = d * f.getDenominator();
		
		int gcd = getGCD(getMax(es, ds), getMin(es, ds));
		
		es /= gcd;
		ds /= gcd;
		
		// Return string containing es/ds
		return es + "/" + ds;
	}
	public String getProduct(Q16Fraction f) {
		// Get product of 2 fractions using pre-defined rules, with gdc division
		int ep = e * f.getNumerator();
		int dp = d * f.getDenominator();
		
		int gcd = getGCD(getMax(ep, dp), getMin(ep, dp));
		
		ep /= gcd;
		dp /= gcd;
		
		// Return string containing ep/dp
		return ep + "/" + dp; 
	}
	
	// Other methods
	public String toString() {
		return numerator + "/" + denominator;
	}
}