t=int(input())

for i in range(t):
    a, b=map(int, input().split())
    
    if i==0:
        minX=maxX=a
        minY=maxY=b
    
    minX=min(minX, a)
    minY=min(minY, b)
    maxX=max(maxX, a)
    maxY=max(maxY, b)
    
result=(maxX-minX)*(maxY-minY)
print(result)