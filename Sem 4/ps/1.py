def most_frequent(str):
    cnt = dict()
    for ltr in str:
        if ltr not in cnt:
            cnt[ltr] = 1
        else:
            cnt[ltr] += 1
    return sorted(cnt.items(),key=lambda cnt : cnt[1],reverse=True)

if __name__ == '__main__':
    x = input("Enter String : ")
    print(most_frequent(x))
