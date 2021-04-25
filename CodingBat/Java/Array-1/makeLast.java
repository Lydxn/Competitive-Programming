public int[] makeLast(int[] nums) {
  int[] arr = new int[nums.length * 2];
  arr[arr.length - 1] = nums[nums.length - 1];
  return arr;
}
