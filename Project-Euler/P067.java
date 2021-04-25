package euler100;
import java.io.*;
import java.util.StringTokenizer;

public class P067 {
	
	static int max = 0;
	static int[][] triangle = new int[100][];
	static int[][] cache = new int[100][];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("src/txt/p067_triangle.txt"));

		for (int i = 0; i < triangle.length; i++) {
			cache[i] = new int[i + 1];
			triangle[i] = new int[i + 1];
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			for (int j = 0; j < triangle[i].length; j++) {
				triangle[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		System.out.println(routes(0, 0));
	}
	
	private static int routes(int x, int y) {
		return cache[x][y] = cache[x][y] != 0 ? cache[x][y] : triangle[x][y] + (x == 99 ? 0 : Math.max(routes(x + 1, y), routes(x + 1, y + 1)));	
	}
	
}
