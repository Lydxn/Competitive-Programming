import java.util.Scanner;

public class J3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < N; i++) {
			String symbols = in.nextLine();
			
			int consec = 1;
			for (int j = 0; j < symbols.length(); j++) {
				char ch = symbols.charAt(j);
				if (j < symbols.length() - 1 && symbols.charAt(j + 1) == ch) {
					consec++;
				} else {
					System.out.print(consec + " " + ch + " ");
					consec = 1;
				}
			}
			System.out.println();
		}
	}

}
