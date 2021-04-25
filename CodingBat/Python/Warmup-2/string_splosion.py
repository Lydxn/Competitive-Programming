def string_splosion(str):
  return "".join([str[:i] for i in range(1, len(str) + 1)])
