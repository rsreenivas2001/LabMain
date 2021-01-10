x = []
inp = 1

while True:
    inp = input("Enter website : ")
    if inp == '0' or inp == '':
        break
    x.append(inp)

for ite in x:
    arr = ite.split('.')
    print(ite, " - ", arr[2])
