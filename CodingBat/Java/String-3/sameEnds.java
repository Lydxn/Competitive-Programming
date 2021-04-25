public String sameEnds(String string) {
  String largeness = "";
  for (int i = 0; i < string.length(); i++) {
    String size = string.substring(0, i);
    for (int j = i; j <= string.length() - size.length(); j++) {
      if (string.substring(j, j + size.length()).equals(size)) 
        largeness = size;
    }
  }
  return largeness;
}
