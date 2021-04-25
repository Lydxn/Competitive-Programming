package COCI;
import java.util.Arrays;
import java.util.Scanner;

public class COCI_2006_C2_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int[] values = {in.nextInt(), in.nextInt(), in.nextInt()};
		Arrays.sort(values);
		in.nextLine();
		
		char[] alphaOrder = in.nextLine().toCharArray();
		int[] numOrder = new int[3];

		for (int i = 0; i < 3; i++) {
			numOrder[i] = (int) (alphaOrder[i]) - 65;
		}
		System.out.println(values[numOrder[0]] + " " + values[numOrder[1]] + " " + values[numOrder[2]]);
	}

}