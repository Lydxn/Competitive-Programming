import java.io.*;
import java.util.*;

public class Main {
    
  @SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		List<Integer>[] ones = new ArrayList[10];
		for (int i = 0; i < ones.length; i++) {
			ones[i] = new ArrayList<Integer>();
		}
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			int a = Integer.parseInt(st.nextToken());
			ones[a % 10].add(a);
		}
		
		for (int i = 0; i < ones.length; i++) {
			Collections.sort(ones[i], Collections.reverseOrder());
		}
		
		for (List<Integer> i : ones) {
			for (int j : i) {
				System.out.print(j + " ");
			}
		}
	}

}
