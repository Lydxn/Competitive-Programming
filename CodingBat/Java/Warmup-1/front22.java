public String front22(String str) {
  String front = str.substring(0, 2 > str.length() ? str.length() : 2);
  return front + str + front;
}
