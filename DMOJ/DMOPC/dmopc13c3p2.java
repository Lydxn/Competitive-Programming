import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int S = in.nextInt();
		in.nextLine();
		String format = in.nextLine().replace("/", "-").replace(" ", "T");

		LocalDateTime curr = LocalDateTime.parse(format, DateTimeFormatter.ISO_LOCAL_DATE_TIME);
		curr = curr.minusHours(S);
		System.out.println(curr.format(DateTimeFormatter.ISO_LOCAL_DATE_TIME).toString()
							   .replace("-", "/").replaceAll("T", " "));
	}

}
