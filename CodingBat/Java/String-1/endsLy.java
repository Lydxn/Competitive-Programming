public boolean endsLy(String str) {
  int len = str.length();
  return len >= 2 ? str.substring(len - 2).equals("ly") : false;
}
