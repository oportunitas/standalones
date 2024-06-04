// File: Q14Student.java
public class Q14Student {
	// Fields
	private String name;
	private String studentID;
	private String degreeProgramme;
	
	// Constructor
	Q14Student(
		String inputName, 
		String inputStudentID, 
		String inputDegreeProgramme
	) {
		name = inputName;
		studentID = inputStudentID;
		degreeProgramme = inputDegreeProgramme;
	}
	
	// Getters
	public String getName() {
		return name;
	}
	public String getStudentID() {
		return studentID;
	}
	public String getDegreeProgramme() {
		return degreeProgramme;
	}
	
	// Setters
	public void setName(String inputName) {
		name = inputName;
	}
	public void setStudentID(String inputStudentID) {
		studentID = inputStudentID;
	}
	public void setDegreeProgramme(String inputDegreeProgramme) {
		degreeProgramme = inputDegreeProgramme;
	}
	
	// Other Methods
	public String toString() {
		// Return the stored private fields
		String result = "[" + name + ", ID: " + studentID + ", " + degreeProgramme + "]";
		
		return result;
	}
}