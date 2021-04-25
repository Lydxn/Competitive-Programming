package COCI;
import java.io.*;
import java.util.StringTokenizer;

public class COCI_2007_C3_P4 {

	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		long[] X = new long[100001];
		long[] Y = new long[100001];
		int[] pX = new int[N];
		int[] pY = new int[N];
		
		for (int i = 0; i < N; i++) {
		    StringTokenizer st = new StringTokenizer(br.readLine());
			X[pX[i] = Integer.parseInt(st.nextToken())]++;
			Y[pY[i] = Integer.parseInt(st.nextToken())]++;
		}
		
		long count = 0;
		for (int j = 0; j < N; j++) {
			count += (long) (X[pX[j]] - 1) * (long) (Y[pY[j]] - 1);
		}
		System.out.println(count);
	}
	
}