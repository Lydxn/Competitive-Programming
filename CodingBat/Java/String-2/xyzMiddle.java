public boolean xyzMiddle(String str) {
  if(str.length() < 3)
    return false;
  int s1 = str.length() / 2 - 2;
  int s2 = str.length() / 2 - 1;
  return str.length() % 2 == 0 
  ? str.substring(s1, s1 + 3).equals("xyz") || str.substring(s2, s2 + 3).equals("xyz") 
  : str.substring(s2, s2 + 3).equals("xyz");                          
}
