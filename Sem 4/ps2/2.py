from math import sqrt


def distance(u, v):
    total = 0
    for x, y in zip(u, v):
        # print(x, y)
        total += pow(y - x, 2)
        # print(total)
    print("The distance is : ", sqrt(total))


if __name__ == '__main__':
    u1 = list(map(int, input('Enter CoOrdinates of 1st point : ').split()))
    v1 = list(map(int, input('Enter CoOrdinates of 2nd point : ').split()))
    distance(u1 ,v1)