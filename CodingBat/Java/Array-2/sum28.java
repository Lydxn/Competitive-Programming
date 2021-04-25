public boolean sum28(int[] nums) {
  int count = 0;
  for (int i : nums) {
    if (i == 2) 
      count++;
  }
  return count == 4 ? true : false;
}
