public String atFirst(String str) {
  int len = str.length();
  return len == 0 ? "@@" : (len == 1 ? str.substring(0, 1) + "@" : str.substring(0, 2));
}
