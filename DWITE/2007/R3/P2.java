import java.io.*;
import java.util.*;
import java.util.regex.*;

public class P2 {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			String line = in.nextLine();

			Pattern pattern = Pattern.compile("'([^']*)'|\"([^\"]*)\"|/\\*(.*?)\\*/|//(.*)");
			Matcher matcher = pattern.matcher(line);

			boolean start = true;
			while (matcher.find()) {
				String res = "";
				for (int j = 1; j <= matcher.groupCount(); j++) {
					String group = matcher.group(j);
					if (group != null) {
						res = group;
					}
				}

				System.out.print((start ? "" : " ") + res);
				start = false;
			}
			System.out.println();
		}
	}
}
