print("Enter Set : ")
x = set()
while True:
    inp = int(input())
    if inp != -1:
        x.add(inp)
    else:
        break
print(len(x))
