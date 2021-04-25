import java.io.*;
import java.util.*;
import java.time.LocalDateTime;

public class Main {
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int startX = in.nextInt();
		int startY = in.nextInt();
		int endX = in.nextInt();
		int endY = in.nextInt();
		in.nextLine();

		int seconds = Math.abs(startX - endX) + Math.abs(startY - endY);
		int[] dt = Arrays.stream(in.nextLine().split(":")).mapToInt(Integer::parseInt).toArray();

		LocalDateTime curr = LocalDateTime.of(dt[0], dt[1], dt[2], dt[3], dt[4], dt[5]);
		System.out.println(curr.plusSeconds(seconds).toString().replaceAll("[-T]", ":"));
	}
}
