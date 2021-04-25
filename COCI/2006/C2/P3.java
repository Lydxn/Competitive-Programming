package COCI;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class COCI_2006_C2_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N1 = in.nextInt();
		int N2 = in.nextInt();
		in.nextLine();
		
		String ants1 = new StringBuilder(in.nextLine()).reverse().toString();
		String ants2 = in.nextLine();
		
		Map<Character, Boolean> map = new HashMap<Character, Boolean>();
		for (int i = 0; i < N1; i++) {
			map.put(ants1.charAt(i), true);
		}
		
		for (int i = 0; i < N2; i++) {
			map.put(ants2.charAt(i), false);
		}
		
		char[] ants = (ants1 + ants2).toCharArray();
		
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			for (int j = 0; j < ants.length - 1; j++) {
				if (map.get(ants[j]) && !map.get(ants[j + 1])) {
					char temp = ants[j];
					ants[j] = ants[j + 1];
					ants[j + 1] = temp;
					j++;
				}
			}
		}
		
		for (char c : ants) {
			System.out.print(c);
		}
		System.out.println();
	}
	
}