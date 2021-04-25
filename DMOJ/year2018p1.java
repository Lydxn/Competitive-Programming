package DMOJ;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class Happy_New_Year {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int h = in.nextInt();
		int m = in.nextInt();
		int s = in.nextInt();
		
		long totalSecs = 3600L * h + 60L * m + s;
		DateTimeFormatter dtFormat = DateTimeFormatter.ofPattern("hh:mm:ss");
		
		String res = dtFormat.format(LocalTime.of(12, 0, 0).minusSeconds(totalSecs));
		System.out.println(res.substring(0, 2).equals("12") ? "00" + res.substring(2) : res);
	}

}
