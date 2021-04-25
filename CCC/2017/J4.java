package ccc_2017;
import java.util.Scanner;

public class J4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		long D = in.nextLong();
		long i = 0;
		int sequence = 0;
		int time = 1200;
		while (i <= D) {
			if (time > 1259) {
				time = 100;
			} else if (time % 100 > 59) {
				time = time / 100 * 100 + 100;
			}
			
			if (arithmetic(time)) {
				sequence++;
			}
			
			if (D > 1439) {
				int rep = (int) (D / 1440);
				sequence += rep * 62;
				D -= rep * 1440;
			}

			time++;
			i++;
		}
		System.out.println(sequence);
	}
	
	private static boolean arithmetic(int time) {
		String timeStr = Integer.toString(time);
		int diff = Integer.valueOf(timeStr.charAt(0) - timeStr.charAt(1));
		
		for (int i = 1; i < timeStr.length() - 1; i++) {
			if (Integer.valueOf(timeStr.charAt(i)) - Integer.valueOf(timeStr.charAt(i + 1)) != diff) {
				return false;
			}
		}
		return true;
	}

}
