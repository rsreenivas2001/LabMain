from scapy.all import sr1 
from scapy.layers.inet import IP , ICMP
import sys
import time


def ip_found(pkt, ip, timeout, ttl):
    start = time.time()
    response = sr1(pkt, timeout=timeout,verbose=False)
    finish = time.time()
    rtt = round((finish - start) * 1000)

    if not response:
        print(f'{ttl}  *')
    else:
        print(f'{ttl}  {response.src}  {rtt} ms')
        if pkt.dst == response.src:
            return True


def traceroute(ip, timeout):
    ttl = 1
    while ttl <= 128:
        icmp_pkt = IP(dst=ip, ttl=ttl) / ICMP()
        if ip_found(icmp_pkt, ip, timeout, ttl):
            break
        ttl += 1


if __name__ == '__main__':
    try:
        print(f"traceroute to {sys.argv[1]} \n")
        traceroute(sys.argv[1],2)
    except:
        print("Failed to traceroute . Try again with correct Arguments \n Usage : sudo python3 file_name.py www.website.com")
    
    
    