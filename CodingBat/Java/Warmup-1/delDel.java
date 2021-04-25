public String delDel(String str) {
  if(str.length() >= 4 && str.substring(1, 4).equals("del"))
    return str.charAt(0) + str.substring(4);
  return str;
}
