// File: Q14StudentTest.java
import java.util.Scanner;
public class Q14StudentTest {
	public static void main(String[] Args) {
		Scanner cin = new Scanner(System.in);
		
		// Ask user to input name, student ID, and degree programme
		System.out.print("Please input your full name\t\t: ");
		String name = cin.nextLine();
		System.out.print("Please input your student ID\t\t: ");
		String studentID = cin.nextLine();
		System.out.print("Please input your degree programme\t: ");
		String degreeProgramme = cin.nextLine();
		
		// Create a new instance of Q14Student with the given parameters input by user
		Q14Student myStudent = new Q14Student(name, studentID, degreeProgramme);
		
		// Tell user back the stored data in the new Q14Student instance
		System.out.printf("Your full name is\t\t: %s\n", myStudent.getName());
		System.out.printf("Your student ID is\t\t: %s\n", myStudent.getStudentID());
		System.out.printf("Your degree programme is\t: %s\n", myStudent.getDegreeProgramme());
		System.out.printf("Full student data:\n \t %s\n", myStudent.toString());
	}
}