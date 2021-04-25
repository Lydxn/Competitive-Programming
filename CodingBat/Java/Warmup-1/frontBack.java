public String frontBack(String str) {
  int len = str.length();
  return len <= 1 ? str : str.charAt(len - 1) + str.substring(1, len - 1) + str.charAt(0);
}
