public boolean shareDigit(int a, int b) {
  return a / 10 == b / 10 || a / 10 == b % 10 || a % 10 == b / 10 || a % 10 == b % 10 ? true : false;
}
