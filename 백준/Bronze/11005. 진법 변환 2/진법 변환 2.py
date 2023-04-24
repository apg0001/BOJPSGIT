a, b=map(int, input().split())
temp=[]
result=''
while a>0:
    temp.append(int(a%b))
    a=a//b
    
for i in range(len(temp)-1, -1, -1):
    c=temp[i]
    
    if(c<10):
        result=result+chr(c+ord('0'))
    else:
        result=result+chr(c-10+ord('A'))

print(result)