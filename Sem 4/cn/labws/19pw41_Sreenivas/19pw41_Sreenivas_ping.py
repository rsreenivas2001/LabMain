from scapy.all import IP, ICMP, sr1
import sys
import time

#function that returns seconds as millisecond format
def millis(x):
    return str("{:.2f}".format(1000*x)) + ' ms'

#function to calculate packet loss
def pkt_loss(x,y):
    var = y/x *100
    return str(100 - var) + '%'

#the ping function that takes ip as the argument
def ping(ip_):
    ip = ip_
    seq_no=0
    rtt = []
    transmitted = 0
    received = 0
    
    ovrall_init_time = time.time()
    for _ in range(0,10):     
        #init_time = time.time()
        #creating the data to be sent
        data = "MY_PING " + str(seq_no) + ' ' +str(time.time())
        #using scapy's sr1 to send and receive the packet
        resp = sr1(IP(dst=ip)/ICMP()/data,timeout=1,verbose=0)
        end_time = time.time()
        transmitted += 1
        if resp is None:
            #printing in the case of timed-out packet
            print(seq_no,"Timed Out", sep=" : ")
            rtt.insert(seq_no,0)
        else:
            received += 1
            time_ = time.strftime('%H:%M:%S', time.localtime(end_time))
            msg_rcvd = (resp.load).decode().split()
            rtt.insert(seq_no,end_time - float((msg_rcvd[2])))
            #printing the output if packet received successfully
            print(seq_no,time_,msg_rcvd[0],"Successfully received",millis(rtt[seq_no]),sep=" : ")
            time.sleep(1-rtt[seq_no])
        seq_no += 1
    ovrall_end_time = time.time()
    total_time = ovrall_end_time - ovrall_init_time

    #displaying the packet loss and rtt value
    print(f"\n---{ip} ping statistics ---")
    print(f"{transmitted} packets transmitted , {received} received , {pkt_loss(transmitted,received)} packet loss , {millis(total_time)}" )
    print(f"rtt min/avg/max {millis(min(rtt))}/{millis(sum(rtt)/len(rtt))}/{millis(max(rtt))}")



if __name__ == '__main__':
    try:
        print(f"PINGING {sys.argv[1]} :\n")
        ping(sys.argv[1])
    except:
        print("Failed to ping . Try again with correct Arguments  \n Usage : sudo python3 file_name.py www.website.com")




            
