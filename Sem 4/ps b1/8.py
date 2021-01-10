

def rle(strng):
    x = {}
    output = ''
    x[strng[0]] = 0
    for char in strng:
        if char in x.keys():
            x[char] += 1
        else:
            for key, value in x.items():
                output = output + key + str(value)
            x.clear()
            x[char] = 1
    for key, value in x.items():
        output = output + key + str(value)
    return output


inp = input("Enter : ")

print(rle(inp))





