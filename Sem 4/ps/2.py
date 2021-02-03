  
def getMax(Values):
    if len(Values) == 1:
        return Values[0]
    else:
        _max = getMax(Values[1:])
        return _max if _max > Values[0] else Values[0]

if __name__ == '__main__':
    list = [1,2,3,4,5,6,7,8,10,6,4]
    print(getMax(list))