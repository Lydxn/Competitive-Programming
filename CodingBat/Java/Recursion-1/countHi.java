public int countHi(String str) {
  if (str.length() < 2) 
    return 0;
  else if (str.charAt(0) == 'h' && str.charAt(1) == 'i') 
    return 1 + countHi(str.substring(2));
  return countHi(str.substring(1));
}
