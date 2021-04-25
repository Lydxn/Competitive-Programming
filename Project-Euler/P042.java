package euler100;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class P042 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("src/txt/p042_words.txt"));
		String[] words = br.readLine().replaceAll("\"", "").split(",");
		br.close();
		
		int triangle = 0;
		for (String i : words) {
			int n = 0;
			for (int j = 0; j < i.length(); j++) {
				n += i.charAt(j) - 'A' + 1;
			}
			
			if (isTriangle(n)) {
				triangle++;
			}
		}
		System.out.println(triangle);
	}
	
	private static boolean isTriangle(int n) {
		double triangle = (Math.sqrt(1 + 8 * n) - 1) / 2;
		return triangle == (int) triangle;
	}

}

