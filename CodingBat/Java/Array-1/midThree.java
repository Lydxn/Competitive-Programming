public int[] midThree(int[] nums) { 
  int first = (nums.length - 1) / 2 - 1;
  int[] three = {nums[first], nums[first + 1], nums[first + 2]};
  return three;
