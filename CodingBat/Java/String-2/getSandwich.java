public String getSandwich(String str) {
  int first = str.indexOf("bread");
  int last = str.lastIndexOf("bread");
  return first != -1 && last != -1 && first != last ? str.substring(first + 5, last) : "";
}
