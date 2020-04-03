def Lsearch(arr,n):
    i=0
    flag=0
    while(arr[i]!='\0'):
        if arr[i]==n:
            flag=1
            return i+1
        i+=1
    return -1    

arr = [1,2,3,4,5,6,6,7]
n=5
pos = Lsearch(arr,n)

if pos == -1:
    print ("ELement not found!")    
else:
    print ("Element found at",pos)