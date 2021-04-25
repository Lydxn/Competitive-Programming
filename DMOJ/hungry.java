package DMOJ;
import java.io.*;
import java.util.*;

public class Hungry {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		Map<Integer, Integer> filling = new TreeMap<Integer, Integer>();
		Map<Integer, Integer> tasty = new TreeMap<Integer, Integer>();
		
		for (int i = 1; i <= N; i++) {
		    StringTokenizer st = new StringTokenizer(br.readLine());
			filling.put(Integer.parseInt(st.nextToken()), i);
			tasty.put(Integer.parseInt(st.nextToken()), i);
		}
		
		for (int f : filling.values()) {
			System.out.print(f + " ");
		}
		System.out.println();
		
		for (int t : tasty.values()) {
			System.out.print(t + " ");
		}
		System.out.println();
	}

}
