def make_chocolate(small, big, goal):
  goal -= goal / 5 * 5 if goal / 5 <= big else big * 5
  return goal if goal <= small else -1;
