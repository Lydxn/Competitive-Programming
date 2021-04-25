import java.util.Scanner;

public class P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			String pat = in.nextLine();
			for (int j = 0; j < 16; j++) {
				String bin = toBinaryString(j);
				if (!bin.contains(pat)) {
					System.out.println(bin);
				}
			}
		}
	}

	private static String toBinaryString(int i) {
		String res = Integer.toBinaryString(i);
		while (res.length() < 4) {
			res = "0" + res;
		}
		return res;
	}

}
