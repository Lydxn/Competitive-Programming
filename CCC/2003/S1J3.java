package ccc_2003;

import java.util.Scanner;

public class S1_J3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int square = 1;
		while (true) {
			System.out.println("Enter sum of dice:");
			int dice = in.nextInt();
			
			if (dice != 0) {
				if (square + dice <= 100) {
					square += dice;
				} 
				
				switch (square) {
					case 9:  square = 34;
							 break;
					case 40: square = 64;
							 break;
					case 54: square = 19;
							 break;
					case 67: square = 86;
							 break;
					case 90: square = 48;
							 break;
					case 99: square = 77;
							 break;
				}
				System.out.println("You are now on square " + square);
			}
			
			
			if (dice == 0 || square == 100) {
				System.out.println(dice == 0 ? "You Quit!" : "You Win!");
				return;
			}
		}

	}

}
