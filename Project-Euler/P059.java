package euler100;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

public class P059 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("src/txt/p059_cipher.txt"));
		int[] cipher = Arrays.stream(br.readLine().split(",")).mapToInt(i -> Integer.parseInt(i)).toArray();
		br.close();

		int[] key = probableKey(cipher);
		int[] decrypted = decrypt(cipher, key);
		System.out.println(Arrays.stream(decrypted).sum());
	}
	
	private static int[] decrypt(int[] cipher, int[] key) {
		int[] decrypted = new int[cipher.length];
		for (int i = 0; i < decrypted.length; i++) {
			decrypted[i] = cipher[i] ^ key[i % key.length];
		}
		return decrypted;
	}
	
	private static int[] probableKey(int[] cipher) {
		int[][] freqs = new int[3][127];
		int[] key = new int[3];
		
		for (int i = 0; i < cipher.length; i++) {
			int j = i % 3;
			freqs[j][cipher[i]]++;
			
			if (freqs[j][cipher[i]] > freqs[j][key[j]]) {
				key[j] = cipher[i];
			}
		}
		return Arrays.stream(key).map(i -> i ^ 32).toArray();
	}

}
