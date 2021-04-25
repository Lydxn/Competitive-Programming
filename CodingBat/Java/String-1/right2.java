public String right2(String str) {
  int len = str.length() - 2;
	return str.substring(len) + str.substring(0, len);
}
