sequence = [5, 10, 15, 20, 25, 30, 35]
a = sequence

mid = int((len(a)+1)/2 - 1)

b = a

c = a[mid : mid + 2]

del a[mid:mid+2]
print(a)

a = a[:mid] + c + a[mid:]
print(a)