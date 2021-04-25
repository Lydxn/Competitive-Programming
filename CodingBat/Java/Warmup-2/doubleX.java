public boolean doubleX(String str) {
  int x = str.indexOf("x");
  return x == -1 ? false : str.substring(x).startsWith("xx");
}
