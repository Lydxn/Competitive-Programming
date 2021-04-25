public boolean has12(int[] nums) {
  boolean oneSpotted = false;
  for (int i : nums) {
  	if (oneSpotted && i == 2) 
  		return true;
  	else if (i == 1)
  		oneSpotted = true;
  }
  return false;
}
