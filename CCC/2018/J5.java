package ccc_2018;
import java.util.*;

public class J5 {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
        List<int[]> book = new ArrayList<int[]>();

        for (int i = 0; i < N; i++) {
            int M = in.nextInt();
        	book.add(new int[M]);
            for (int j = 0; j < M; j++) {
            	book.get(i)[j] = in.nextInt() - 1;
            } 
        }
        reachable(book, N);
	}
	
	private static void reachable(List<int[]> book, int size) {
        Queue<Integer> queue = new LinkedList<Integer>();
        boolean[] visited = new boolean[size];
        int[] level = new int[size];

        queue.offer(0);
        visited[0] = true;
        level[0] = 1;

        int shortestPath = Integer.MAX_VALUE;
        boolean found = false;
        
        while (!queue.isEmpty()) {
        	int start = queue.poll();
        	int[] page = book.get(start);

        	if (page.length == 0 && !found) {
        		shortestPath = level[start];
        		found = true;
        	}
        	
            for (int i : page) {
                if (!visited[i]) {
                    visited[i] = true;
                    queue.offer(i);
                    level[i] = level[start] + 1;
                }
            }
        }
        
        boolean Y = true;
        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                Y = false;
            }
        }
        System.out.println((!Y ? "N" : "Y") + "\n" + shortestPath);
	}

}
