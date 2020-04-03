import math
def Bsearch(arr,n):     #This only works for sorted arrays
    flag=0
    size_of_array=len(arr)
    l=0
    m=size_of_array-1
    mid=math.floor((l+m)/2)
    while(mid>=l and mid<=m):
        mid=math.floor((l+m)/2)
        if arr[mid]==n:
            flag=1
            return mid+1
        elif arr[mid]>n:
            m=mid
        else:
            l=mid
    return -1    

arr = [1,2,3,4,5,6,7]
n=5
pos = Bsearch(arr,n)

if pos == -1:
    print ("ELement not found!")    
else:
    print ("Element found at",pos)