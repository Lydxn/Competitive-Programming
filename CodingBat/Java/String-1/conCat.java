public String conCat(String a, String b) {
	if(a.length() >= 1 && b.length() >= 1) 
	  return a + (a.charAt(a.length() - 1) == b.charAt(0) ? b.substring(1) : b);
	return a + b;
}
