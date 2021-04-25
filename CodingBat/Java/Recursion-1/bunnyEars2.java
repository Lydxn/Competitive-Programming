public int bunnyEars2(int bunnies) {
  int n = bunnies % 2 == 0 ? 3 : 2;
  return bunnies == 0 ? 0 : n + bunnyEars2(bunnies - 1); 
}
