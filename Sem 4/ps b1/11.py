
def iskeprekar(n):
    if n == 1:
        return True
    num = 0
    temp = n
    while not temp == 0:
        #print(num)
        num = num + 1
        temp = temp // 10
    #print("n",n)
    #print("num",num)
    sq = pow(n, 2)
    z = (pow(10, num))
    #print(sq,z)
    total = int(sq / z) + int(sq % z)
    if total == n:
        return True
    return False


x = int(input("Enter Number : "))
if iskeprekar(x):
    print(x, "is a Keprekar number")
else:print(x, "is not a Keprekar number")



