N = input()
S = raw_input()
print ''.join('01'[c in 'qwertasdfgzxcv'] for c in S)