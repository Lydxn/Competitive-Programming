// current best score: 151

import math
def f(n):s=int(n**.5);return 2*sum(n/-~i for i in range(s))-s*s
while 1:
 a,b=map(int,raw_input().split())
 if a<1:break
 print f(b)-f(a-1)
