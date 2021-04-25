public boolean no14(int[] nums) {
  boolean noOne = true;
  boolean noFour = true;
  for (int i : nums) {
		if (i == 1)
			noOne = false;
		else if (i == 4)
			noFour = false;
	}	
	return noOne || noFour;
}
