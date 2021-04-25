import java.io.*;
import java.util.*;

public class P3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			String link = in.nextLine();
			link = link.substring(link.indexOf("<a"), link.lastIndexOf("</a>") + 4);

			int rel = link.indexOf("rel=\"");
			if (rel == -1) {
				int end = link.indexOf(">");
				System.out.println(link.substring(0, end) + " rel=\"nofollow\"" + link.substring(end));
			} else {
				rel += 5;
				int quote = link.indexOf('"', rel);
				System.out.println(link.substring(rel, quote).equals("nofollow") ? link :
								   (link.substring(0, quote) + (quote > rel ? " " : "") + "nofollow" + link.substring(quote)));
			}
		}
    }
}
