import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		int x1 = Integer.parseInt(st.nextToken());
		int y1 = Integer.parseInt(st.nextToken());
		int x2 = Integer.parseInt(st.nextToken());
		int y2 = Integer.parseInt(st.nextToken());

		int dx = x - (x < x1 ? x1 : (x > x2 ? x2 : x));
		int dy = y - (y < y1 ? y1 : (y > y2 ? y2 : y));
		System.out.println(String.format("%.3f", Math.sqrt(dx * dx + dy * dy)));
	}


}
