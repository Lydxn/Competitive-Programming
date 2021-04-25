public String extraFront(String str) {
  str = str.length() < 2 ? str : str.substring(0, 2);  
  return str + str + str;
}
