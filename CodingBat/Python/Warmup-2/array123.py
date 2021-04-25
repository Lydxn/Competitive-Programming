def array123(nums):
  for i in range(0, len(nums) - 2):
    if [1, 2, 3] == nums[i:i+3]:
      return True
  return False
