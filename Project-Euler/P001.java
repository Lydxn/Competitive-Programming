package euler100;
import java.util.stream.IntStream;

public class P001 {

	public static void main(String[] args) {
		int sum = IntStream.range(1, 1000).filter(i -> i % 3 == 0 || i % 5 == 0).sum();
		System.out.println(sum);
	}

}
