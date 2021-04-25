public int sum67(int[] nums) {
  int sum = 0;
	boolean range = false;
	for (int i : nums) {
		if (i == 6) 
		  range = true;
		else if (i == 7 && range)
		  range = false;
		else if (!range)
		  sum += i;
	}
	return sum;
}

