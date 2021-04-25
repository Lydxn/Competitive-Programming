public boolean has271(int[] nums) {
  for (int i = 0; i < nums.length - 2; i++) {
    int val = nums[i];
    if (nums[i + 1] == (val + 5) && Math.abs(nums[i + 2] - val + 1) <= 2) 
      return true;
  }
  return false;
}
