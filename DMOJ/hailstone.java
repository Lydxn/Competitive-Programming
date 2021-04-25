package DMOJ;
import java.util.Scanner;

public class Hailstone_Numbers {

	public static void main(String[] args) {	
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		int operations = 0;
		while (n != 1) {
			n = (n & 1) == 0 ? n >> 1 : n * 3 + 1;
			operations++;
		}
		System.out.println(operations);
	}

}
