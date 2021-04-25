public boolean array6(int[] nums, int index) {
  if (index == nums.length) 
    return false;
  else if (nums[index] == 6) 
    return true;
  return array6(nums, index + 1);
}
