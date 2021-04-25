S = __import__("sys").stdin.buffer.read()
print(sum(S) - 96 * len(S) + 86)
