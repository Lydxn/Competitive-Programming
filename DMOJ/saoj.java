package DMOJ;
import java.util.Scanner;

public class Sword_Art_Online_Judge {
	
	static final int MOD = 1000000000;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		long res = 1;
		for (long i = 2; i <= N; i++) {
			res = (res + i * i % MOD * i % MOD * i % MOD * i % MOD * i % MOD) % MOD;
		}
		System.out.println(res);
	}

}