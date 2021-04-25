import java.util.*;
import java.io.*;

public class J1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int C = in.nextInt();
		int cMax = 0;
		for (int i = 0; i < C; i++) {
			int cRank =  in.nextInt() * in.nextInt();
			if (cMax < cRank) {
				cMax = cRank;
			}
		}

		int N = in.nextInt();
		int nMax = 0;
		for (int i = 0; i < N; i++) {
			int nRank =  in.nextInt() * in.nextInt();
			if (nMax < nRank) {
				nMax = nRank;
			}
		}

		System.out.println(nMax > cMax ? "Natalie" : (nMax < cMax ? "Casper" : "Tie"));
	}


}
