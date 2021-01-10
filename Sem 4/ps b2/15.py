import random


def keygen(length):
    values = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()?'
    password = ''.join(random.sample(values, length))
    return password


if __name__ == '__main__':
    inp = int(input('Enter the length of the password '))
    print(keygen(inp))