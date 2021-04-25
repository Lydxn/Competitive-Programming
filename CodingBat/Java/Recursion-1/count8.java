public int count8(int n) {
  if (n == 0) 
    return 0;
	else if (n % 10 == 8) 
	  return count8(n / 10) + ((n / 10) % 10 == 8 ? 2 : 1);
	return count8(n / 10);
}
