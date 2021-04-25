import java.io.*;
import java.util.*;

public class dmopc16c1p2 {

	static class Line {
		int m, b;

		public Line(int m, int b) {
			this.m = m;
			this.b = b;
		}

		@Override
		public boolean equals(Object o) {
			Line line = (Line) o;
			return line.m == m && line.b == b;
		}

		@Override
		public int hashCode() {
			return Objects.hash(m, b);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		Set<Line> lines = new HashSet<Line>();
		Map<Integer, Integer> slopes = new HashMap<Integer, Integer>();

		for (int i = 0; i < N; i++) {
			StringTokenizer l = new StringTokenizer(br.readLine());
			int m = Integer.parseInt(l.nextToken());
			int b = Integer.parseInt(l.nextToken());
			Line line = new Line(m, b);

			if (lines.contains(line)) {
				System.out.println("Infinity");
				return;
			}

			lines.add(line);
			slopes.put(m, slopes.containsKey(m) ? slopes.get(m) + 1 : 1);
		}

		long pairs = 0;
		for (int v : slopes.values()) {
			pairs += v * (N - v);
		}
		System.out.println(pairs / 2);
	}

}
