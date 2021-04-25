def front_back(str):
  return str if len(str) < 2 else str[-1] + str[1:-1] + str[0]
