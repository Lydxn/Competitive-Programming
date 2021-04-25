public boolean lessBy10(int a, int b, int c) {
  return Math.abs(a - c) >= 10 || Math.abs(c - b) >= 10 || Math.abs(b - a) >= 10 ? true : false;
}
