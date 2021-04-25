def end_other(a, b):
  return a.lower().endswith(b.lower()) if len(a) > len(b) else b.lower().endswith(a.lower())
