public int noTeenSum(int a, int b, int c) {
  if (a == 13 || a == 14 || a == 17 || a == 18 || a == 19) 
    a = 0;
  if (b == 13 || b == 14 || b == 17 || b == 18 || b == 19) 
    b = 0;
  if (c == 13 || c == 14 || c == 17 || c == 18 || c == 19) 
    c = 0;
  return a + b + c;
};
