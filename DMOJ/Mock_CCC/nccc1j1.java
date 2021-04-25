import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		try {
			System.out.println(Integer.toString(Integer.parseInt(in.readLine()) + 1).replaceAll("0", "1"));
		} catch (NumberFormatException | IOException e) {
			e.printStackTrace();
		}
    }
}
