#x = [12,24,35,24,88,120,155]

print("Enter Arr 1 : ")
x = []
while True:
    inp = int(input())
    if inp != -1:
        x.append(inp)
    else:
        break

new_x = [i for i in x if i != 24]

print(new_x)