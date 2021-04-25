cnt = idk = 1
for c in input():
	if c == 'L': cnt *= 2
	elif c == 'R': cnt = cnt * 2 + idk
	elif c == '*': cnt, idk = cnt * 5 + idk, idk * 3
print(cnt)
