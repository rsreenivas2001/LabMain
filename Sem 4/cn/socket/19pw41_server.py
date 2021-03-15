import socket
import threading
import subprocess

HOST = "localhost"
PORT = 8888


clients = {}
data_dict = {}

TCP_server = socket.socket()
TCP_server.bind((HOST, PORT))
TCP_server.listen()


def handle_client(_client):
    while True:
        try:
            msg = (_client.recv(512)).decode()
            if msg.startswith('mput'):
                values = msg.split(' ', 1)
                print(values)
                data = values[1].split(',')
                key = data[0][1:]
                print(key)
                value = data[1][:len(data[1])-1]
                print(value)
                data_dict[key] = value
                _client.send(b'<key,value> pair added !')
            elif msg.startswith('mget'):
                values = msg.split(' ', 1)
                key = values[1][1:len(values[1])-1]
                print(key)
                msg_to_send = data_dict[key]
                if msg_to_send is None:
                    _client.send('The Key does not exist'.encode())
                else:
                    _client.send(msg_to_send.encode())
            elif msg.startswith("#"):
                no_of_sockets = subprocess.check_output('ss -Hx | wc -l', shell=True)
                _client.send(no_of_sockets)
        except Exception as e:
            _client.send('The Key does not exist'.encode())



if __name__ == '__main__':
    print("Listening to port 8888 : ")
    while True:
        client, (host, port) = TCP_server.accept()
        client.send(b'Connected to the FTP Server!')

        print(f'{host}:{port} connected to the server')

        handle_thread = threading.Thread(target=handle_client, args=(client,))
        handle_thread.start()
