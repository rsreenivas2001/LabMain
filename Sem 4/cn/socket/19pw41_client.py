import socket
import threading

HOST = "localhost"
PORT = 8888


TCP_client = socket.socket()
TCP_client.connect((HOST, PORT))


if __name__ == '__main__':
    print(TCP_client.recv(1024).decode())
    print('Commands: \n mput <key,value> \n mget <key> \n # of sockets')
    while True:
        msg = input(" >> ")
        TCP_client.send(msg.encode())
        data = TCP_client.recv(1024)
        print(data.decode())



