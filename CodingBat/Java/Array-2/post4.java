public int[] post4(int[] nums) {
  int p = nums.length - 1;
	int[] arr;
	while (nums[p] != 4) {
		p--;
	}

	arr = new int[nums.length - 1 - p];
	for (int i = p + 1; i < nums.length; i++) {
		arr[i - p - 1] = nums[i];
	}
	return arr;
}
