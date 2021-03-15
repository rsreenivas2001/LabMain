import socket 
import subprocess

#HOST = "192.168.1.34"
HOST = "localhost"
PORT = 5555
HEADER = 10

TCP_server = socket.socket()

TCP_server.bind((HOST, PORT))
TCP_server.listen()
print(f"listening to port {PORT}")
while True:
    con, adr = TCP_server.accept()
    print(f"Connected with Client : {adr}")
    while True:
        raw_data = con.recv(1024)
        data = raw_data.decode()
        print(data)
        if data.lower() == 'option r':
            cmd = subprocess.Popen(['netstat', '-r'], stdout=subprocess.PIPE)
            output, error = cmd.communicate()
            output = (f'{len(output.decode()):<{HEADER}}'+output.decode()).encode()
            con.sendall(output)
        if data.lower() == 'option s':
            cmd = subprocess.Popen(['netstat', '-s'], stdout=subprocess.PIPE)
            output, error = cmd.communicate()
            output = (f'{len(output.decode()):<{HEADER}}'+output.decode()).encode()
            con.sendall(output)
        if data.lower() == 'option a':
            cmd = subprocess.Popen(['arp', '-a'], stdout=subprocess.PIPE)
            output, error = cmd.communicate()
            output = (f'{len(output.decode()):<{HEADER}}'+output.decode()).encode()
            con.sendall(output)

