package ccc_2000;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class S4 {
	
	static Integer[] power;
	static int[] cache;
	static int target;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		target = in.nextInt();
		int clubs = in.nextInt();
		
		power = new Integer[clubs];
		cache = new int[target + 1];
		
		for (int i = 0; i < power.length; i++) {
			power[i] = in.nextInt();
		}
		Arrays.sort(power, Collections.reverseOrder());
		
		int strokes = shortestWin(0, 0);
		System.out.println(strokes == Integer.MAX_VALUE ? "Roberta acknowledges defeat." : "Roberta wins in " + strokes + " strokes.");
	}
	
	private static int shortestWin(int dist, int strokes) {
		if (dist == target) {
			return strokes;
		} else if (cache[dist] > 0) {
			return cache[dist];
		} else {
			int best = Integer.MAX_VALUE;
			for (int i : power) { 
				if (dist + i <= target) {
					best = Math.min(best, shortestWin(dist + i, strokes + 1));
				}
			}
			return cache[dist] = best;
		}
	}
	
}
