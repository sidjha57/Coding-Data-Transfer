from sys import stdin
from collections import defaultdict as dd
from collections import deque as dq
from collections import Counter as ctr
from heapq import heapify,heappush as ha, heappop as hp
from math import ceil,floor,gcd,sqrt
from bisect import bisect_left as bsl, bisect_right as bsr
from bisect import insort_left as isl, insort_right as isr
from itertools import permutations, combinations
ip = lambda : int(stdin.readline())
ips = lambda : str(stdin.readline())
ipm = lambda : map(int,stdin.readline().split())
mod = int(1e9)+7
mod2 = 998244353
def next(arr, target):
    start = 0;
    end = len(arr) - 1;
 
    ans = -1;
    while (start <= end):
        #print(start,end) #debug
        mid = (start + end) // 2;
        if (arr[mid] <= target):
            start = mid + 1;
            ans = mid
        else:
            ans = mid;
            end = mid - 1;
    return ans;
#start
for _ in range(ip()):
    n = ip()
    a = list(ipm())
    c = 0
    for i in range(n-2):
        for j in range(i+2,n):
            m = (a[i]+a[j])//2
            v = next(a[i+1:j],m)
            mx = (a[i+1+v]-a[i])*(a[j]-a[i+1+v])
            if v+1<j:
               mx = max (mx, (a[i+2+v]-a[i])*(a[j] - a[i+2+v]))
            if v-1>i:
               mx = max (mx, (a[i+v]-a[i])*(a[j] - a[i+v]))
                    
            c+=mx
    print(c)