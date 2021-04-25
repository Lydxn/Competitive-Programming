public String theEnd(String str, boolean front) {
  return front ? str.substring(0, 1) : str.substring(str.length() - 1);
}
