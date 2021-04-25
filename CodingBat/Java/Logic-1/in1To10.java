public boolean in1To10(int n, boolean outsideMode) {
  return (n >= 1 && n <= 10 && !outsideMode) || ((n <= 1 || n >= 10) && outsideMode) ? true : false;
}
