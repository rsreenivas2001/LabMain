alice_ratings = {"alonzo": 1, "bob": 3, "turing": 2}
bob_ratings = {"alice": 1, "alonzo": 2, "turing": 3}
alonzo_ratings = {"alice": 3, "bob": 2, "turing": 1}
turing_ratings = {"alice": 2, "alonzo": 1, "bob": 3}
friends = {"alice": alice_ratings, "bob": bob_ratings,"alonzo": alonzo_ratings, "turing": turing_ratings}

def popular_student():

    results = dict.fromkeys(friends.keys(),0)

    for _,value in friends.items():
        for name,rating in value.items():
            results[name] += rating

    minrating = min(results.values())
    popular = [key for key,value in results.items() if value == minrating]

    return popular

if __name__ == '__main__':
    print(str(popular_student()))