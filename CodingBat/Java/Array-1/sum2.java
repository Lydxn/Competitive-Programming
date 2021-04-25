public int sum2(int[] nums) {
  return nums.length >= 2 ? nums[0] + nums[1] : (nums.length == 1 ? nums[0] : 0);
}
