public int factorial(int evenBetterBunnies) {
  return evenBetterBunnies == 1 ? 1 : evenBetterBunnies * factorial(evenBetterBunnies - 1);
}
