def pythagorean_triple(limit):
    c, m = 0, 2
    while c < limit:
        for n in range(1, m):
            a = m * m - n * n
            b = 2 * m * n
            c = m * m + n * n

            if c > limit:
                break

            print(f"Pythagorean triplet {a},{b},{c}")

        m += 1


if __name__ == '__main__':
    max_limit = 100
    pythagorean_triple(max_limit)