def InsertionSort(A):
    length = len(A)
    for j in range(1, length):
        key = A[j]
        i = j - 1
        while i >= 0 and A[i] > key:
            A[i + 1] = A[i]
            i -= 1
        A[i + 1] = key


a = [3, 2, 1, 5, 6, 4]
InsertionSort(a)
print(a)
