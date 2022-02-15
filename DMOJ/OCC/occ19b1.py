S = input().lower()
if S == 'darcy_liu':
    print('real')
elif S[:5] == 'darcy' and S[-3:] == 'liu' and all(c == '_' for c in S[5:-3]):
    print('fake')
else:
    print('other user')