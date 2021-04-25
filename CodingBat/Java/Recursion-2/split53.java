public boolean split53(int[] nums) {
  return helper(nums, 0, 0, 0);
}

public boolean helper(int[] nums, int start, int g1, int g2) {
  if (start >= nums.length) 
    return g1 == g2;
  else if (nums[start] % 3 == 0) 
    return helper(nums, start + 1, g1, g2 + nums[start]);
  else if (nums[start] % 5 == 0) 
    return helper(nums, start + 1, g1 + nums[start], g2);
  return helper(nums, start + 1, g1 + nums[start], g2) || 
         helper(nums, start + 1, g1, g2 + nums[start]);
}
