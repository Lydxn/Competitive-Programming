public String parenBit(String str) {
  if (str.charAt(0) != '(')
    return str.charAt(str.length() - 1) != ')' ? parenBit(str.substring(1, str.length() - 1)) : parenBit(str.substring(1));
  else if (str.charAt(str.length() - 1) != ')') 
    return parenBit(str.substring(0, str.length() - 1));
  return str;
}
