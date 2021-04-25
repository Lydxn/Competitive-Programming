public String[] fizzBuzz(int start, int end) {
  String[] str = new String[end - start];
  for (int i = start; i < end; i++) {
    if (i % 15 == 0) {
      str[i - start] = "FizzBuzz";
    } else if (i % 3 == 0) {
      str[i - start] = "Fizz";
    } else if (i % 5 == 0) {
      str[i - start] = "Buzz";
    } else {
      str[i - start] = Integer.toString(i);
    }
  }
  return str;
}
