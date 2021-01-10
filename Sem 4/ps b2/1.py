inp = input("Enter String : ")

x = inp.split(" ")

#print(x)
#print(set(x))
#print(list(set(x)))
out = list(set(x))
out.sort()
print(*out, sep=" ")