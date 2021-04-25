public int maxTriple(int[] nums) {
  int len = nums.length;
  return Math.max(nums[0], Math.max(nums[len / 2], nums[len - 1]));
}
