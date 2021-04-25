public int makeChocolate(int small, int big, int goal) {
  goal -= goal / 5 <= big ? goal / 5 * 5 : big * 5;
	return goal <= small ? goal : -1;
}
