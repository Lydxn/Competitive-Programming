public String stringX(String str) {
  String result = "";
  for (int i = 0; i < str.length(); i++) {
    if (!(i > 0 && i < (str.length() - 1) && str.substring(i, i + 1).equals("x"))) {
      result += str.charAt(i);
    }
  }
  return result;
}
