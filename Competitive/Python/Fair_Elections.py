# cook your dish here
for t in range(int(input())):
    l = list(map(int,input().split()))
    n, m = l[0], l[1]
    s1, s2 = 0, 0
    john = list(map(int,input().split()))
    jack = list(map(int,input().split()))
    s1, s2 = sum(john),sum(jack)
    count = 0
    if s1 > s2 :
        print(0)
    
    else :
        john.sort()
        jack.sort()
        if n > m:
            for i in range (m):
                if jack[m-1-i] != john [i]:
                    s1 += jack [m-1-i] - john [i]
                    s2 += john [i] -jack [m-1-i]
                    count += 1
                    if s1 > s2 :
                        print (count)
                        break
            if s1 <= s2 :
                print(-1)
        else:
            for i in range (n):
              if jack[m-1-i] != john [i]:
                    s1 += jack [m-1-i] - john [i]
                    s2 += john [i] -jack [m-1-i]
                    count += 1
                    if s1 > s2 :
                        print (count)
                        break
            if s1 <= s2 :
                print(-1)