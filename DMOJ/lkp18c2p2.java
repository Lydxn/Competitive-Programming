package DMOJ;
import java.util.Scanner;

public class Secret_Signal {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();
		
		int[] arr = new int[N];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = in.nextInt();
		}
		
		int[] counter = new int[K];
		counter[0] = 1;
		
		long res = 0;
		long sum = 0;
		
		for (int a : arr) {
			sum += a;
			res += counter[(int) (sum % K)]++;
		}
		System.out.println(res);
	}

}
