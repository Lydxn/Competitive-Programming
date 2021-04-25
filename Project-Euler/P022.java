package euler100;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

public class P022 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("src/txt/p022_names.txt"));
		String[] names = br.readLine().replaceAll("\"", "").split(",");
		br.close();
		
		Arrays.sort(names);
		
		long score = 0;
		for (int i = 0; i < names.length; i++) {
			int value = 0;
			for (int j = 0; j < names[i].length(); j++) {
				value += names[i].charAt(j) - 'A' + 1;
			}
			score += value * (i + 1);
		}
		System.out.println(score);
	}

}
