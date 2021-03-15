import socket
import threading

HOST = "localhost"
PORT = 8888


clients = {}

TCP_server = socket.socket()
TCP_server.bind((HOST, PORT))
TCP_server.listen()


def process_msg(message, clnt):
    data = list(message)
        
    data.reverse()
    c, ch, j, r, error, h, parity_list, h_copy = 0, 0, 0, 0, 0, [], [], []

    for k in range(0, len(data)):
        p = (2 ** c)
        h.append(int(data[k]))
        h_copy.append(data[k])
        if p == (k + 1):
            c = c + 1

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
            parity_list.append(h[parity])
            ch += 1
    parity_list.reverse()
    print(parity_list)
    error = sum(int(parity_list) * (2 ** i) for i, parity_list in enumerate(parity_list[::-1]))

    if error == 0:
        print('There is no error in the hamming code received')
        clnt.send(b'There is no error in the hamming code received')

    elif error >= len(h_copy):
        print('Error cannot be detected')
        clnt.send(b'Error cannot be detected')

    else:
        print('Error is in', error, 'bit')
        error_msg = 'Error is in' + str(error) + 'bit'
        clnt.send(error_msg.encode())

        if h_copy[error - 1] == '0':
            h_copy[error - 1] = '1'

        elif h_copy[error - 1] == '1':
            h_copy[error - 1] = '0'
        print('After correction hamming code is:- ')
        clnt.send(b'After correction hamming code is:- ')
        h_copy.reverse()
        print(int(''.join(map(str, h_copy))))
        hc = ''.join(map(str, h))
        clnt.send(hc.encode())


def handle_client(_client):
    while True:
        try:
            msg = (_client.recv(512)).decode()
            process_msg(msg, _client)
        except Exception as e:
            print(e)
            _client.close()
            break


if __name__ == '__main__':
    print("Listening to port 8888 : ")
    while True:
        client, (host, port) = TCP_server.accept()
        client.send(b'Connected to the Server!')

        #print(clients)
        print(f'{host}:{port} connected to the server')

        handle_thread = threading.Thread(target=handle_client, args=(client,))
        handle_thread.start()