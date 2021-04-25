public boolean equalIsNot(String str) {
  int equal = 0;
  for (int i = 0; i < str.length() - 2; i++) {
    if (str.substring(i, i + 2).equals("is")) 
      equal++;
    else if (str.substring(i, i + 3).equals("not")) 
      equal--;
  }
  
  if (str.lastIndexOf("is") == str.length() - 2)
    equal++;
  return equal == 0 ? true : false;
}
