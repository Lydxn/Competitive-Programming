public int[] pre4(int[] nums) {
	int p = 0;
	int[] arr;
	while (nums[p] != 4)
		p++;
	
	arr = new int[p];
	for (int i = 0; i < p; i++)
		arr[i] = nums[i];
	return arr;
}
