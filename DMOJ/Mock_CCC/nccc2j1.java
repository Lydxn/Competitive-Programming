import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String equation = br.readLine();

		int a = Integer.parseInt(equation.substring(0, 1));
		int b = Integer.parseInt(equation.substring(4, 5));
		int c = Integer.parseInt(equation.substring(8, 9));

		System.out.println(a + b == c ? "True" : "False");
    }
}
