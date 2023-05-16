t = int(input())
while (t):
    n = int(input())
    a = list(map(int,input().split(" ")))
    one = 0
    two = 0
    for i in a:
        if (i == 1):
            one = one + 1
        if (i == 2):
            two = two + 1
    
    ans = n*(n-1)/2 - (n-one)*(n-one-1)/2 + two*(two-1)/2
    
    t -= 1
    ans = int(ans)
    print(ans)

# 1 2, 1 3, 1 4, 1 5, 1 6
# 2 3, 2 4, 2 5, 2 6
# 3 4, 3 5, 3 6 