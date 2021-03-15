import socket
import threading

HOST = "localhost"
PORT = 8888


clients = {}

TCP_server = socket.socket()
TCP_server.bind((HOST, PORT))
TCP_server.listen()


def process_message(clnt, message):
    data = message
    g = [1, 0, 1, 1]
    message = [int(bit) for bit in data]
    m = len(data) - len(g) - 1
    # perform division
    while 1 in message[:m]:
        cur_shift = message.index(1)
        for i in range(len(g)):
            message[cur_shift + i] = g[i] ^ message[cur_shift + i]

    is_corrupted = 1 in message[m:]

    if is_corrupted:
        print('Corrupted')
        clnt.send('Corrupted')
    else:
        print('No error, data recieved is')
        clnt.send('No error, data recieved is')
        print(data[:m])
        clnt.send(data[:m])


def handle_client(_client):
    while True:
        try:
            msg = (_client.recv(512)).decode()
            process_message(_client, msg)
        except Exception as e:
            print(e)
            _client.close()
            break


if __name__ == '__main__':
    print("Listening to port 8888 : ")
    while True:
        client, (host, port) = TCP_server.accept()
        client.send(b'Connected to the Server!')

        print(f'{host}:{port} connected to the server')

        handle_thread = threading.Thread(target=handle_client, args=(client,))
        handle_thread.start()
