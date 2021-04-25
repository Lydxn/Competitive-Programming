public String repeatEnd(String str, int n) {
  String last = str.substring(str.length() - n);
  return String.join("", Collections.nCopies(n, last));
}
