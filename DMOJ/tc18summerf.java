package DMOJ;
import java.math.BigInteger;
import java.util.Scanner;

public class Forget_Me_Not {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String S = in.nextLine();
		String T = in.nextLine();
		
		BigInteger bigS = new BigInteger(S);
		BigInteger bigT = new BigInteger(T);
		
		int compare = bigS.compareTo(bigT);
		System.out.println(compare == 1 ? 'S' : (compare == -1 ? 'T' : 'E'));
	}

}