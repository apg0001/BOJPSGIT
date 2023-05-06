a1, a0=map(int, input().split())
c=int(input())
n0=int(input())

flag=True

if(a1>c):
    flag=False
if(a1*n0+a0>c*n0):
    flag=False
    
if flag:
    print(1)
else:
    print(0)