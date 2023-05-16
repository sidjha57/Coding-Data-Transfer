n = int(input())
j=0
res = list()
if (n<10) :
    print (n+10)
else :
    for i in range (9,1,-1):
        while (n%i == 0):
            n = n / i
            res.append(i) 
            j+=1
    if (n > 10):
        print("Not Possible")
    else:
        for x in range (j-1,-1,-1):
            print(res[x],end="")
