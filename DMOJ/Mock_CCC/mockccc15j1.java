import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
		String area = str[0];
		String local = str[1];
		
		if (area.equals("416") && local.length() == 7) {
			System.out.println("valuable");
		} else if ((area.equals("647") || area.equals("437")) && local.length() == 7) {
			System.out.println("valueless");
		} else {
			System.out.println("invalid");
		}
    }
}
