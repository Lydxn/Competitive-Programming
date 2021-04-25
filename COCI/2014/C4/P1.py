n = list(raw_input())
print ''.join(sorted(n)[::-1]) if n.count('0') and sum(map(int, n)) % 3 == 0 else -1
