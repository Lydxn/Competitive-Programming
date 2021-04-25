package ccc_2010;
import java.util.Scanner;

public class J2 {

	public static void main(String []args){
	    Scanner in = new Scanner(System.in);
	    int a = in.nextInt();
	    int b = in.nextInt();
	    int c = in.nextInt();
	    int d = in.nextInt();
	    int s = in.nextInt();
	  
	    int nDist = 0;
	    int bDist = 0;
	    int nCount = 0;
	    int bCount = 0;
	  
	    for (int i = 0; i < s && nCount + bCount < s; i++) {
		    if (i % a == 0 && i >= a) {
			    bCount += b;
	        } else {
	    	    nCount += 1;
	        }
	    } 
	  
	    nDist = nCount - bCount;
	  
	    nCount = 0;
	    bCount = 0;
	    for (int j = 0; j < s && nCount + bCount < s; j++) {
	        if (j % c == 0 && j >= c) {
	    	    bCount += d;
	        } else {
	    	    nCount += 1;
	        }
	    }
	    
	    bDist = nCount - bCount;
	    
  	    if (bDist > nDist) {
		    System.out.println("Byron");
	    } else if (nDist > bDist) {
	        System.out.println("Nikky");
	    } else {
	        System.out.println("Tied");
	    }
	}

}
