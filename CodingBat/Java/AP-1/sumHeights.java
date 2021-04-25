public int sumHeights(int[] heights, int start, int end) {
  int sum = 0;
  for (int i = start; i < end; i++) {
    sum += Math.abs(heights[i] - heights[i + 1]);
  }
  return sum;
}
