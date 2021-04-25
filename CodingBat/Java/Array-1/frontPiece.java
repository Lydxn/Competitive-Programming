public int[] frontPiece(int[] nums) {
  return nums.length >= 2 ? Arrays.copyOfRange(nums, 0, 2) : nums;
}
