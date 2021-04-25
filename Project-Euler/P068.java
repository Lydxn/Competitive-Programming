static String max = "";

	public static void main(String[] args) {
		long a = System.nanoTime();
		byte[] ring = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		permute(ring, 0);
		long b = System.nanoTime();
		System.out.println(max);
		System.out.println(b - a);
	}
	
	private static void permute(byte[] ring, int index) {
		for (int i = index; i < ring.length; i++) {
			swap(ring, i, index);
			permute(ring, index + 1);
			swap(ring, index, i);
		}
		
		if (index == ring.length - 1 && isMagic(ring)) {
			String str = "" + ring[0] + ring[1] + ring[2] + 
						 	  ring[3] + ring[2] + ring[4] + 
						 	  ring[5] + ring[4] + ring[6] + 
						 	  ring[7] + ring[6] + ring[8] +
						 	  ring[9] + ring[8] + ring[1];
			max = max.compareTo(str) > 0 ? max : str;
		}
	}
	
	private static boolean isMagic(byte[] ring) {
		int equality = ring[0] + ring[1] + ring[2];
		return !(ring[1] == 10 || ring[2] == 10 || ring[4] == 10 || ring[5] == 10 || ring[8] == 10 ||
				 ring[0] > ring[3] || ring[0] > ring[5] || ring[0] > ring[7] || ring[0] > ring[9] ||
				 equality != ring[3] + ring[2] + ring[4] ||
				 equality != ring[5] + ring[4] + ring[6] ||
				 equality != ring[7] + ring[6] + ring[8] ||
				 equality != ring[9] + ring[8] + ring[1]);
	}
	
	private static void swap(byte[] ring, int i, int j) {
		byte temp = ring[i];
		ring[i] = ring[j];
		ring[j] = temp;
	}
