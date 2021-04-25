public List wordsWithoutList(String[] words, int len) {
  ArrayList<String> str = new ArrayList<String>(Arrays.asList(words));
  for (int i = 0; i < str.size(); i++) {
    if (str.get(i).length() == len) 
      str.remove(i);
  }
  return str;
}
