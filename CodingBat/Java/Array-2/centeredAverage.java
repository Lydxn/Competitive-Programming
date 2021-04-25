public int centeredAverage(int[] nums) {
  Arrays.sort(nums);
  int sum = 0;
  for (int i = 1; i < nums.length - 1; i++) {
    sum += nums[i];
  }
  return sum / (nums.length - 2);
}
