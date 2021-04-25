package DMOJ;
import java.util.Scanner;

public class Art {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int l1 = in.nextInt();
		int l2 = in.nextInt();
		int l3 = in.nextInt();
		int l4 = in.nextInt();
		int l5 = in.nextInt();
		
		System.out.println(isTri(l1, l2, l3) + isTri(l1, l2, l4) + isTri(l1, l2, l5) + isTri(l1, l3, l4) + isTri(l1, l3, l5) + 
						   isTri(l1, l4, l5) + isTri(l2, l3, l4) + isTri(l2, l3, l5) + isTri(l2, l4, l5) + isTri(l3, l4, l5));
	}
	
	private static int isTri(int a, int b, int c) {
		return a + b > c && b + c > a && a + c > b ? 1 : 0;
	}

}