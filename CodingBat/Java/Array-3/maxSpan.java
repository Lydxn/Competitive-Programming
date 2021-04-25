public int maxSpan(int[] nums) {
  if (nums.length == 0) 
    return 0;
  else if (nums.length == 1) 
    return 1;
  
  for (int i = nums.length; i >= 1; i--) {
    for (int j = 0; j < nums.length; j++) {
      if (i + j < nums.length) {
        if (nums[j] == nums[i + j]) {
          return i + 1;
        }
      }
    }
  }
  return 1;
}
