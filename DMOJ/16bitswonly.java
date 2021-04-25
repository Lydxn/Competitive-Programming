import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
		    StringTokenizer st = new StringTokenizer(br.readLine());
			long A = Long.parseLong(st.nextToken());
			long B = Long.parseLong(st.nextToken());
			long P = Long.parseLong(st.nextToken());
			
			System.out.println(A * B == P ? "POSSIBLE DOUBLE SIGMA" : "16 BIT S/W ONLY");
		}
	}


}
