public int last2(String str) {
  int len = str.length();
  int count = 0;
  for (int i = 0; i < len - 2; i++) {
    if (str.substring(i, i + 2).equals(str.substring(len - 2, len))) 
      count++;
  }
  return count;
}
