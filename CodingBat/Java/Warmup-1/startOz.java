public String startOz(String str) {
  String res = "";
  
  if (str.length() >= 1 && str.charAt(0) == 'o') {
    res += str.charAt(0);
  } 
  if (str.length() >= 2 && str.charAt(1) == 'z') {
    res += str.charAt(1);
  }
  return res;
}
