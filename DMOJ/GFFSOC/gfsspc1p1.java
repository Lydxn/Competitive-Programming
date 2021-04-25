package DMOJ;
import java.util.Scanner;

public class Bruno_And_Trig {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		
		System.out.println(a + b > c && b + c > a && a + c > b ? "Huh? A triangle?" : "Maybe I should go out to sea...");
	}

}