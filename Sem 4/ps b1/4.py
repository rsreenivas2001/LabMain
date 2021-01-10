
s = input()

i, c = input().split()

lt = list(s)
lt[int(i)] = c
output = ''.join(lt)

print(output)
