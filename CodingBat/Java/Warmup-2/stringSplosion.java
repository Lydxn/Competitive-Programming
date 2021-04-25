public String stringSplosion(String str) {
  String res = "";
  for (int i = 0; i < str.length() + 1; i++) {
    res += str.substring(0, i);
  }
  return res;
}
