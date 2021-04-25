package ccc_2007;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class S2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		int[][] boxes = new int[n][3];
		for (int i = 0; i < boxes.length; i++) {
			for (int j = 0; j < boxes[0].length; j++) {
				boxes[i][j] = in.nextInt();
			}
			Arrays.sort(boxes[i]);
		}
		
		Arrays.sort(boxes, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] * a[1] * a[2] - b[0] * b[1] * b[2];
			}
		});

		int m = in.nextInt();
		int[][] items = new int[m][3];
		for (int i = 0; i < items.length; i++) {
			for (int j = 0; j < items[0].length; j++) {
				items[i][j] = in.nextInt();
			}
			Arrays.sort(items[i]);
		}
		
		outer: for (int i = 0; i < items.length; i++) {
			for (int j = 0; j < boxes.length; j++) {
				if (items[i][0] <= boxes[j][0] && items[i][1] <= boxes[j][1] && items[i][2] <= boxes[j][2]) {
					System.out.println(boxes[j][0] * boxes[j][1] * boxes[j][2]);
					continue outer;
				}
			}
			System.out.println("Item does not fit.");
		}
	}

}
