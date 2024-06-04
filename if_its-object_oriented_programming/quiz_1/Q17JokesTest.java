// File: Q17JokesTest.java
public class Q17JokesTest {
	public static void main(String[] Args) {
		// Test the input given in the problem
		Q17Jokes myJoke = new Q17Jokes("Knock knock who's there?");
		System.out.println(myJoke.isFunny());
		System.out.println(myJoke.firstWord());
		myJoke.setJoke("Your life");
		System.out.println(myJoke.isFunny());
		System.out.println(myJoke.firstWord());
	}
}