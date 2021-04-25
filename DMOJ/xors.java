package DMOJ;
import java.io.*;
import java.util.StringTokenizer;

public class XOR_Sum {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		long min = 0;
		long max = 0;
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			int num = Integer.parseInt(st.nextToken());
			
			min ^= num;
			max += num;
		}
		System.out.println(max - min);
	}

}