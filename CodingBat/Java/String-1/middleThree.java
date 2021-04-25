public String middleThree(String str) {
  int mid = str.length() / 2 + 1;
  return str.substring(mid - 2, mid + 1);
}
