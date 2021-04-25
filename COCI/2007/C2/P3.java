package COCI;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class COCI_2007_C2_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int R = in.nextInt();
		int C = in.nextInt();
		
		char[][] cw = new char[R][];
		LinkedList<String> words = new LinkedList<String>();
		
		for (int i = 0; i < R; i++) {
			String row = in.next();
			cw[i] = row.toCharArray();
			
			String[] split = row.split("#");
			for (int j = 0; j < split.length; j++) {
				if (split[j].length() >= 2) {
					words.add(split[j]);
				}
			}
		}
		
		for (int k = 0; k < C; k++) {
			String str = "";
			for (int l = 0; l < R; l++) {
				str += cw[l][k];
			}
			
			String[] split = str.split("#");
			for (int m = 0; m < split.length; m++) {
				if (split[m].length() >= 2) {
					words.add(split[m]);
				}
			}
		}
		Collections.sort(words);
		System.out.println(words.get(0));
	}

}