public String startWord(String str, String word) {
  int len = word.length();
  return str.length() >= len && str.substring(1, len).equals(word.substring(1)) ? str.substring(0, len) : ""; 
}
