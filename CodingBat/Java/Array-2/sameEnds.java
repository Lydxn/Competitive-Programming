public boolean sameEnds(int[] nums, int len) {
  int start = 0;
	int end = nums.length - len;
	for (; len > 0; len--) {
		if (nums[start] != nums[end]) 
			return false;
		else 
			start++;
			end++;
	}
	return true;
}

