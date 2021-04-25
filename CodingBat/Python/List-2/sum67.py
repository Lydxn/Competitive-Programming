def sum67(nums):
  sum = 0
  ignore = False
  for i in nums:
    if i == 6:
      ignore = True
      continue
    elif i == 7 and ignore:
      ignore = False
      continue
    if not ignore:
      sum += i
  return sum
