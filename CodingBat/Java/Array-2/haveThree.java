public boolean haveThree(int[] nums) {
  int count = 0;
  boolean no = false;
  for (int i : nums) {
    if (i == 3)
      if (no) 
        return false;
      else {
        count++;
        no = true;
      }
    else
      no = false;
  }
  return count == 3;
}

