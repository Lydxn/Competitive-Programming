import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

    	Long[] energy = new Long[N];
		for (int i = 0; i < energy.length; i++) {
			energy[i] = in.nextLong();
		}
		Arrays.sort(energy);

		Long[] lengths = new Long[N];
		for (int i = 0; i < lengths.length; i++) {
			lengths[i] = in.nextLong();
		}
		Arrays.sort(lengths);

		long sum = 0;
		for (int i = 0; i < N; i++) {
			sum += energy[i] * lengths[N - i - 1];
		}
		System.out.println(sum);
	}
}
