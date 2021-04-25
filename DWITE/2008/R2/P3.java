import java.io.*;
import java.util.*;

public class P3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			int volume = in.nextInt();

			ArrayList<Integer> factors = new ArrayList<Integer>();
			for (int j = 1; j <= Math.sqrt(volume); j++) {
				if (volume % j == 0) {
					factors.add(j);
					factors.add(volume / j);
				}
			}

			int min = Integer.MAX_VALUE;
			for (int l : factors) {
				for (int w : factors) {
					int h = volume / l / w;
					if (l * w * h == volume) {
						min = Math.min(min, 2 * (l * w + l * h + w * h));
					}
				}
			}
			System.out.println(min);
		}
    }
}
