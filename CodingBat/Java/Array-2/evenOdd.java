public int[] evenOdd(int[] nums) {
  int temp;
  int even = 0;
  for (int i = 0; i < nums.length; i++) {
    if (nums[i] % 2 == 0) {
      temp = nums[i];
      nums[i] = nums[even];
      nums[even] = temp;
      even++;
    }
  }
  return nums;
}
