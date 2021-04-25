import java.io.*;
import java.util.*;

public class CCCJQR_P4 {
    
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		Set<Integer> nums = new HashSet<Integer>(Arrays.asList(1, 2, 6, 20, 70, 252, 924, 3432, 12870, 48620, 184756, 705432));
		for (int i = 1; i <= N; i++) {
		    StringTokenizer st = new StringTokenizer(br.readLine());
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());
			System.out.println(nums.contains(i) ? A - B : A + B);
		}
	}

}
