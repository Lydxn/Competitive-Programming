package DMOJ;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Max_And_Cards {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int Q = in.nextInt();
		
		for (int i = 0; i < Q; i++) {
			System.out.println(permute(factoradic(N, in.nextLong())));
		}
	}	
	
	private static String permute(int[] factoradic) {
		List<Integer> permutation = new ArrayList<Integer>();
		for (int i = 1; i <= factoradic.length; i++) {
			permutation.add(i);
		}
		
		String res = "";
		for (int i = 0; i < factoradic.length; i++) {
			res += permutation.get(factoradic[i]) + (i == factoradic.length - 1 ? " " : " ");
			permutation.remove(factoradic[i]);
		}
		return res;
	}
	
	private static int[] factoradic(int N, long Q) {
		int[] res = new int[N];
		for (int i = 1; Q != 0; i++) {
			res[N - i] = (int) (Q % i);
			Q /= i;
		}
		return res;
	}
	
}