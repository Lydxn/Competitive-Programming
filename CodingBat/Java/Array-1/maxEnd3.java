public int[] maxEnd3(int[] nums) {
  int largest = Math.max(nums[0], nums[2]);
  Arrays.fill(nums, largest);
  return nums;
}
