def checkMetathesisPair(word1,word2):
    charList1 = []
    charList2 = []
    for x in range(len(word1)):
        if word1[x] != word2[x]:
            charList1.append(word1[x])
            charList2.append(word2[x])
        if len(charList2) == len(charList1) and len(charList1) == 2 and set(charList1) == set(charList2):
            return True

    return False


if __name__ == '__main__':
    str1 = input("Enter String 1 :")
    str2 = input("Enter String 2 :")
    if checkMetathesisPair(str1,str2):
        print("Yes , they are Methathesis pair")
    else:
        print("No , they are not Methathesis pair")