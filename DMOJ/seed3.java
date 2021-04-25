package DMOJ;
import java.io.*;
import java.util.StringTokenizer;

public class Battle_Positions {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int I = Integer.parseInt(br.readLine());
		int N = Integer.parseInt(br.readLine());
		int J = Integer.parseInt(br.readLine());
		
		int[] stations = new int[I + 1];
		for (int i = 0; i < J; i++) {
		    StringTokenizer st = new StringTokenizer(br.readLine());
			int Xi = Integer.parseInt(st.nextToken()) - 1;
			int Xf = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken());
			
			stations[Xi] += K;
			stations[Xf] -= K;
		}
		
		for (int i = 1; i < I; i++) {
			stations[i] += stations[i - 1];
		}
		
		int insecure = 0;
		for (int i = 0; i < I; i++) {
			if (stations[i] < N) {
				insecure++;
			}
		}
		System.out.println(insecure);
	}

}