public int[] tenRun(int[] nums) {
  int tenMode = -1;
	for (int i = 0; i < nums.length; i++) {
		if (nums[i] % 10 == 0)
			tenMode = nums[i];
		else if (tenMode != -1)
			nums[i] = tenMode;
	}
	return nums;
}
