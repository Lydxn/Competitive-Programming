public int maxBlock(String str) {
  if (str.length() == 0)
    return 0;
    
  int max = 0;
  int curr = 1;
  for (int i = 1; i < str.length(); i++) {
    if (str.charAt(i) != str.charAt(i-1)) {
      if (curr > max)
        max = curr;
      curr = 1;
    } else {
      curr++;
    }
  }
  return Math.max(max, curr);
}
