package DMOJ;
import java.io.*;
import java.util.*;

public class Favorite_Numbers {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		NavigableMap<Integer, Integer> favourites = new TreeMap<Integer, Integer>();
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			int fav = Integer.parseInt(st.nextToken());
			favourites.put(fav, favourites.containsKey(fav) ? favourites.get(fav) + 1 : 1);
		}
		
		int Q = Integer.parseInt(br.readLine());
		for (int i = 0; i < Q; i++) {
			Map.Entry<Integer, Integer> entry = favourites.ceilingEntry(Integer.parseInt(br.readLine()));
			System.out.println(entry.getKey() + " " + entry.getValue());
		}
	}

}