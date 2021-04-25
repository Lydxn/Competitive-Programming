public boolean inOrder(int a, int b, int c, boolean bOk) {
  return (!bOk && b > a && c > b) || (bOk && c > b) ? true : false;
}
