lines = []
inputSentence = input('Enter the sentence ')
lines = inputSentence.split('.')
#print(lines)
sentences = {}
for line in lines:
    words = line.split(':')[1].split()
    for word in words:
        if word not in sentences.keys():
            sentences[word] = [int(line.split(':')[0])]
        else:
            sentences[word].append(int(line.split(':')[0]))


print(*(sentences.items()), sep="\n")

#input sample : 1:he is good.2:she is very bad.3:he was very good