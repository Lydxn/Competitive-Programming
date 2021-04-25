public int diff21(int n) {
  int diff = Math.abs(21 - n);
  return n > 21 ? diff * 2 : diff;
}
