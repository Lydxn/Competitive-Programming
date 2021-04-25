def pos_neg(a, b, negative):
  return (a < 0) ^ (b < 0) if not negative else (a < 0) and (b < 0)
