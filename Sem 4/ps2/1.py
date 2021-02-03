for t in range(0,100):
    if t % 3 == 0 and t % 5 == 0:
        print('FizzBuzz')
    elif t % 3 == 0:
        print('Fuzz')
    elif t % 5 == 0:
        print('Buzz')
    else:
        print(t)



