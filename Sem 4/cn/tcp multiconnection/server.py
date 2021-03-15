import socket
import threading

HOST = "localhost"
PORT = 8888


clients = {}

TCP_server = socket.socket()
TCP_server.bind((HOST, PORT))
TCP_server.listen()


def broadcast_clients(_client, msg):
    for client_ in clients:
        if client_ != _client:
            msg_to_send = clients[_client] + " >> " + msg
            client_.send(msg_to_send.encode())
        elif client_ == _client:
            msg_to_send = "YOU >> " + msg
            client_.send(msg_to_send.encode())


def handle_client(_client):
    while True:
        try:
            msg = (_client.recv(512)).decode()
            broadcast_clients(_client, msg)
        except Exception as e:
            print(e)
            _client.close()
            break


if __name__ == '__main__':
    print("Listening to port 8888 : ")
    while True:
        client, (host, port) = TCP_server.accept()
        client.send(b'Connected to the Chat Server!')
        name = (client.recv(64)).decode()
        clients[client] = name
        #print(clients)
        print(f'{name} from {host}:{port} connected to the server')

        handle_thread = threading.Thread(target=handle_client, args=(client,))
        handle_thread.start()

