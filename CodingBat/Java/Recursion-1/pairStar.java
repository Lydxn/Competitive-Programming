public String pairStar(String str) {
  if (str.length() < 2) 
    return str;
  else if (str.charAt(0) == str.charAt(1)) 
    return str.charAt(0) + "*" + pairStar(str.substring(1));
  return str.charAt(0) + pairStar(str.substring(1));
}
