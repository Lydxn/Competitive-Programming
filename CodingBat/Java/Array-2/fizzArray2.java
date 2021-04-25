public String[] fizzArray2(int n) {
  String[] nums = new String[n];
  for (int i = 0; i < nums.length; i++) {
    String str = Integer.toString(i);
    nums[i] = str;
  }
  return nums;
}
