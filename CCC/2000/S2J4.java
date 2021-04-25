package ccc_2000;
import java.util.ArrayList;
import java.util.Scanner;

public class S2_J4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		ArrayList<Float> flow = new ArrayList<Float>();
		for (int i = 0; i < n; i++) {
			flow.add((float) in.nextInt());
		}
		
		while (true) {
			int command = in.nextInt();
			if (command == 99) {
				int split = in.nextInt() - 1;
				int percent = in.nextInt();
				
				flow.add(split + 1, (float) (flow.get(split) * (100 - percent) / 100));
				flow.set(split, (float) (flow.get(split) * percent / 100));
			} else if (command == 88) {
				int join = in.nextInt() - 1;
				
				flow.set(join, flow.get(join) + flow.get(join + 1));
				flow.remove(join + 1);
			} else if (command == 77) {
				for (Float k : flow) {
					System.out.print(Math.round(k) + " ");
				}
				return;
			}
		}
	}

}
