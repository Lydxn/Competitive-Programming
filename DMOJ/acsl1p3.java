import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class acsl1p3 {
	
	public static void main(String[] args) {
		Scanner BILL = new Scanner(System.in);
		int bill = BILL.nextInt();
		BigInteger BiLLbIll = BigInteger.ONE;
		for (int billll = 2; billll <= bill; billll++)
			BiLLbIll = BiLLbIll.multiply(BigInteger.valueOf(billll));
		int billBiLL = 0;
		String billlLLLBiLL = BiLLbIll.toString();
		for (int bILL = 0; bILL < billlLLLBiLL.length(); bILL++)
			if (billlLLLBiLL.charAt(bILL) == '0') ++billBiLL;
		System.out.println(billBiLL);
	}
}

