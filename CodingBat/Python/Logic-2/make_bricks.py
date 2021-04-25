def make_bricks(small, big, goal):
  return False if goal % 5 > small or goal > small + big * 5 else True
