import sys
import math
import bisect
from sys import stdin, stdout
from math import gcd, floor, sqrt, log2, ceil
from collections import defaultdict as dd
from bisect import bisect_left as bl, bisect_right as br
from bisect import insort
from collections import Counter
from collections import deque
from heapq import heappush,heappop,heapify
from itertools import permutations,combinations
from itertools import accumulate as ac
from random import randint as ri,shuffle

mod = 998244353
 
ip = lambda : int(stdin.readline())
inp = lambda: map(int,stdin.readline().split())
ips = lambda: stdin.readline().rstrip()
out = lambda x : stdout.write(str(x)+"\n")

            
t = ip()
for _ in range(t):
    n = ips()
    ans = set()
    while True:
        ans.add(n)
        if int(n) == 0:
            break
        if n[-1] == '0':
            n = n[:len(n)-1]
        else:
            n = str(int(n)-1)
    ans = len(ans)
    print(ans)
            