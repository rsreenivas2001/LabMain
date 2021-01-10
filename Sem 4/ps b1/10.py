def has22(lst):
    print(lst)
    for ite in range(len(lst)):
        if lst[ite] == 2:
            if lst[ite + 1] == 2:
                return True
            else:
                continue
        else:
            continue
    return False


print("Enter array(-1 to terminate): ")
lt = []
while True:
    x = int(input())
    if x < 0:
        break
    lt.append(x)
if has22(lt):
    print("has 2,2")
else:
    print("no 2,2")
