def xyz_there(str):
  for i in range(0, len(str) - 2):
    if str[i:i+3] == "xyz" and str[i-1] != ".":
      return True
  return False
