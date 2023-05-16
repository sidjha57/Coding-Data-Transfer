def getVialToRemove(vials):
    n = len(vials)
    even = [0] * n
    odd = [0] * n
    even_sum = 0
    odd_sum = 0

    odd[0] = vials[0]


    # considering 1 based indexing
    for i in range(1,n):
        odd[i] = odd[i-1]
        even[i] = even[i-1]

        if (i&1) == 0:
            odd[i] += vials[i]
        else:
            even[i] += vials[i]

    
    for i in range(0,n):
        if i > 0:
            odd_sum = odd[i-1]
            even_sum = even[i-1]

        odd_sum += even[n-1] - even[i]
        even_sum += odd[n-1] - odd[i]

        if (even_sum == odd_sum):
            return i+1
    
    return -1

print(getVialToRemove([2,5,6,7,8,4]))       

    