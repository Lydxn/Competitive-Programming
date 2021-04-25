package ECOO;
import java.util.*;

public class ECOO_2017_R1_P4 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 10; i++) {
			int N = in.nextInt();
			in.nextLine();
			
			ArrayList<String> names = new ArrayList<String>();
			for (int j = 0; j < N; j++) {
				names.add(in.nextLine());
			}
	
			int minSwaps = Integer.MAX_VALUE;
			for (int j = 0; j < names.size(); j++) {
				String omit = names.remove(j);
				int swaps = swaps(names);
				names.add(j, omit);
				
				if (swaps < minSwaps) {
					minSwaps = swaps;
				}
			}
			System.out.println(minSwaps);
		}
	}

	private static int swaps(ArrayList<String> names) {
		@SuppressWarnings("unchecked")
		ArrayList<String> temp = (ArrayList<String>) names.clone();
		
		int swaps = 0;
		for (int i = 0; i < temp.size(); i++) {
			int min = i;
			for (int j = i + 1; j < temp.size(); j++) {
				if (temp.get(min).compareTo(temp.get(j)) > 0) {
					min = j;
				}
			}

			if (min != i) {
				Collections.swap(temp, i, min);
				swaps++;
			}
		}
		return swaps;
	}

}