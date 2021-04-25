public String repeatSeparator(String word, String sep, int count) {
  String rep = "";
  for (int i = 0; i < count * 2 - 1; i++) {
    rep += i % 2 == 0 ? word : sep;
  }
  return rep;
}
