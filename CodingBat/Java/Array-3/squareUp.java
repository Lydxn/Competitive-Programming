public int[] squareUp(int n) {
  int[] arr = new int[n * n];
  int p;
  for (int i = 1; i <= n; i++) {
    p = n * i - 1;
    for (int j = 1; j <= i; j++, p--) {
      arr[p] = j;
    }
  }
  return arr;
}
