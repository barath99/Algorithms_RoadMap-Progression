def maxsumcontinuoussubarray(arr,n):
    sum=0
    res=[0]*n
    res[0]=arr[0]
    sum=res[0]
    for i in range(1,len(arr)):
        res[i]=max(arr[i],res[i-1]+arr[i])
        if res[i]>sum:
            sum=res[i]
    return sum
            

n=int(input())
arr=list(map(int,input().split()))
print(maxsumcontinuoussubarray(arr,n))

#time complexity=O(n)
#space=O(n)
