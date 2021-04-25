package DMOJ;
import java.io.*;

public class Character_Analysis {

	public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] begin = br.readLine().toCharArray();
		char[] end = br.readLine().toCharArray();
		byte[] keys = new byte[127];
		
		for (int b : begin) {
			keys[b % 127]++;
		}
		
		for (int e : end) {
			keys[e % 127]--;
		}
		
		for (int i = 0; i < keys.length; i++) {
			if (keys[i] != 0) {
				System.out.println((char) i);
				return;
			}
		}
	}

}