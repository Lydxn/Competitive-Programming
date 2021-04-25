import java.io.*;

public class dmopc16c4p1 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		for (int i = 0; i < N; i++) {
			long I = Long.parseLong(br.readLine());
			System.out.println((I & (I - 1)) == 0 ? 'T' : 'F');
		}
	}

}
