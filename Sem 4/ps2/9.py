def absolute(val):
    return abs(val)


if __name__ == "__main__":
    f = int(input("Enter 1 for normal number and 0 for complex number : "))
    if f:
        x = int(input("Enter Number : "))
        print(absolute(x))
    else:
        x = int(input("Enter Real Part : "))
        y = int(input("Enter Imaginary Part : "))
        z = complex(x, y)
        print(absolute(z))
