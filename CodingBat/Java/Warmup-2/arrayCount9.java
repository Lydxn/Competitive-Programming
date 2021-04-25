public int arrayCount9(int[] nums) {
  return (int) Arrays.stream(nums).filter(i -> i == 9).count();
}
