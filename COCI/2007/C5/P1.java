package COCI;
import java.util.Scanner;

public class COCI_2007_C5_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] num = new int[3];
		for (int i = 0; i < 3; i++) {
			num[i] = in.nextInt();
		}
		
		if (num[0] + num[1] == num[2]) {
			System.out.println(num[0] + "+" + num[1] + "=" + num[2]);
		} else if (num[0] == num[1] + num[2]) {
			System.out.println(num[0] + "=" + num[1] + "+" + num[2]);
		} else if (num[0] - num[1] == num[2]) {
			System.out.println(num[0] + "-" + num[1] + "=" + num[2]);
		} else if (num[0] == num[1] - num[2]) {
			System.out.println(num[0] + "=" + num[1] + "-" + num[2]);
		} else if (num[0] * num[1] == num[2]) {
			System.out.println(num[0] + "*" + num[1] + "=" + num[2]);
		} else if (num[0] == num[1] * num[2]) {
			System.out.println(num[0] + "=" + num[1] + "*" + num[2]);
		} else if (num[0] / num[1] == num[2]) {
			System.out.println(num[0] + "/" + num[1] + "=" + num[2]);
		} else if (num[0] == num[1] / num[2]) {
			System.out.println(num[0] + "=" + num[1] + "/" + num[2]);
		}
	}

}
