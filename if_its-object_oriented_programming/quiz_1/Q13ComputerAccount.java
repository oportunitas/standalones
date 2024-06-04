// File: Q13ComputerAccount.java
public class Q13ComputerAccount {
	/**
	 * In this class, I will declare the 3 strings attributes
	 * as private, and then I will create a constructor that will
	 * set the value of the 3 strings (this means that because
	 * there is no setter for variables realName and userName, 
	 * both of those variables can only be set via passing 
	 * parameters to the class' constructor).
	 */
  
	// Fields
	private String realName;
	private String userName;
	private String password;

	// Constructor
	public Q13ComputerAccount(
	String inputRealName,
	String inputUserName,
    String inputPassword
	) {
		realName = inputRealName;
		userName = inputUserName;
		password = inputPassword;
	}

	// Getters
	public void printRealName() {
		System.out.print(realName);
	}
	public void printUserName() {
		System.out.print(userName);
	}
	public void printPassword() {
		System.out.print(password);
	}

	// Setters
	public void changePassword(String inputPassword) {
		password = inputPassword; // set password to be equal to the input param;
		
		// Tell user that password has changed
		System.out.printf("Password succesfully changed to %s", password);
		System.out.println();
	}
}