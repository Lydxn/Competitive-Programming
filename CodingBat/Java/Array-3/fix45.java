public int[] fix45(int[] nums) {
  int j = 0;
  while (j < nums.length && nums[j] != 5) {
    j++;
  }

  for (int i = 0; i < nums.length; i++) {
    if (nums[i] == 4) {
      int temp = nums[i + 1];
      nums[i + 1] = nums[j];
      nums[j] = temp;

      while ((j < nums.length && nums[j] != 5) || j == i + 1) {
        j++;
      }
    }
  }
  return nums;
}
