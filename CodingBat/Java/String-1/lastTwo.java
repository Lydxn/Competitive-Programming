public String lastTwo(String str) {
  int len = str.length();
  return len >= 2 ? str.substring(0, len - 2) + str.charAt(len - 1) + str.charAt(len - 2) : str;
}
