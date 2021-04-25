public int[] zeroFront(int[] nums) { 
  int zero = 0;
  for (int i = 0; i < nums.length; i++) {
    if (nums[i] == 0) {
      nums[i] = nums[zero];
      nums[zero] = 0;
      zero++;
    }
  }
  return nums;
}
