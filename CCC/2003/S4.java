import java.util.*;

public class S4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < N; i++) {
			String S = in.nextLine();
			System.out.println(substrings(S));
		}
	}
	
	private static int substrings(String S) { 
		List<String> suffix = new ArrayList<String>();
		for (int i = 0; i < S.length(); i++) {
			suffix.add(S.substring(i));
		}
		Collections.sort(suffix);
		
		int count = suffix.get(0).length() + 1;
		for (int i = 1; i < S.length(); i++) {
			count = count + suffix.get(i).length() - LCP(suffix.get(i), suffix.get(i - 1));
		}
		return count;
	}

	private static int LCP(String s1, String s2) {
		int len = Math.min(s1.length(), s2.length());
		for (int i = 0; i < len; i++) {
			if (s1.charAt(i) != s2.charAt(i)) {
				return i;
			}
		}
		return len;
	}
}
