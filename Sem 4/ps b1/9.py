print("Enter Arr  : ")
x = []
while True:
    inp = int(input())
    if inp != -1:
        x.append(inp)
    else:
        break

print(sum(x)/len(x))