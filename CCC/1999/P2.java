package ccc_1999;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class P2 {
	
	static ArrayList<String> months = new ArrayList<String>(Arrays.asList("January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"));
	static Matcher matcher;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < n; i++) {
			String line = in.nextLine();
			line = dmy(ymd(mdy(line)));
			System.out.println(line);
		}
	}

	private static String dmy(String line) {
		Pattern pattern = Pattern.compile("\\b(0[1-9]|[1-2][0-9]|3[0-1])\\/(0[1-9]|1[1-2])\\/([0-9][0-9])\\b");
		Matcher matcher = pattern.matcher(line);

		return matcher.replaceAll(i -> i.group(1) + "/" + i.group(2) + "/" + (Integer.parseInt(i.group(3)) >= 25 ? "19" : "20") + i.group(3));
	}
	
	private static String ymd(String line) {
		Pattern pattern = Pattern.compile("\\b([0-9][0-9])\\.(0[1-9]|1[1-2])\\.(0[1-9]|[1-2][0-9]|3[0-1])\\b");
		Matcher matcher = pattern.matcher(line);
		
		return matcher.replaceAll(i -> (Integer.parseInt(i.group(1)) >= 25 ? "19" : "20") + i.group(1) + "." + i.group(2) + "." + i.group(3));
	}

	private static String mdy(String line) {
		Pattern pattern = Pattern.compile("\\b(January|February|March|April|May|June|July|August|September|October|November|December) (0[1-9]|[1-2][0-9]|3[0-1])\\, ([0-9][0-9])\\b");
		Matcher matcher = pattern.matcher(line);
		
		return matcher.replaceAll(i -> i.group(1) + " " + i.group(2) + ", " + (Integer.parseInt(i.group(3)) >= 25 ? "19" : "20") + i.group(3));
	}
	
}
