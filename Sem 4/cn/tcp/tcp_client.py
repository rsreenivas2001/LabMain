import socket

#HOST = "61.2.78.56"
HOST = "localhost"
PORT = 5555
HEADER = 10

TCP_client = socket.socket()

TCP_client.connect((HOST, PORT))
while True:
    x = input("Enter Option :\n"
              "“Option R” – Server must sends its routing table\n"
              "“Option S” – Server must return number of TCP/UDP sockets that is created in the system\n"
              "“Option A” – Server must return its ARP cache\n")

    if x.lower() == 'r':
        TCP_client.send(b"Option R")

        data = TCP_client.recv(16)
        msg_len = int(data.decode()[:HEADER])

        data = TCP_client.recv(msg_len)
        print(data.decode()[HEADER:])

    if x.lower() == 's':
        TCP_client.send(b"Option S")

        data = TCP_client.recv(16)
        msg_len = int(data.decode()[:HEADER])

        data = TCP_client.recv(msg_len)
        print(data.decode()[HEADER:])

    if x.lower() == 'a':
        TCP_client.send(b"Option A")

        data = TCP_client.recv(16)
        msg_len = int(data.decode()[:HEADER])

        data = TCP_client.recv(msg_len)
        print(data.decode()[HEADER:])

