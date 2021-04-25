public boolean splitArray(int[] nums) {
  return helper(nums, 0, 0, 0);
}

public boolean helper(int[] nums, int start, int g1, int g2) {
  return start >= nums.length ? g1 == g2 : helper(nums, start + 1, g1, g2 + nums[start]) || 
                                           helper(nums, start + 1, g1 + nums[start], g2);
}
