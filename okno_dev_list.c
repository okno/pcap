/* okno_dev_list_c
  Zorzan Urban 'okno' Pawel 2k9 - mail@pawelzorzan.eu
  compilare con libreria pcap:
  > gcc okno_dev_list.c -lpcap -o okno_dev_list
*/
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main(int argc, char **argv)
{
char *dev;
char *net;
char *mask;
int ret;
char errbuf[PCAP_ERRBUF_SIZE];
bpf_u_int32 netp;       /* indirizzo ip */
bpf_u_int32 maskp;      /* subnet mask */
struct in_addr addr;
/* Chiediamo a pcap di trovare un interfaccia */
dev = pcap_lookupdev(errbuf);
/* Controllo errore */
if(dev == NULL)
        {
        printf("%s\n",errbuf);
        exit(1);
        }
/* Stampa il nome dell'interfaccia */
printf("DEV: %s\n",dev);
/* Chiediamo a php di trvare la rete e la subnet mask dell'interfaccia */
ret = pcap_lookupnet(dev,&netp,&maskp,errbuf);
        if(ret == -1)
        {
        printf("%s\n",errbuf);
        exit(1);
        }
/* Rendiamo leggibile la rete */
addr.s_addr = netp;
net = inet_ntoa(addr);
if(net == NULL)
        {
        perror("inet_ntoa");
        exit(1);
        }
printf("NET: %s\n",net);
/* Rendiamo leggibile la subnet mask */
addr.s_addr = maskp;
mask = inet_ntoa(addr);
if(mask == NULL)
        {
        perror("inet_ntoa");
        exit(1);
        }
printf("MASK: %s\n",mask);
return 0;
}
