public String changePi(String str) {
  if (str.length() < 2)
    return str;
  else if (str.substring(0, 2).equals("pi")) 
    return "3.14" + changePi(str.substring(2));
  return str.charAt(0) + changePi(str.substring(1));
}
