public boolean startHi(String str) {
  return str.length() < 2 ? false : str.substring(0, 2).equals("hi");
}
