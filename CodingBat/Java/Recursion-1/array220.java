public boolean array220(int[] nums, int index) {
  if (index >= nums.length - 1) 
    return false;
  else if (nums[index] * 10 == nums[index + 1]) 
    return true;
  return array220(nums, index + 1);
}
