def frequency(str):
    cnt = dict()
    for ltr in str:
        if ltr not in cnt:
            cnt[ltr] = 1
        else:
            cnt[ltr] += 1
    return sorted(cnt.items())

if __name__ == '__main__':
    x = input("Enter String : ")
    print(frequency(x))