import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		boolean[] ESieve = ESieve(100000);
		int good = 0;
		
		for (int i = 0; i < N; i++) {
			int x = in.nextInt();
			if (!ESieve[x] && !ESieve[digSum(x)]) {
				good++;
			}
		}
		System.out.println(good);
	}
	
	public static boolean[] ESieve(int lim) {
        boolean[] isComposite = new boolean[lim + 1];
        
        isComposite[1] = true;
        for (int i = 2; i <= lim; i++) {
            if (!isComposite[i]) {
                for (long j = i; i * j <= lim; j++) {
                    isComposite[i * (int) j] = true;
                }
            }
        }
        return isComposite;
    }
	
	private static int digSum(int n) {
		int sum = 0;
		while (n != 0) {
			sum += n % 10;
			n /= 10;
		}
		return sum;
	}
}
