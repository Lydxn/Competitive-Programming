import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		List<Integer> a = new ArrayList<Integer>();
		for (int i = 0; i < K; i++) {
			a.add(Integer.parseInt(br.readLine()));
		}

		long res = 0;
		for (int i = 0; i < a.size() - 2; i++) {
			res += (long) (a.get(i) - (i > 0 ? a.get(i - 1) : 0)) * (N - a.get(i + 2) + 1);
		}
		System.out.println(res);
	}
}
