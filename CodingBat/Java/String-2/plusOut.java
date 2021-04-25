public String plusOut(String str, String word) {
  word = java.util.regex.Pattern.quote(word);
  return str.replaceAll("\\G((?:" + word + ")*+).", "$1+");
}
