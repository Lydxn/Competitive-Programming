import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		double avg = 0;
		int[] marks = new int[N];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < marks.length; i++) {
			marks[i] = Integer.parseInt(st.nextToken());
			avg += marks[i];
		}
		
		avg /= N;
		Arrays.sort(marks);
		
		System.out.println(marks[(N - 1) / 2] > avg ? "Winnie should take the risk" : "That's too risky");
	}
}
