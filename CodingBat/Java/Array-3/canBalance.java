public boolean canBalance(int[] nums) {
  int left = 0;
  int right = 0;
  for (int i : nums) {
    right += i;
  }
  
  for (int j = 0; j <= nums.length - 2; j++) {
    left += nums[j];
    right -= nums[j];
    if (left == right) 
      return true;
  }
  return false;
}
