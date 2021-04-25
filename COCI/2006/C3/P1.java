package COCI;
import java.util.Scanner;

public class COCI_2006_C3_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int[] dwarves = new int[9];
		for (int i = 0; i < 9; i++) {
			dwarves[i] = in.nextInt();
		}
		
		for (int a = 0; a < 3; a++) {
			for (int b = a + 1; b < 4; b++) {
				for (int c = b + 1; c < 5; c++) {
					for (int d = c + 1; d < 6; d++) {
						for (int e = d + 1; e < 7; e++) {
							for (int f = e + 1; f < 8; f++) {
								for (int g = f + 1; g < 9; g++) {
									if (dwarves[a] + dwarves[b] + dwarves[c] + dwarves[d] + 
										dwarves[e] + dwarves[f] + dwarves[g] == 100) {
										System.out.println(dwarves[a]);
										System.out.println(dwarves[b]);
										System.out.println(dwarves[c]);
										System.out.println(dwarves[d]);
										System.out.println(dwarves[e]);
										System.out.println(dwarves[f]);
										System.out.println(dwarves[g]);
									}
								}
							}
						}
					}
				}
			}
		}
	}

}