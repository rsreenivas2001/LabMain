print("Enter Set 1 : ")
x = set()
while True:
    inp = int(input())
    if inp != -1:
        x.add(inp)
    else:
        break


print("Enter Set 2 : ")
y = set()
while True:
    inp = int(input())
    if inp != -1:
        y.add(inp)
    else:
        break

print(x.union(y))
print(x.intersection(y))
print(x.symmetric_difference(y))
