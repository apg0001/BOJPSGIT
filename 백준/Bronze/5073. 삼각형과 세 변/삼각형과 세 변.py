while True:
    a=list(map(int, input().split()))
    if a[0]==0 and a[1]==0 and a[2]==0:
        break
    a.sort()
    
    if a[0]+a[1]<=a[2]:
        print("Invalid")
    elif a[0]==a[1] and a[1]==a[2]:
        print("Equilateral")
        continue
    elif a[0]==a[1] or a[1]==a[2] or a[0]==a[2]:
        print("Isosceles")
    else:
        print("Scalene")
    