public String mirrorEnds(String string) {
  int len = string.length() - 1;
	for (int i = 0; i < len; i++, len--) {
		if (string.charAt(i) != string.charAt(len))
			return string.substring(0, i);
	}
	return string;
}
