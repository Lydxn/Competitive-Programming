import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());

		int[] lengths = new int[N];
		for (int i = 0; i < lengths.length; i++) {
			lengths[i] = br.readLine().length();
		}

		int M = Integer.parseInt(br.readLine());
		int[] centres = new int[M];

		for (int l : lengths) {
			int minTime = Integer.MAX_VALUE;
			int minIndex = 0;

			for (int j = 0; j < centres.length; j++) {
				if (centres[j] < minTime) {
					minTime = centres[j];
					minIndex = j;
				}
			}
			centres[minIndex] += l;

			pw.println(minIndex + 1);
			pw.flush();
		}
		pw.close();
 	}
}
