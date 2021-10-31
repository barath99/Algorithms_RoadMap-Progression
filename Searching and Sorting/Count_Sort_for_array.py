def count(arr):
    k=(len(arr))
    m=[0]*k
    for i in range(len(arr)):
        m[arr[i]]+=1
    for i in range(1,len(m)):
        m[i]+=m[i-1]
    l=[0]*(len(arr))
    for i in range(len(arr)-1,-1,-1):
        m[arr[i]]-=1
        l[m[arr[i]]]=arr[i]
    for i in range(len(arr)):
        arr[i]=l[i]
    return arr
arr=list(map(int,input().split()))
print(*count(arr))
