public int powerN(int base, int n) {
  return n == 1 ? base : base * powerN(base, n - 1);
}
