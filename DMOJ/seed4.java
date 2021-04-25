package DMOJ;
import java.util.*;
import java.io.*;

class Triple {
	int first;
	int second;
	int third;
	
	public Triple(int first, int second, int third) {
	    this.first = first;
	    this.second = second;
	    this.third = third;
	}
	
	@Override
	public boolean equals(Object obj) {
		Triple t = (Triple) obj;
		return first == t.first && second == t.second && third == t.third; 
	}
	
	@Override
	public int hashCode() {
		return Objects.hash(first, second, third);
	}
}

public class Freedom_Appears {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer f = new StringTokenizer(br.readLine());
		long fX = Long.parseLong(f.nextToken());
		long fY = Long.parseLong(f.nextToken());
		long fZ = Long.parseLong(f.nextToken());
		
		Set<Triple> slopes = new HashSet<Triple>();
		
		int N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
		    StringTokenizer s = new StringTokenizer(br.readLine());
			long sX = Long.parseLong(s.nextToken()) - fX;
			long sY = Long.parseLong(s.nextToken()) - fY;
			long sZ = Long.parseLong(s.nextToken()) - fZ;
			
			long gcd3 = Math.abs(gcd(sX, gcd(sY, sZ)));
			slopes.add(new Triple((int) (sX / gcd3), (int) (sY / gcd3), (int) (sZ / gcd3)));
		}
		System.out.println(slopes.size());
	}
	
	private static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

}