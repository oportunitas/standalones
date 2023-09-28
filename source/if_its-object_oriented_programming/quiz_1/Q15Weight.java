// File: Q15Weight.java
public class Q15Weight {
	/**
	 * This class stores the Weight data.
	 * 
	 * Upon construction, the kilogram value of the inputted pound is
	 * immediately found. The user will only need to just retrieve the data
	 * stored in the private fields of an instance of the class.
	 */
	// Fields
	private double poundVal;
	private double kilogramVal;
	
	// Constructor
	Q15Weight(double inputPoundVal) {
		poundVal = inputPoundVal;
		kilogramVal = poundVal * 0.45359237;
	}
	
	// Getters
	public double getPounds() {
		return poundVal;
	}
	public double getKilograms() {
		return kilogramVal;
	}
}