import java.io.*;
import java.util.*;

public class dmpg15b3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int W = in.nextInt();
        int H = in.nextInt();
        in.nextLine();

        int count = 0;
        for (int i = 0; i < H; i++) {
            String line = in.nextLine();
            for (int j = 0; j < line.length(); j++) {
                if (line.charAt(j) == 'o') count++;
            }
            System.out.println(line.replace("o", " ").replace("*", " "));
        }

        for (int i = 0; i < count; i++) System.out.print("o");
    }
}
