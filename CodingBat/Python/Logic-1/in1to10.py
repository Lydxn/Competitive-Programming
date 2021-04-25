def in1to10(n, outside_mode):
  return True if n == 1 or n == 10 else (n in range(1, 11)) ^ outside_mode
