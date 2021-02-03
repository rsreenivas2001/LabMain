import math
dist = __import__(2)


def magnitude(vec):
    total = 0
    for x in vec:
        #print(x)
        total += (pow(x, 2))
    return math.sqrt(total)


def cosine(u, v):
    dot = 0
    for x, y in zip(u, v):
        dot += x * y
    print(dot/(magnitude(u)*magnitude(v)))

if __name__ == '__main__':
    u1 = list(map(int, input('Enter 1st vector : ').split()))
    v1 = list(map(int, input('Enter 2nd vector : ').split()))
    cosine(u1,v1)
    dist.distance(u1,v1)




