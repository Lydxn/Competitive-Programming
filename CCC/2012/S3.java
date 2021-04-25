package ccc_2012;
import java.util.*;
import java.util.Map.Entry;

public class S3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		HashMap<Integer, Integer> readings = new HashMap<Integer, Integer>();
		for (int i = 0; i < N; i++) {
			int reading = in.nextInt();
			readings.put(reading, readings.get(reading) == null ? 1 : readings.get(reading) + 1);
		}

		List<Integer> high1 = highs(readings);
		readings.values().removeAll(Collections.singleton(Collections.max(readings.values())));
		List<Integer> high2 = highs(readings);

		if (high1.size() > 1) {
			System.out.println(Math.abs(high1.get(0) - high1.get(high1.size() - 1)));
		} else {
			int maxDiff = 0;
			for (int i : high2) {
				maxDiff = Math.max(maxDiff, Math.abs(i - high1.get(0)));
			}
			System.out.println(maxDiff);
		}
	}
	
	private static ArrayList<Integer> highs(HashMap<Integer, Integer> readings) {
		if (readings.isEmpty()) {
			return new ArrayList<Integer>();
		}
		
		int maxValue = Collections.max(readings.values());
		ArrayList<Integer> highs = new ArrayList<Integer>();
		for (Entry<Integer, Integer> entry : readings.entrySet()) {
			if (entry.getValue() == maxValue) {
				highs.add(entry.getKey());
			}
		}
		return highs;
	}
	
}
