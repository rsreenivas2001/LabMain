data = 'evaporate'
word = list(data)
guessed = '_'*len(word)
guessed = list(guessed)
listGuessed = []

while True:
    ltr = input("Guess Letter :")
    if ltr in listGuessed:
        print('Already guessed :', ltr)
        print(*guessed, sep='')
        continue
    elif ltr not in word:
        print("InCorrect!")
        print(*guessed, sep='')
        if ltr != '':
            listGuessed.append(ltr)
        continue
    while True:
        if ltr not in word:
            print("Correct!")
            print(*guessed, sep='')
            if ltr != '':
                listGuessed.append(ltr)
            break
        else:
            index = word.index(ltr)
            guessed[index] = ltr
            word[index] = '0'

    if '_' not in guessed:
        print('You guessed the Word:',data )
        break
