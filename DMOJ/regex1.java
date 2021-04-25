package DMOJ;
import java.text.*;
import java.util.Scanner;
import java.util.regex.*;

public class Find_Dates {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd");
		format.setLenient(false);
		
		for (int i = 0; i < N; i++) {
			String line = in.nextLine();
			Matcher matcher = Pattern.compile("\\b\\d\\d\\d\\d-\\d\\d-\\d\\d\\b").matcher(line);
			
			while (matcher.find()) {
				String group = matcher.group();
				try {
					format.parse(group);
					System.out.println(group);
				} catch (ParseException e) {}
			}
		}
	}	

}
