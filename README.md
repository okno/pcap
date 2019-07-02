# libpcap C 

Simple test written in *C* with libpcap to extract *Interface*, *Network* and *Subnet* 

Install libpcap development files : 

    # sudo apt install libpcap-dev
    
Clone pcap git and play with libpcap in C :

    # cd ~
    # git clone https://github.com/okno/pcap.git
    # cd pcap
    
Compile (need gcc, but if you are reading this shit it means that you already know how a compiler works and know how to use it 😅)

    # gcc okno_dev_list.c -lpcap -o okno_dev_list
    
Run with root permissions to read /sys/class/net 

    # sudo ./okno_dev_list
 
Output : 

    DEV: eth0
    NET: 149.202.32.0
    MASK: 255.255.254.0

<p align="left">
<img src="https://raw.githubusercontent.com/okno/pcap/master/okno_dev_list_screenshot.png" /></p>

It means that my test VPS is on the *149.202.32.0* network with *255.255.254.0* subnet mask on the *eth0* interface(Yes it's on OVH).

If you want to learn more about how this test works, take a look at th strace files in the project.

