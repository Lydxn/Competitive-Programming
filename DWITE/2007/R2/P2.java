import java.io.*;
import java.util.*;

public class P2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

		int balance = 0;
		main: for (int j = 0; j < 5; j++) {
			String actions = in.nextLine();
			for (int k = 0; k < actions.length(); k++) {
				switch (actions.charAt(k)) {
					case '+':
						balance++;
						break;
					case '-':
						balance--;
						if (balance < 0) {
							System.out.println("OH NOES!");
							balance = 0;
							continue main;
						}
				}
			}
			System.out.println(balance);
		}
    }
}
