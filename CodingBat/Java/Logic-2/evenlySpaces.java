public boolean evenlySpaced(int a, int b, int c) {
  return (Math.abs(a - b) == Math.abs(b - c)) ||
         (Math.abs(a - c) == Math.abs(c - b) && a != b) ||
         (Math.abs(c - a) == Math.abs(a - b) && b != c) ? true : false;
}
