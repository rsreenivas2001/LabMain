import socket

HOST = "localhost"
PORT = 8888

TCP_client = socket.socket()
TCP_client.connect((HOST, PORT))

print(TCP_client.recv(256).decode())


d = input('Enter the data bits : ')
data = list(d)
data.reverse()
c, ch, j, r, h = 0, 0, 0, 0, []

while (len(d) + r + 1) > (pow(2, r)):
    r = r + 1

print(r)
for i in range(0, (r + len(data))):
    p = (2 ** c)

    if p == (i + 1):
        h.append(0)
        c = c + 1

    else:
        h.append(int(data[j]))
        j = j + 1
h.reverse()
print(h)
h.reverse()


for parity in range(0, (len(h))):
    ph = (2 ** ch)
    if ph == (parity + 1):
        startIndex = ph - 1
        i = startIndex
        toXor = []

        while i < len(h):
            block = h[i:i + ph]
            toXor.extend(block)
            i += 2 * ph
        print("toxor = ", toXor)
        for z in range(1, len(toXor)):
            h[startIndex] = h[startIndex] ^ toXor[z]
        ch += 1

h.reverse()
print('Hamming code generated would be:- ', end="")
hc = ''.join(map(str, h))
print(hc)


TCP_client.send(hc.encode())

while True:
    print(TCP_client.recv(1024).decode())
