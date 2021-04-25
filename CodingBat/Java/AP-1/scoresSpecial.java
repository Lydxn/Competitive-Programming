public int helper(int[] arr) {
  int largest = 0;
  for (int i = 0; i < arr.length; i++) {
    if (arr[i] % 10 == 0 && arr[i] > largest)
      largest = arr[i];
  }
  return largest;
}

public int scoresSpecial(int[] a, int[] b) {
  return helper(a) + helper(b);
}
