print("Enter Arr 1 : ")
x = []
while True:
    inp = int(input())
    if inp != -1:
        x.append(inp)
    else:
        break

print("Enter Arr 2 : ")
y = []
while True:
    inp = int(input())
    if inp != -1:
        y.append(inp)
    else:
        break

setx = set(x)
sety = set(y)

sorted(setx)
sorted(sety)

if setx == sety:
    print('Both sets are equal')
else:
    m = list(setx.difference(sety))
    n = list(sety.difference(setx))
    print(m)
    print(n)

