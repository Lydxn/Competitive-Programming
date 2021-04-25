public int[] copyEvens(int[] nums, int count) {
  int[] evens = new int[count];
  for (int i = 0, even = 0; even < count; i++) {
    if (nums[i] % 2 == 0) {
      evens[even] = nums[i];
      even++;
    }
  }
  return evens;
}
