public String everyNth(String str, int n) {
  String res = "";
  for (int i = 0; i < str.length(); i += n) {
    res += str.charAt(i);
  }
  return res;
}
