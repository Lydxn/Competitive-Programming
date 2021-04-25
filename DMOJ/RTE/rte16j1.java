import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();

        int count = 0;
        int consec = 0, maxConsec = 0;

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch == 'L') {
                count++;
                consec++;
            } else if (ch != ' ') {
                maxConsec = Math.max(maxConsec, consec);
                consec = 0;
            }
        }

        System.out.println(count + " " + Math.max(consec, maxConsec));
    }
}
