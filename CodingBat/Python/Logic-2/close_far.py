def close_far(a, b, c):
  return (abs(b - a) >= 2 and abs(b - c) >= 2 and abs(c - a) <= 1) or (abs(c - a) >= 2 and abs(b - c) >= 2 and abs(b - a) <= 1)
