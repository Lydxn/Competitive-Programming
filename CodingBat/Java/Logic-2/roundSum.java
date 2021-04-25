public int round10(int num) {
  return num % 10 >= 5 ? num + 10 - num % 10 : num - num % 10;
}

public int roundSum(int a, int b, int c) {
  return round10(a) + round10(b) + round10(c);
}
