public boolean lastDigit(int a, int b, int c) {
  return (a - b) % 10 == 0 || (b - c) % 10 == 0 || (a - c) % 10 == 0 ? true : false;
}
