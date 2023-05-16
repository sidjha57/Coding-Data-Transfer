def make_non_decreasing(A):
    n = len(A)
    ops = []
    for i in range(n-1):
        if A[i] > A[i+1]:
            j = i+1
            while j < n and A[j] < A[i]:
                j += 1
            if j < n:
                for k in range(i+1, j):
                    ops.append((k, j))
                A[i] ^= A[j]
                ops.append((i, j))
    if not all(A[i] <= A[i+1] for i in range(n-1)):
        for i in range(n-2, -1, -1):
            if A[i] > A[i+1]:
                j = i+1
                while j < n and A[j] < A[i]:
                    j += 1
                if j < n:
                    for k in range(i+1, j):
                        ops.append((k, j))
                    A[i] ^= A[j]
                    ops.append((i, j))
    if not all(A[i] <= A[i+1] for i in range(n-1)):
        for i in range(n):
            for j in range(n-i-1):
                if A[j] > A[j+1]:
                    A[j] ^= A[j+1]
                    ops.append((j, j+1))
    return ops

t = int(input())
for _ in range(t):
    n = int(input())
    A = list(map(int, input().split()))
    ops = make_non_decreasing(A)
    print(len(ops))
    for i, j in ops:
        print(i+1, j+1)

    print(A)