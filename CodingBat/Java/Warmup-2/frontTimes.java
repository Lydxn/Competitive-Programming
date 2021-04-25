public String frontTimes(String str, int n) {
  int len = str.length();
  return String.join("", Collections.nCopies(n, str.substring(0, len >= 3 ? 3 : len)));
}
