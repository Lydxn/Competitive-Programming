package DMOJ;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Problem_Setting_Pandemonium_Junior {

	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		Set<Integer> difficulty = new HashSet<Integer>();
		for (int i = 0; i < N; i++) {
			difficulty.add(in.nextInt());
		}
		System.out.println(difficulty.size());
    }

}
