def lone_sum(a, b, c):
  sum = 0
  sum += a if a not in [b, c] else 0
  sum += b if b not in [a, c] else 0
  sum += c if c not in [a, b] else 0
  return sum
