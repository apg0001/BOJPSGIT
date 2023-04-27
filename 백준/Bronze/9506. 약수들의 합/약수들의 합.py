while True:
    n=int(input())
    if(n==-1):
        break
    s=0
    l=[]
    
    for i in range(1, n):
        if(n%i==0):
            l.append(i)
            s+=i
    
    if s==n:
        print(n, "=", end=" ")
        print(l[0], end=" ")
        for i in range(1, len(l)):
            print("+", l[i], end=" ")
        print()
    else:
        print(n, "is NOT perfect.")       