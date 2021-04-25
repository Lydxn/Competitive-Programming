package DMOJ;
import java.util.Scanner;

public class SC2_Multitasking {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		String[] keyboard = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
		int res = 0;
		
		for (int i = 0; i < N; i++) {
			String word = in.nextLine();
			
			boolean[] rows = new boolean[keyboard.length];
			for (int j = 0; j < word.length(); j++) {
				char ch = word.charAt(j);
				for (int k = 0; k < keyboard.length; k++) {
					if (keyboard[k].indexOf(ch) != -1) {
						rows[k] = true;
					}
				}
			}
			
			if ((rows[0] && !rows[1] && !rows[2]) || 
				(!rows[0] && rows[1] && !rows[2]) || 
				(!rows[0] && !rows[1] && rows[2])) {
				res++;
			}
		}
		System.out.println(res);
	}

}