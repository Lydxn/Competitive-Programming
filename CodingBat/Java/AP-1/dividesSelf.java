public boolean dividesSelf(int n) {
  for (int i = n; i != 0; i /= 10) {
    if (i % 10 == 0 || n % (i % 10) != 0)
      return false;
  }
  return true;
}
