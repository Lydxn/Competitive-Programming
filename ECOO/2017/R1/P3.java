package ECOO;
import java.util.Scanner;

public class ECOO_2017_R1_P3 {
	
	static int[] heights;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 10; i++) {
			int N = in.nextInt();
			
			heights = new int[N];
			for (int j = 0; j < heights.length; j++) {
				heights[j] = in.nextInt();
			}

			int maxQuality = 0;
			int maxMountain = 0;
			for (int j = 0; j < heights.length; j++) {
				int quality = quality(j);
				if (quality > maxQuality) {
					maxQuality = quality;
					maxMountain = j;
				}
			}
			System.out.println(maxMountain + 1);
		}
	}
	
	private static int quality(int peak) {
		int visibility = 0;
		for (int i = -1; i <= 1; i += 2) {
			double minSlope = Integer.MAX_VALUE;
			for (int j = peak + i; i == -1 ? j >= 0 : j < heights.length; j += i) {
				double slope = (double) (heights[j] - heights[peak]) / (peak - j) * i;
				if (slope < minSlope) {
					minSlope = slope;
					visibility++;
				}
			}
		}
		return visibility;
	}

}