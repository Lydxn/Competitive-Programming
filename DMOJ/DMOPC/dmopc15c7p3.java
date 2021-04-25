import java.util.Scanner;

public class DMOPC_2015_C7_P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		double C = in.nextInt();
		double S = in.nextInt();
		double P = in.nextInt();

		int N = in.nextInt();
		int sumC = 0, sumS = 0, sumP = 0;

		int[][] attr = new int[N][3];
		for (int i = 0; i < attr.length; i++) {
			sumC += attr[i][0] = in.nextInt();
			sumS += attr[i][1] = in.nextInt();
			sumP += attr[i][2] = in.nextInt();
		}

		double max = 0;
		if (N < 5) {
			max = Math.min(sumC / C, Math.min(sumS / S, sumP / P));
		} else {
			for (int i = 0; i < N; i++) {
				for (int j = i + 1; j < N; j++) {
					for (int k = j + 1; k < N; k++) {
						for (int l = k + 1; l < N; l++) {
							for (int m = l + 1; m < N; m++) {
								sumC = attr[i][0] + attr[j][0] + attr[k][0] + attr[l][0] + attr[m][0];
								sumS = attr[i][1] + attr[j][1] + attr[k][1] + attr[l][1] + attr[m][1];
								sumP = attr[i][2] + attr[j][2] + attr[k][2] + attr[l][2] + attr[m][2];
								max = Math.max(max, Math.min(sumC / C, Math.min(sumS / S, sumP / P)));
							}
						}
					}
				}
			}
		}
		System.out.printf("%.1f\n", Math.min(100, max * 100));
	}

}
