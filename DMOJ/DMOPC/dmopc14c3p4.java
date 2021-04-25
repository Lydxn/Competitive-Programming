import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();

		List<Integer>[] numFactors = numFactors(100000);
		for (int i = 0; i < T; i++) {
			int K = in.nextInt();
			int A = in.nextInt();
			int B = in.nextInt();

			if (A > B) {
				int temp = A;
				A = B;
				B = temp;
			}
			System.out.println(bound(numFactors[K], B, 'u') - bound(numFactors[K], A, 'l'));
		}
	}

	private static List<Integer>[] numFactors(int lim) {
		int[] factors = new int[lim + 1];

		for (int i = 1; i <= lim; i++) {
			for (int j = i; j < lim; j += i) {
				factors[j]++;
			}
		}

		@SuppressWarnings("unchecked")
		List<Integer>[] numFactors = new ArrayList[lim + 1];
		for (int i = 0; i < numFactors.length; i++) {
			numFactors[i] = new ArrayList<Integer>();
		}

		for (int i = 1; i < numFactors.length; i++) {
			numFactors[factors[i]].add(i);
		}
		return numFactors;
	}

	public static int bound(List<Integer> list, int val, char c) {
        int low = 0;
        int high = list.size();

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (c == 'l') {
            	if (list.get(mid) < val) {
            		low = mid + 1;
            	} else {
            		high = mid;
            	}
            } else {
            	if (list.get(mid) > val) {
            		high = mid;
            	} else {
            		low = mid + 1;
            	}
            }
        }
        return low;
    }
}
