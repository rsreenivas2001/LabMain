def normalize(data):
    return [float(i)/sum(data) for i in data]

if __name__ == '__main__':
    data = [5,5,10]
    print(normalize(data))