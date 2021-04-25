public int sumDigits(int n) {
  return n < 10 ? n : sumDigits(n / 10) + n % 10;
}
