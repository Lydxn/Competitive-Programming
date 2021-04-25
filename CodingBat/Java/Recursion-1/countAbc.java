public int countAbc(String str) {
  if (str.length() < 3) 
    return 0;
  else if (str.substring(0, 3).equals("abc") || str.substring(0, 3).equals("aba")) 
    return 1 + countAbc(str.substring(2));
  return countAbc(str.substring(1));
}
