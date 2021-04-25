package ccc_2000;
import java.util.Scanner;

public class S1_J3 {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int quarters = in.nextInt();
		
		int[] played = new int[3];
		int[] win = {30, 60, 9};
		int[] time = {35, 100, 10};
		
		for (int i = 0; i < played.length; i++) {
			played[i] = in.nextInt();
		}
		
		int count = 0;
		int machine = 0;
		while (quarters != 0) {
			played[machine]++;
			if (played[machine] == time[machine]) {
				played[machine] = 0;
				quarters += win[machine];
			}
			
			machine = (machine + 1) % 3;
			count++;
			quarters--;
		}
		System.out.println("Martha plays " + count + " times before going broke.");
	}
	
}
