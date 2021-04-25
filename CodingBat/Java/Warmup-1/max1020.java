public int max1020(int a, int b) {
  boolean aIn = a >= 10 && a <= 20;
  boolean bIn = b >= 10 && b <= 20;
  return aIn && bIn ? Math.max(a, b) : (aIn ? a : (bIn ? b : 0));
}
