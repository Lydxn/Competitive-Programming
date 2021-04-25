public String allStar(String str) {
  return str.length() < 2 ? str : str.charAt(0) + "*" + allStar(str.substring(1)); 
}
