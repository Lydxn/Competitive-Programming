import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		boolean[] coders = new boolean[N + 1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			coders[Integer.parseInt(st.nextToken())] = true;
		}
		
		int sources = 0;
		for (int i = 0; i < coders.length; i++) {
			if (!coders[i]) {
				sources++;
			}
		}
		System.out.println(sources);
	}
}
