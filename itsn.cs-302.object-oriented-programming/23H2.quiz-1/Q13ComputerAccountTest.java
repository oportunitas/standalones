// File: Q13ComputerAccountTest.java
import java.util.Scanner;
public class Q13ComputerAccountTest {
	/**
	 * This class is used to test all existing properties,
	 * fields, construstor, getters, and setters present in
	 * class Q13ComputerAccount present in Q13ComputerAccount.java
	 */
	
	public static void main(String[] Args) {
		Scanner cin = new Scanner(System.in);

		// Tells the user to put in real name, username, and password
		System.out.print("Please enter your real name: ");
		String inputRealName = cin.nextLine();
		System.out.print("Please enter your username: ");
		String inputUserName = cin.nextLine();
		System.out.print("Please enter your password: ");
		String inputPassword = cin.nextLine();

		// Create a Q13ComputerAccount instance with the given real name, username, and password
		Q13ComputerAccount myAccount = new Q13ComputerAccount(
				inputRealName, inputUserName, inputPassword);
		
		/**
		 *  Output the stored data in the new instance using the
		 *  Getter functions defined in Q12ComputerAccount.
		 */
		System.out.println();
		System.out.println("Account created succesfully");
		
		System.out.print("Your real name is: ");
		myAccount.printRealName();
		System.out.println();
		System.out.print("Your username is: ");
		myAccount.printUserName();
		System.out.println();
		System.out.print("Your password is: ");
		myAccount.printPassword();
		System.out.println();
		
		// Ask the user on whether they want to change their password, until they say no
		while (true) {
			System.out.print("Would you like to change your password? (Y/N): " );
			String prompt = cin.nextLine();
			
			/** 
			 * If yes, call the getter function changePassword of myAccount
			 * else if no, end the loop.
			 * 
			 * If the input is invalid, try again.
			 */
			if (prompt.equals("y") || prompt.equals("Y")) {
				System.out.print("Please input your new password: ");
				String inputNewPassword = cin.nextLine();
				myAccount.changePassword(inputNewPassword);
			}
			else if (prompt.equals("n") || prompt.equals("N")) {
				break;
			}
			else {
				System.out.println("Invalid input");
			}
		}
	}
}