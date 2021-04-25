public String repeatFront(String str, int n) {
  if (n > 0)
    return str.substring(0, n) + repeatFront(str, n - 1); 
  return "";
}
