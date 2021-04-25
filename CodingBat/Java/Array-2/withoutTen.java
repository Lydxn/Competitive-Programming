public int[] withoutTen(int[] nums) {
  int[] arr = new int[nums.length];
	int p = 0;
	for (int i : nums) {
		if (i != 10) {
			arr[p] = i;
			p++;
		}
	}
	return arr;
}
