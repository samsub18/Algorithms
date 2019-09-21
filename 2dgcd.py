def gcd(a,b):
    
    while b!=0:
        r = a%b
        a = b
        b = r

    return a

res = []
test_cases = int(input(""))
n_m = input("")
for _ in range(test_cases):
    sum = 0 
    i_j = [int(i) for i in input("").split()]
    i1,j1 = i_j[:2]
    i2,j2 = i_j[2:]
    arr1 = [i for i in range(i1,i2+1)]
    arr2 = [i for i in range(j1,j2+1)]
    for i in arr1:
        for j in arr2:
            sum += gcd(i,j)

    res.append(sum)

for i in res:
    print(i)
