package ccc_2013;
import java.util.Arrays;
import java.util.Scanner;

public class J4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int C = in.nextInt();
		
		int[] chores = new int[C];
		for (int i = 0; i < C; i++) {
			chores[i] = in.nextInt();
		}
		
		int finishedChores = 0;
		Arrays.sort(chores);
		
		for (int j = 0; j < chores.length; j++) { 
			int minutes = chores[j];
			
			if (minutes <= T) {
				finishedChores++;
				T -= minutes;
			} else {
				j = chores.length;
			}
		}
		System.out.println(finishedChores);

 	}

}
