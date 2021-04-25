public int blackjack(int a, int b) {
  if (a > 21 && b > 21) 
    return 0;
  else if (a <= 21 && b <= 21) 
    return a > b ? a : b;
  else
    return a > 21 ? b : a;
}
