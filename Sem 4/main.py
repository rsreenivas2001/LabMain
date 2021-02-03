import math

def magnitude(vec):
    total = 0
    for x in vec:
        print(x)
        total += (pow(x, 2))
    print(math.sqrt(total))


u = list(map(int, input('Enter 1st vector : ').split()))
v = list(map(int, input('Enter 2nd vector : ').split()))

total = 0

magnitude(u)
magnitude(v)



