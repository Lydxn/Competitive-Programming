package ECOO;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Chocolate {
	String name;
	int P;
	int F;
	int G;
	
	public Chocolate(String name, int P, int F, int G) {
		this.name = name;
		this.P = P;
		this.F = F;
		this.G = G;
	}
}

public class ECOO_2017_R1_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 10; i++) {
			int N = in.nextInt();
			in.nextLine();	
			String currName = in.nextLine();

			Chocolate[] chocolates = new Chocolate[N];
			for (int j = 0; j < N; j++) {
				String name = currName;
				int P = 0;
				int F = 0;
				int G = 0;
				
				while (true) {
					String str = in.next();
					if (str.equals("*")) {
						in.nextLine();
						break;
					} else if (str.equals("J")) {
						P += in.nextInt();
						F += in.nextInt();
						G += in.nextInt();
					} else {
						currName = str;
						in.nextLine();
						break;
					}
				}
				chocolates[j] = new Chocolate(name, P, F, G);
			}

			Arrays.sort(chocolates, new Comparator<Chocolate>() {
				public int compare(Chocolate a, Chocolate b) {
					int aSum = a.P + a.F + a.G;
					int bSum = b.P + b.F + b.G;
					
					if (bSum != aSum) {return Integer.compare(bSum, aSum);}
					if (b.G != a.G)   {return Integer.compare(b.G, a.G);}
					if (b.F != a.F)   {return Integer.compare(b.F, a.F);}
					return Integer.compare(b.P, a.P);
				}
			});

			for (int c = 0; c < chocolates.length; c++) {
				if (!equal(chocolates[0], chocolates[c])) {
					break;
				}
				System.out.print((c != 0 ? "," : "") + chocolates[c].name);
			}
			System.out.println();
		}
	}
	
	private static boolean equal(Chocolate a, Chocolate b) {
		return a.P == b.P && a.F == b.F && a.G == b.G;
	}

}