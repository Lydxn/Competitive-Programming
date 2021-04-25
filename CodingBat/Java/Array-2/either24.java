public boolean either24(int[] nums) {
  int no2pair = 1;
  int no4pair = 1;
  for (int i = 0; i < nums.length - 1; i++) {
		if (nums[i] == 2 && nums[i + 1] == 2)
			no2pair = 0;
		else if (nums[i] == 4 && nums[i + 1] == 4)
			no4pair = 0;
	}
	return (no2pair ^ no4pair) == 1;
}
