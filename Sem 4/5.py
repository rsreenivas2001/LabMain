def checkprime(x):
    if x == 1:
        print(x, "is Not Prime")
        return
    if x == 2:
        print(x, "is Prime")
        return
    for i in range(2, int(x/2)+2):
        if x % i == 0:
            print(x,"is Not Prime")
            return
    print(x, "is Prime")


if __name__ == '__main__':
    flag = int(input("random or 1to50 (1 or 0) : "))
    if flag == 1:
        inp = int(input("Enter Number  : "))
        checkprime(inp)
    else:
        for j in range(1, 51):
            checkprime(j)














