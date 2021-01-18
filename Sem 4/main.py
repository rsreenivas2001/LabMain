  
def getMax(intList):
    if len(intList) == 1:
        return intList[0]
    else:
        max = getMax(intList[1:])
        return max if max > intList[0] else intList[0]

if __name__ == '__main__':
    list = [1,2,3,4,5,6,7,8,10,6,4]
    print(getMax(list))
