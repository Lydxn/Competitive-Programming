package DMOJ;
import java.io.*;
import java.util.StringTokenizer;

public class Discerning_Discounts {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer NT = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(NT.nextToken());
		int T = Integer.parseInt(NT.nextToken());
		
		int count = 0;
		for (int i = 0; i < N; i++) {
		    StringTokenizer cd = new StringTokenizer(br.readLine());
			int c = Integer.parseInt(cd.nextToken());
			int d = Integer.parseInt(cd.nextToken());
			
			if (c - c * (d / 100.0) <= T) {
				count++;
			}
		}
		System.out.println(count);
	}

}
