public String stringTimes(String str, int n) {
  return String.join("", Collections.nCopies(n, str));
}
