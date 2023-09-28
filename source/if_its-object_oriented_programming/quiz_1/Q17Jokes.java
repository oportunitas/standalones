//File Q17Jokes.java
public class Q17Jokes {
	/**
	 * This class stores the Jokes class.
	 * There would be 2 fields in the class, one storing the string
	 * of the joke sentence itself, and the other being an array
	 * of words in the joke.
	 */
	
	// Fields
	private String jokeSentence; //string of the joke
	private String jokeWord[];
	
	Q17Jokes(String inputJokeSentence) {
		jokeSentence = inputJokeSentence;
		jokeWord = inputJokeSentence.split(" ");
	}
	
	// Setters
	public void setJoke(String inputJokeSentence) {
		// Change the joke to a new sentence
		jokeSentence = inputJokeSentence;
		jokeWord = inputJokeSentence.split(" ");
	}
	
	// Other Methods
	public String isFunny() {
		// Return a string corresponding to length of joke
		if (jokeSentence.length() < 20) {
			return "It's funny";
		} else {
			return "It's not funny";
		}
	}
	public String firstWord() {
		// Return the first word in jokeWord array
		return jokeWord[0];
	}
}