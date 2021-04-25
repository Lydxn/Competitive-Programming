package DMOJ;
import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Inaho_V {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		short M = Short.parseShort(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		BigInteger sum = BigInteger.ZERO;
		for (int i = 0; i < M; i++) {
			sum = sum.add(new BigInteger(st.nextToken()));
		}
		System.out.println(sum);
	}

}