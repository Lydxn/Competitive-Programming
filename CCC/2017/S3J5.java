package ccc_2017;
import java.util.Scanner;

public class S3_J5 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		int[] woods = new int[2001];
		int[] sums = new int[4001];
		
	    for (int i = 0; i < N; i++) {
	    	woods[in.nextInt()]++;
	    }
	    
	    for (int i = 0; i < woods.length; i++) {
	        if (woods[i] != 0) {
	            for (int j = i; j < woods.length; j++) {
	            	sums[i + j] += i == j ? woods[i] / 2 : Math.min(woods[i], woods[j]);
	            }
	        }
	    }
	    
	    int l = 0;
	    int w = 0;
	    
	    for(int i = 0; i < sums.length; i++) {
	        if (sums[i] > l) {
	            l = sums[i];
	            w = 1;
	        } else if (sums[i] == l) {
	            w++;
	        }
	    }
	    System.out.println(l + " " + w);
	}

}
