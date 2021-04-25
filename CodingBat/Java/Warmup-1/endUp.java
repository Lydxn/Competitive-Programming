public String endUp(String str) {
  int len = str.length();
  return len <= 3 ? str.toUpperCase() : str.substring(0, len - 3) + str.substring(len - 3).toUpperCase();
}
