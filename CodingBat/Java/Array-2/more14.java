public boolean more14(int[] nums) {
  int count = 0;
  for (int i : nums) {
    if (i == 1) 
      count++;
    else if (i == 4) 
      count--;
  }
  return count > 0 ? true : false;
}
