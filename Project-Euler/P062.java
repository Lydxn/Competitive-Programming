package euler100;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Cube {
	long size;
	int perms;
	
	public Cube(long size, int perms) {
		this.size = size;
		this.perms = perms;
	}
}

public class P062 {

	public static void main(String[] args) {
		Map<String, Cube> cubes = new HashMap<String, Cube>();
		for (int i = 1000; ; i++) {
			String cube = sortPerm((long) i * i * i);
			if (!cubes.containsKey(cube)) {
				cubes.put(cube, new Cube(i, 0));
			}
			
			if (++cubes.get(cube).perms == 5) {
				System.out.println((long) Math.pow(cubes.get(cube).size, 3));
				return;
			}
		}
	}
	
	private static String sortPerm(long n) {
	    char[] charPerm = Long.toString(n).toCharArray();
	    Arrays.sort(charPerm);
	    return new String(charPerm);
	}

}
