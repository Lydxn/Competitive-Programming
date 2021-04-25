package ccc_2006;
import java.util.Scanner;

public class S1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String mother = in.nextLine();
		String father = in.nextLine();
		
		int X = in.nextInt();
		in.nextLine();
		for (int i = 0; i < X; i++) {
			String baby = in.nextLine();
			
			boolean child = true;
			for (int j = 0; j < 5; j++) {
				char attr = baby.charAt(j);
				if (((attr > mother.charAt(j << 1) && attr > mother.charAt((j << 1) + 1)) || (attr > father.charAt(j << 1) && attr > father.charAt((j << 1) + 1))) ||
					 (attr < mother.charAt(j << 1) && attr < mother.charAt((j << 1) + 1) && attr < father.charAt(j << 1) && attr < father.charAt((j << 1) + 1))) {
					child = false;
					break;
				}
			}
			System.out.println(child ? "Possible baby." : "Not their baby!");
		}
	}

}
