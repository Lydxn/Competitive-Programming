public boolean twoTwo(int[] nums) {
  int count = 0;
	for (int i : nums) {
		if (i == 2)
			count++;
		else {
			if (count == 1)
				return false;
			else
				count = 0;
		}
	}
	return count != 1;
}
