public String front3(String str) {
  String front = str.length() >= 3 ? str.substring(0, 3) : str;
  return front + front + front;
}
