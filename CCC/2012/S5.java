static boolean[][] lab;
	static int[][] cache;
	static int R, C;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		R = in.nextInt();
		C = in.nextInt();
		int K = in.nextInt();
		
		lab = new boolean[R][C];
		cache = new int[R][C];
		
		for (int i = 0; i < K; i++) {
			lab[in.nextInt() - 1][in.nextInt() - 1] = true;
		}
		System.out.println(numPaths(0, 0));
	}
	
	private static int numPaths(int x, int y) {
		if (x >= C || y >= R || lab[y][x]) {
			return 0;
		} else if (x == C - 1 && y == R - 1) {
			return 1;
		} else if (cache[y][x] != 0) {
			return cache[y][x];
		} else {
			return cache[y][x] = numPaths(x + 1, y) + numPaths(x, y + 1);
		}
	}
