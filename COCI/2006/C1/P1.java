package COCI;
import java.util.HashSet;
import java.util.Scanner;

public class COCI_2006_C1_P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		HashSet<Integer> modulo = new HashSet<Integer>();
		for (int i = 0; i < 10; i++) {
			modulo.add(in.nextInt() % 42);
		}
		System.out.println(modulo.size());
	}

}
