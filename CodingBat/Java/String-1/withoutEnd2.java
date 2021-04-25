public String withouEnd2(String str) {
  int len = str.length();
  return len >= 3 ? str.substring(1, len - 1) : "";
}
