import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st = new StringTokenizer(br.readLine());
		st.nextToken();
		int M = Integer.parseInt(st.nextToken());

		int[] recieved = new int[M];
		String[] names = new String[M];

		for (int i = 0; i < M; i++) {
		    StringTokenizer docs = new StringTokenizer(br.readLine());
			docs.nextToken();
			recieved[i] = Integer.parseInt(docs.nextToken());
			names[i] = br.readLine();
		}

		int Y = Integer.parseInt(br.readLine());
		for (int i = 0; i < M; i++) {
			if (recieved[i] == Y) {
				System.out.println(names[i]);
			}
		}
	}
}
