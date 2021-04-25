public int[] makeMiddle(int[] nums) {
  int[] mid = new int[2];
  mid[0] = nums[nums.length / 2 - 1];
  mid[1] = nums[nums.length / 2];
  return mid;
}
