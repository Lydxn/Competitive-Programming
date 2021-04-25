public boolean frontAgain(String str) {
  int len = str.length();
  return len >= 2 ? str.substring(0, 2).equals(str.substring(len - 2, len)) : false;
}
