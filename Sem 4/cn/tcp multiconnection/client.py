import socket
import threading

HOST = "localhost"
PORT = 8888


TCP_client = socket.socket()
TCP_client.connect((HOST, PORT))

print(TCP_client.recv(256).decode())

name = input("Enter your NAME for the CHAT server : ")

TCP_client.send(name.encode())


def print_messages():
    while True:
        try:
            message = TCP_client.recv(512).decode()
            if message:
                print("\n" + message)
        except Exception as e:
            print(e)
            TCP_client.close()
            break


if __name__ == '__main__':
    print_thread = threading.Thread(target=print_messages, args=())
    print_thread.start()

    while True:
        msg = input("")
        TCP_client.send(msg.encode())



