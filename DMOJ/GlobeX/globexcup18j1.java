import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		int up = 0;
		int down = 0;
		
		for (int i = 0; i < N; i++) {
			double X = Double.parseDouble(br.readLine());
			if ((int) X + 0.5 <= X) {
				up++;
			} else {
				down++;
			}
		}
		System.out.println(up + "\n" + down);
	}
}
