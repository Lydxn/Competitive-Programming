public int countYZ(String str) {
  String[] words = str.split("[^a-zA-Z]");
  int count = 0;
  for (int i = 0; i < words.length; i++) {
    if (words[i].length() > 0 && (words[i].toLowerCase().indexOf("y") == words[i].length() - 1 || 
                                  words[i].toLowerCase().indexOf("z") == words[i].length() - 1))
      count++;
  }
  return count;
}
