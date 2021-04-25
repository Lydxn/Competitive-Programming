public int array11(int[] nums, int index) {
  if (index == nums.length) 
    return 0;
  else if (nums[index] == 11) 
    return 1 + array11(nums, index + 1);
  return array11(nums, index + 1);
}
