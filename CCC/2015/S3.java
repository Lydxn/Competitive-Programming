package ccc_2015;
import java.util.Scanner;
import java.util.TreeSet;

public class S3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int G = in.nextInt();
		int P = in.nextInt();
		
		TreeSet<Integer> planes = new TreeSet<Integer>();
		for (int i = 1; i <= G; i++) {
			planes.add(i);
		}
		
		int land = 0;
		for (int i = 0; i < P; i++) {
			int range = in.nextInt();
			if (planes.floor(range) == null) {
				break;
			}
			
			planes.remove(planes.floor(range));
			land++;
		}
		System.out.println(land);
	}

}
