package ccc_2013;
import java.util.Scanner;

public class S3_J5 {

	static boolean[][] played = new boolean[4][4];
	static int T = 0;
	static int wins;
	
	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        T = in.nextInt() - 1; 
        int G = in.nextInt();  
        
        played = new boolean[4][4];
        int[] scores = new int[4];

        for(int i = 0; i < G; i++) {
            int A = in.nextInt() - 1;
            int B = in.nextInt() - 1;
            int SA = in.nextInt();
            int SB = in.nextInt();
            
            played[A][B] = true;
            scores[A] += SA > SB ? 3 : (SA < SB ? 0 : 1);
        	scores[B] += SA > SB ? 0 : (SA < SB ? 3 : 1);
        }
        
       champion(scores, G);
       System.out.println(wins);
    }
	
	public static void champion(int[] scores, int games) {
		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 4 && games < 6; j++) {
				if (!played[i][j]) {
					played[i][j] = true;
					int[] temp = scores.clone();
					
					temp[i] += 3;
					champion(temp, games + 1);
					temp[i] -= 3;

					temp[j] += 3;
					champion(temp, games + 1);
					temp[j] -= 3;

					temp[i]++;
					temp[j]++;
					champion(temp, games + 1);
					temp[i]--;
					temp[j]--;
					
					played[i][j] = false;
					return;
 				}
			}
		}
		
		for (int i = 0; i < scores.length; i++) {
			if (i != T && scores[i] >= scores[T]) {
				return;
			}
		}
		wins++;
	}
	
}
