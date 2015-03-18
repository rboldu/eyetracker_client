#include "api.h"

#include <netdb.h>
#include <pthread.h>

#include "ProcesData.h"
#include "Socket.h"

#include <unistd.h>



int main(int argc, char *argv[])
{
    int sockfd, s_tty, portno=27015;
    char ip[256], tty_port[256];
    Position p;
    char object;
    char pep[230];

    //execve("sudo osascript -e set Volume 0");
    sprintf(ip,"172.16.142.130");
    sprintf(tty_port, "/dev/tty.usbmodem14531");

    
    sockfd=socketInit(portno,ip);
    s_tty=tty_connection(tty_port);
    char aux[4];

  
    while (1) {
        socketReadMessage(sockfd, &p);
        object=procesDataFindObject(p);
        tty_sendAction(s_tty,object);
        }
    return 0;
}