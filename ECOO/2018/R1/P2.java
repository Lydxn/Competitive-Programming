package ECOO;
import java.util.*;

public class ECOO_2018_R1_P2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 10; i++) {
			int N = in.nextInt();
			
			Map<Integer, Integer> IDs = new HashMap<Integer, Integer>();
			for (int j = 0; j < N; j++) {
				int ID = in.nextInt();
				int R = in.nextInt();
				
				int min = Integer.MAX_VALUE;
				for (int k = 0; k < R; k++) {
					min = Math.min(min, in.nextInt());
				}
				IDs.put(ID, min);
			}

			int totalMin = Integer.MAX_VALUE;
			for (Integer m : IDs.values()) {
				totalMin = Math.min(totalMin, m);
			}
			
			List<Integer> issues = new ArrayList<Integer>();
			for (Map.Entry<Integer, Integer> entry : IDs.entrySet()) {
				if (entry.getValue() == totalMin) {
					issues.add(entry.getKey());
				}
			}
			
			System.out.print(totalMin + " {");
			
			String res = "";
			for (int j : issues) {
				res += j + " ";
			}
			
			System.out.println(res.trim().replace(" ", ",") + "}"); 
		}
	}

}