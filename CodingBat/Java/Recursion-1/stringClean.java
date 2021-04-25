public String stringClean(String str) {
  if (str.length() < 2) 
    return str;
  else if (str.charAt(0) == str.charAt(1)) 
    return stringClean(str.substring(1));
  return str.charAt(0) + stringClean(str.substring(1));
}
