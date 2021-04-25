public String[] wordsWithout(String[] words, String target) {
  int len = 0;
  for (String s : words) {
    if (s.equals(target)) 
      len++;
  }
  
  String[] res = new String[words.length - len];
  for (int i = 0, n = 0; i < words.length; i++) {
    if (!words[i].equals(target))
      res[n++] = words[i];
  }
  return res;
}
