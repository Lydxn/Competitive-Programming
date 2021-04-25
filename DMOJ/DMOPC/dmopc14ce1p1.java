import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String verb = in.nextLine();
		String object = in.nextLine();

		char end = object.charAt(object.length() - 1);
		String subject = end == 'e' ? "la" :
						 end == 's' ? "les" :
							 		  "le";

		System.out.printf("%s-tu %s %s ?", verb, subject, object);
	}
}
