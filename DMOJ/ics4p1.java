package DMOJ;
import java.util.*;

public class Word_Scrambler {
	
	static List<String> permutations = new ArrayList<String>();

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String str = in.nextLine();

		permute("", str);
		Collections.sort(permutations);
		
		for (String p : permutations) {
			System.out.println(p);
		}
	}	
	
	private static void permute(String prefix, String str) {
        if (str.length() == 0) {
            permutations.add(prefix);
        } else {
            for (int i = 0; i < str.length(); i++) {
                permute(prefix + str.charAt(i), str.substring(0, i) + str.substring(i + 1));
            }
        }
    }

}