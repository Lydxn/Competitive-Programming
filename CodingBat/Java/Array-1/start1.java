public int start1(int[] a, int[] b) {
  int ones = 0;
	if (a.length >= 1 && a[0] == 1)
		ones++;
	if (b.length >= 1 && b[0] == 1)
		ones++;
	return ones;
}
