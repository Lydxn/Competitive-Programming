public int[] make2(int[] a, int[] b) {
  int[] two = new int[2];
  if (a.length >= 2) {
    two[0] = a[0];
    two[1] = a[1];
  } else if (a.length == 0) {
    two[0] = b[0];
    two[1] = b[1];
  } else {
    two[0] = a[0];
    two[1] = b[0];
  }
  return two;
}
