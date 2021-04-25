import java.io.*;
import java.util.*;

public class dmpg15b1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        in.nextLine();

        for (int i = 0; i < N; i++) {
            String number = in.nextLine();
            if (number.length() != 10) {System.out.println("not a phone number"); continue;}
            String area = number.substring(0, 3);
            if ((area.equals("416") || area.equals("647"))) {
                System.out.println("(" + area + ")-" + number.substring(3, 6) + "-" + number.substring(6));
            } else {
                System.out.println("not a phone number");
            }
        }
    }
}
