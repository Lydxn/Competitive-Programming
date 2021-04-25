public String doubleChar(String str) {
  String res = "";
  for (int i = 0; i < str.length(); i++) {
    for (int j = 0; j < 2; j++) {
      res += str.charAt(i);
    }
  }
  return res;
}
