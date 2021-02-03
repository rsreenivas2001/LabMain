def number_of_digits(val):
    cnt = 1
    while True:
        if val/10 >= 1:
            cnt += 1
            val /= 10
            continue
        break
    print(cnt)


x = int(input("Enter a Number : "))
number_of_digits(x)
