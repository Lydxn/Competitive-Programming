public int sumLimit(int a, int b) {
  return String.valueOf(a + b).length() > String.valueOf(a).length() ? a : a + b;
}
