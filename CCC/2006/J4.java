package ccc_2006;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class J4 {
	
	static ArrayList<Integer> tasks = new ArrayList<Integer>(Arrays.asList(1, 7, 1, 4, 2, 1, 3, 4, 3, 5));
	static int count = Integer.MAX_VALUE;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (true) {
			int before = in.nextInt();
			int after = in.nextInt();
			
			if (before == 0 && after == 0) {
				break;
			}
			
			tasks.add(before);
			tasks.add(after);
		}
		
		permute("", "1234567");
		System.out.println(count == Integer.MAX_VALUE ? "Cannot complete these tasks. Going to bed." : Integer.toString(count).replace("", " ").trim());
	}
	
	private static void permute(String prefix, String order) {
		if (order.isEmpty() && inSchedule(prefix + order) && count > Integer.parseInt(prefix)) {
			count = Integer.parseInt(prefix);
		} else {
			for (int i = 0; i < order.length(); i++) {
				permute(prefix + order.charAt(i), order.substring(0, i) + order.substring(i + 1, order.length()));
			}
		}
	}
	
	private static boolean inSchedule(String order) {
		for (int i = 0; i < tasks.size(); i += 2) {
			if (order.indexOf(Integer.toString(tasks.get(i))) > order.indexOf(Integer.toString(tasks.get(i + 1)))) {
				return false;
			}
		}
		return true;
	}
	
}
