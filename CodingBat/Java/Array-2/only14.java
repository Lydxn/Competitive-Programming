public boolean only14(int[] nums) {
  for (int i : nums) {
    if (i != 1 && i != 4) 
      return false;
  }
  return true;
}
