package DMOJ;
import java.util.Scanner;

public class Better_Censor {

	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();
        
        for (int i = 0; i < n; i++) {
            System.out.println(in.nextLine().replaceAll("\\b(\\w\\w\\w\\w)\\b", "****"));
        }
    }

}
