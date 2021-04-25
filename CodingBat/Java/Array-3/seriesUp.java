public int[] seriesUp(int n) {
  int up = 0;
  int[] arr = new int[(n * (n + 1)) / 2];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      arr[up] = j;
      up++;
    }
  }
  return arr;
}
