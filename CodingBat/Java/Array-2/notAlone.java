public int[] notAlone(int[] nums, int val) {
  for (int i = 1; i < nums.length - 1; i++) {
  	if (nums[i] == val && nums[i - 1] != val && nums[i + 1] != val) 
  		nums[i] = (nums[i - 1] > nums[i + 1]) ? nums[i - 1] : nums[i + 1];
  }
  return nums;
}
