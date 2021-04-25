package DMOJ;
import java.io.*;

public class The_Odd_Number {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		int res = 0;
		for (int i = 0; i < N; i++) {
			res ^= Integer.parseInt(br.readLine());
		}
		System.out.println(res);
	}

}
