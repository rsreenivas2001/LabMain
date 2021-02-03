def decrypt(data, shift):
    data_list = list(data)
    result = []
    for char in data_list:
        ascii_value = ord(char)
        if char.isalpha():
            ascii_value -= shift
            if (90 < ascii_value < 97) or (ascii_value > 122):
                ascii_value += 26
        result.append(chr(ascii_value))
    return "".join(result)


if __name__ == "__main__":
    f = open("file2.txt", "r")
    data = f.read()
    f.close()
    result = decrypt(data, 1)
    f = open("file3.txt", "a")
    f.write(result)
    f.close()