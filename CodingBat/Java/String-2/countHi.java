public int countHi(String str) {
  int count = 0;
  for (int i = 0; i < str.length() - 1; i++) {
    if (str.substring(i, i + 2).equals("hi")) 
      count++;
  }
  return count;
}
