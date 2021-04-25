import java.io.*;
import java.util.*;

public class P3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			int space = in.nextInt();
			int N = in.nextInt();
			int[] playlists = new int[space + 1];

			for (int j = 0; j < N; j++) {
				in.next();
				int rating = in.nextInt();
				int S = in.nextInt();

				for (int k = space; k >= S; k--) {
					playlists[k] = Math.max(playlists[k], playlists[k - S] + rating);
				}
			}
			System.out.println(playlists[space]);
		}
    }
}
