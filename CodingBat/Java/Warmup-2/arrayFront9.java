public boolean arrayFront9(int[] nums) {
  for (int i = 0; i < (nums.length >= 4 ? 4 : nums.length); i++) {
    if (nums[i] == 9) 
      return true;
  }
  return false;
}
