public boolean hasBad(String str) {
  int index = str.indexOf("bad");
	return index == 0 || index == 1 ? true : false;
}
