import java.io.*;
import java.util.*;

public class P2 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    		float L = Float.parseFloat(br.readLine());
    		float W = Float.parseFloat(br.readLine());

    		System.out.println((int) Math.ceil(L * L * W / 3));
        } catch (IOException | NumberFormatException e) {}
    }
}
