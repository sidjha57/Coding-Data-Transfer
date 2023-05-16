def smallestString(weight):
    weights = list()
    weights.append(1)

    for i in range(1,26):
        a = (i+2)*weights[i-1]
        weights.append(a)

    j = 25
    ans = ""
    while (weight):
        while (weight >= weights[j]):
            a = chr(97+j)
            ans += a
            weight -= weights[j]
        
        j -= 1
    
    ans = ans [::-1]
    return ans
        

print(smallestString(20))