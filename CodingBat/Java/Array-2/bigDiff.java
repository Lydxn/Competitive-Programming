public int bigDiff(int[] nums) {
  Arrays.sort(nums);
  return nums[nums.length - 1] - nums[0];
}
