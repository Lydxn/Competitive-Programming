import java.io.*;
import java.util.*;

class Veteran {
	String name;
	int skill;

	public Veteran(String name, int skill) {
		this.name = name;
		this.skill = skill;
	}
}

public class P3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		Veteran[] veterans = new Veteran[N];
		for (int i = 0; i < N; i++) {
			veterans[i] = new Veteran(in.next(), in.nextInt());
		}

		int Q = in.nextInt();
		for (int i = 0; i < Q; i++) {
			int s = in.nextInt();
			int d = in.nextInt();

			String minName = "No suitable teacher!";
			int minSkill = Integer.MAX_VALUE;

			for (Veteran v : veterans) {
				if (s <= v.skill && v.skill <= s + d && minSkill > v.skill) {
					minSkill = v.skill;
					minName = v.name;
				}
			}
			System.out.println(minName);
		}
	}

}
