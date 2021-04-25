package ccc_2014;
import java.util.Scanner;

public class J3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int rounds = in.nextInt();
		
		int antonia = 100;
		int david = 100;
		
		for (int i = 0; i < rounds; i++) {
			int aRoll = in.nextInt();
			int dRoll = in.nextInt();
			
			if (aRoll > dRoll) {
				david -= aRoll;
			} else if (aRoll < dRoll) {
				antonia -= dRoll;
			}
		}
		
		System.out.println(antonia + "\n" + david);
	}

}
