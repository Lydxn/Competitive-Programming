package DMOJ;
import java.util.Scanner;

public class Food_Lines {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();
		
		int[] lines = new int[N];
		for (int i = 0; i < lines.length; i++) {
			lines[i] = in.nextInt();
		}
		
		for (int i = 0; i < M; i++) {
			int min = Integer.MAX_VALUE;	
			int minJ = 0;
			
			for (int j = 0; j < lines.length; j++) {
				if (min > lines[j]) {
					min = lines[j];
					minJ = j;
				}
			}
			
			System.out.println(min);
			lines[minJ]++;
		}
	}

}