public String seeColor(String str) {
  return str.indexOf("red") == 0 ? "red" : (str.indexOf("blue") == 0 ? "blue" : "");
}
