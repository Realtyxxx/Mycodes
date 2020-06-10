def Merge(p, q, r, L=[]):
    b = []
    i, j = p, q + 1
    while (i <= q and j <= r):
        if L[i] <= L[j]:
            b.append(L[i])
            i += 1
        else:
            b.append(L[j])
            j += 1
    while i <= q:
        b.append(L[i])
        i += 1
    while j <= r:
        j += 1
    for k in range(r-p+1):
        L[k+p]=b[k]


def MergeSort(p, r, L=[]):
    if (p < r):
        q = (p + r) // 2
        MergeSort(p, q, L)
        MergeSort(q + 1, r, L)
        Merge(p, q, r, L)


a = [3, 2, 1, 5, 6, 4]
MergeSort(0,len(a)-1,a)
# print(len(a)- 1)
print(a)
