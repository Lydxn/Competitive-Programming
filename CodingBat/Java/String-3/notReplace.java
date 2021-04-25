public String notReplace(String str) {
  String res = "";
  str = " " + str + "  ";
  for (int i = 0; i <= str.length() - 2; i++) {
    if (str.substring(i, i + 2).equals("is") && !Character.isLetter(str.charAt(i - 1)) && !Character.isLetter(str.charAt(i + 2))) {
      res += "is not";
      i++;
    } else 
      res += str.charAt(i);
  }
  return res.substring(1, res.length() - 1);
} 
