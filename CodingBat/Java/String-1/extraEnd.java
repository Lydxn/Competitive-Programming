public String extraEnd(String str) {
  String last = str.substring(str.length() - 2, str.length());
  return last + last + last;
}
