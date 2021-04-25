import java.io.*;
import java.util.*;

public class P1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int M = in.nextInt();

        if (N % M == 0) {
            System.out.println("yes " + N / M);
        } else {
            int i = 0;
            while (N % M++ != 0) i++;
            System.out.println("no " + i);
        }
    }
}
