package ccc_2009;
import java.util.ArrayList;
import java.util.Scanner;

public class J4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("Enter w: ");
		int w = in.nextInt();
		
		String[] message = {"WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"};
		ArrayList<String> line = new ArrayList<String>();
		int currWords = 0;
		int currLength = 0;
		
		for (int i = 0; i < 6; i++) {
			if (currLength + message[i].length() >= w - currWords + 1) {
				for (int j = 0; j < line.size(); j++) {
					System.out.print(line.get(j) + format(currWords, w - currLength)[j]);
				}
				System.out.println();
				
				currWords = 1;
				currLength = message[i].length();
				line.clear();
				line.add(message[i]);
			} else {
				currLength += message[i].length();
				line.add(message[i]);
				currWords++;
			}
		}
		
		for (int j = 0; j < line.size(); j++) {
			System.out.print(line.get(j) + format(currWords, w - currLength)[j]);
		}
	}
	
	private static String[] format(int currWord, int currLength) {
		int total = 0;
		int[] spaces = new int[currWord];
		String[] dots = new String[currWord];
		
		if (currWord != 1) {
			int average = currLength / (currWord - 1);
			int remainder = currLength % (currWord - 1);
			
			for (int i = 0; i < currWord - 1; i++) {
				if (i < remainder) {
					spaces[i] = average + 1;
					total += average + 1;
				} else {
					spaces[i] = average;
					total += average;
				}
			}
		}
		
		spaces[currWord - 1] = currLength - total;
		for (int j = 0; j < spaces.length; j++) {
			dots[j] = new String(new char[spaces[j]]).replace("\0", ".");
		}
		return dots;
	}

}
