import java.io.*;
import java.util.*;

public class dmopc18c1p2 {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();
		
		int[] P = new int[N];
		for (int i = 0; i < N; i++) {
			P[i] = in.nextInt();
		}
		
		for (int i = 0; i < K; i++) {
			int[] A = new int[1 + (N - i - 1) / K];

			for (int j = i, index = 0; j < N; j += K, index++) {
				A[index] = P[j];
			}
			
			Arrays.sort(A);

			for (int j = i, index = 0; j < N; j += K, index++) {
				P[j] = A[index];
			}
		}
		
		for (int i = 0; i < N - 1; i++) {
			if (P[i] > P[i + 1]) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}
}
