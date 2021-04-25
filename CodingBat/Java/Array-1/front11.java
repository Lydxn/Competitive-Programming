public int[] front11(int[] a, int[] b) {
  if (a.length > 0 && b.length > 0) {
    return new int[] {a[0], b[0]};
  } else if (a.length > 0) {
    return new int[] {a[0]};
  } else if (b.length > 0) {
    return new int[] {b[0]};
  }
  return new int[0];
}
