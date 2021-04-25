import java.util.*;

public class J5 {
	
	static String[][] rules = new String[3][2];

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		for (int i = 0; i < 3; i++) {
			rules[i] = in.nextLine().split(" ");
		}
		
		int S = in.nextInt();
		String I = in.next();
		String F = in.next();
		
		@SuppressWarnings("unchecked")
		Set<String>[] cache = new HashSet[16];
		for (int i = 0; i < cache.length; i++) {
			cache[i] = new HashSet<String>();
		}
		findSequence(S, I, F, new Stack<String>(), cache);
	}
	
	private static void findSequence(int S, String I, String F, Stack<String> sequence, Set<String>[] cache) {
		if (I.equals(F) && S == 0) {
			for (String s : sequence) {
				System.out.println(s);
			}
			System.exit(0);
		} else if (!cache[S].contains(I) && S > 0) {
			for (int i = 0; i < rules.length; i++) {
				String check = rules[i][0];
				for (int j = 0; j <= I.length() - check.length(); j++) {
					if (I.substring(j, j + check.length()).equals(check)) {
						String res = new StringBuilder(I).replace(j, j + check.length(), rules[i][1]).toString();
						cache[S].add(I);
						
						sequence.push((i + 1) + " " + (j + 1) + " " + res);
						findSequence(S - 1, res, F, sequence, cache); 
						sequence.pop();
					}	
				}
			}
		}
	}

}
