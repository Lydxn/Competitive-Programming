package ECOO;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ECOO_2016_R1_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 10; i++) {
			int N = in.nextInt();
			
			Set<Double> S = new HashSet<Double>();
	        for (int j = 0; j < N; j++) {
	            S.add(in.nextDouble());
	        }
	        
	        int[] T = new int[5];
	        for (int j = 0; j < T.length; j++) {
	            T[j] = in.nextInt();
	        }
	
	        for (double t : T) {
	        	boolean possible = false;
	            for (double j : S) {
	                for (double k : S) {
	                    if (S.contains((t / j) / k) || 
	                    	S.contains((t / j) - k) || 
	                    	S.contains((t - j) / k) || 
	                    	S.contains((t - j) - k)) {
	                        possible = true;
	                    }
	                }
	            }
	            System.out.print(possible ? 'T' : 'F');
	        }
	        System.out.println();
		}
	}

}