def transpose(matrix,tr,N):
    for i in range(N):
        for j in range(N):
            tr[i][j] = matrix[j][i]


def is_symmetric(matrix,N):
    tr = [[0 for j in range(len(matrix[0]))] for i in range(len(matrix))]
    transpose(matrix,tr,N)
    for i in range(N):
        for j in range(N):
            if matrix[i][j] != tr[i][j]:
                return False

    return True


if __name__ == '__main__':
    N = int(input('Enter the number of rows : '))
    matrix = []

    for i in range(N):
        a = []
        for j in range(N):
            a.append(int(input()))
        matrix.append(a)

    if is_symmetric(matrix, N):
        print('Yes, The given matrix is Symmetric')
    else:
        print('No, The given matrix is not Symmetric')