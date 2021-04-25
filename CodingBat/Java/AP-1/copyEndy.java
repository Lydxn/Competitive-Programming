public int[] copyEndy(int[] nums, int count) {
  int[] endies = new int[count];
  for (int i = 0, endy = 0; endy < count; i++) {
    if ((nums[i] >= 0 && nums[i] <= 10) || (nums[i] >= 90 && nums[i] <= 100)) {
      endies[endy] = nums[i];
      endy++;
    }
  }
  return endies;
}
