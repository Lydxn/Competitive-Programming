import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		int[] sums = new int[N];
		sums[0] = Integer.parseInt(br.readLine());
		for (int i = 1; i < sums.length; i++) {
			sums[i] = sums[i - 1] + Integer.parseInt(br.readLine());
		}

		int Q = Integer.parseInt(br.readLine());
		for (int i = 0; i < Q; i++) {
		    StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			System.out.println(sums[b] - (a == 0 ? 0 : sums[a - 1]));
		}
	}
}
