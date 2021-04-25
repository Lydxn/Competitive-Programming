public boolean groupSumClump(int start, int[] nums, int target) {
  if (start >= nums.length)
    return target == 0;
    
  int i = start;
  int sum = 0;
  for (; i < nums.length && nums[start] == nums[i]; i++) 
    sum += nums[i];
  return groupSumClump(i, nums, target - sum) || groupSumClump(i, nums, target) ? true : false;
}
