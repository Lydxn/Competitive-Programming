import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();
		
		int[] farms = new int[N];
		for (int i = 0; i < farms.length; i++) {
			farms[i] = in.nextInt();
		}
		Arrays.sort(farms);
		
		long earnings = 0;
		for (int i = N - 1; i >= M; i--) {
			earnings += farms[i];
		}
		System.out.println(earnings);
	}
}
