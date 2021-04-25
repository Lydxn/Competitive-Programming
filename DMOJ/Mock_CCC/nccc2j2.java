import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try {
    		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    		String[] input = new String[2];
    		input = br.readLine().split(" ");
    		int n = Integer.parseInt(input[0]);
    		int m = Integer.parseInt(input[1]);

    		String[] rows = new String[n];
    		char[][] arr = new char[n][m];

    		for (int i = 0; i < n; i++) {
    			rows[i] = br.readLine();
    			for (int j = 0; j < m; j++) {
    				arr[i][j] = rows[i].charAt(j);
    			}
    		}

    		for (int k = 0; k < n; k++) {
    			for (int l = 0; l < m; l++) {
    				System.out.print(swap(arr)[k][l]);
    			}
    			System.out.println();
    		}
        } catch (IOException | NumberFormatException e) {}
	}

	public static char[][] swap(char[][] arr) {
		for (int times = 0; times < 49; times++) {
			for (int i = 0; i < arr.length - 1; i++) {
				for (int j = 0; j < arr[0].length; j++) {
					if (arr[i][j] == 'o' && arr[i + 1][j] == '.') {
						arr[i][j] = '.';
						arr[i + 1][j] = 'o';
					}
				}
			}
		}
		return arr;
	}
}
