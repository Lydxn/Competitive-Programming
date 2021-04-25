package DMOJ;
import java.util.*;
import java.io.*;

public class Literature_Club {

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer NK = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(NK.nextToken());
		int K = Integer.parseInt(NK.nextToken());
		int W = Integer.parseInt(br.readLine());
		
		Set<String>[] triggers = new HashSet[4];
		for (int i = 0; i < triggers.length; i++) {
			triggers[i] = new HashSet<String>();
		}
		
		for (int i = 0; i < triggers.length; i++) {
			StringTokenizer trigger = new StringTokenizer(br.readLine());
			for (int j = 0; j < W; j++) {
			    triggers[i].add(trigger.nextToken());
			}
		}
		
		Set<String> words = new HashSet<String>();
		for (int i = 0; i < N; i++) {
			StringTokenizer sentence = new StringTokenizer(br.readLine());
			for (int j = 0; j < K; j++) {
			    words.add(sentence.nextToken());
			}
		}
		
		int[] closeness = new int[4];
		for (String w : words) {
			for (int i = 0; i < triggers.length; i++) {
				if (triggers[i].contains(w)) {
					closeness[i]++;
				}
			}
		}
		
		int max = 0;
		for (int c : closeness) {
		    max = Math.max(max, c);
		}
		
		if (max == 0) {
			return;
		}
		
		String[] names = {"Sayori", "Natsuki", "Yuri", "Monika"};
		for (int i = 0; i < closeness.length; i++) {
			if (closeness[i] == max) {
				System.out.println(names[i]);
			}
		}
	}

}
