def removeduplicates(lst):
    st = set(lst)
    return list(st)


if __name__ == '__main__':
    lst = [1,2,3,4,5,5,6,7,7,8,9]
    print(removeduplicates(lst))