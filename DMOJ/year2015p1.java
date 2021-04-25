package DMOJ;
import java.util.Scanner;

public class Invitation_Devastation {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String template = in.nextLine();
		int N = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < N; i++) {
			String invitee = in.nextLine();
			System.out.println(template.replaceAll(">", invitee));
		}
	}

}