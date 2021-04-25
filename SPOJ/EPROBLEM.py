# current best score: 171

import sys
def f(n):
 if 0<n<3:return'2(0)'[:(n^2)+1]
 m=len(bin(n))-3;p=2**m;return f(p)+'+'+f(n-p)if n-p else'2('+f(m)+')'
for l in sys.stdin:print`int(l)`+'='+f(int(l))
