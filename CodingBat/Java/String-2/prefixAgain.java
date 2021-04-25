public boolean prefixAgain(String str, int n) {
  String prefix = str.substring(0, n);
  return str.substring(n).contains(prefix);
}
