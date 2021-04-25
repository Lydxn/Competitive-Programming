package DMOJ;
import java.io.*;
import java.util.StringTokenizer;

public class Marathon {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer NQ = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(NQ.nextToken());
		int Q = Integer.parseInt(NQ.nextToken());
		
		int[] ratings = new int[N + 1];		
		StringTokenizer r = new StringTokenizer(br.readLine());
		ratings[1] = Integer.parseInt(r.nextToken());
		
		for (int i = 2; i < ratings.length; i++) {
			ratings[i] = Integer.parseInt(r.nextToken()) + ratings[i - 1];
		}
		
		int sum = ratings[ratings.length - 1];
		for (int i = 0; i < Q; i++) {
		    StringTokenizer ab = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(ab.nextToken());
			int b = Integer.parseInt(ab.nextToken());
			
			System.out.println(sum - ratings[b] + ratings[a - 1]);
		}
	}

}