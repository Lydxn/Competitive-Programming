public String wordEnds(String str, String word) {
  return str.replaceAll(".*?(?=" + word + ")(?<=(.|^))" + word + "(?=(.|$))|.+", "$1$2");
}
