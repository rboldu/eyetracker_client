//
//  tty_connection.c
//  Car_Server
//
//  Created by Roger Boldu on 17/3/15.
//  Copyright (c) 2015 Roger Boldú. All rights reserved.
//

#include "tty_connection.h"
#include "api.h"

// this is a bucle for stablish the bluetooth connection
int tty_connection(char tty_port[256]){
    int fd_tty=-1;
  
    while (fd_tty<0) {
        rprint("trying to stablish a new connection with Arduino\n",SPAMtty_1);
        
        //important here it have to be the direction of the device
        fd_tty=tty_connectionStablishNewConection(tty_port);
        sleep(1);
            }
         rprint("Connection done-> Arduino\n",SPAMtty_1);
    return fd_tty;
}

int set_interface_attribs (int fd, int speed, int parity)
{
    struct termios tty;
    memset (&tty, 0, sizeof tty);
    if (tcgetattr (fd, &tty) != 0)
    {
        printf("error %d from tcgetattr", errno);
        return -1;
    }
    
    cfsetospeed (&tty, speed);
    cfsetispeed (&tty, speed);
    
    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
    // disable IGNBRK for mismatched speed tests; otherwise receive break
    // as \000 chars
    tty.c_iflag &= ~IGNBRK;         // ignore break signal
    tty.c_lflag = 0;                // no signaling chars, no echo,
    // no canonical processing
    tty.c_oflag = 0;                // no remapping, no delays
    tty.c_cc[VMIN]  = 0;            // read doesn't block
    tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout
    
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl
    
    tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
    // enable reading
    tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
    tty.c_cflag |= parity;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;
    
    if (tcsetattr (fd, TCSANOW, &tty) != 0)
    {
        printf("error %d from tcsetattr", errno);
        return -1;
    }
    return 0;
}




void set_blocking (int fd, int should_block)
{
    struct termios tty;
    memset (&tty, 0, sizeof tty);
    if (tcgetattr (fd, &tty) != 0)
    {
        printf("error %d from tggetattr", errno);
        //return; TODO:
    }
    
    tty.c_cc[VMIN]  = should_block ? 1 : 0;
    tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout
    
    if (tcsetattr (fd, TCSANOW, &tty) != 0)
        printf("error %d setting term attributes", errno);
}



int tty_connectionStablishNewConection(char *portname ){
    
    int fd = open (portname, O_RDWR | O_NOCTTY | O_SYNC| O_NDELAY);
    // printf("-----------------------------------------i have stablish a new connection\n");
    if (fd < 0){
        printf("trying to establish the connexion bluetooth");
        return -1; // it was not possible to stablish a new connection
    }
    
    set_interface_attribs (fd, BAUD, 0);  // set speed to 115,200 bps, 8n1 (no parity)
    set_blocking (fd, 0);                // set no blocking
    
    
    return fd;
}


void tty_sendAction(int s_tty,char object){

    char aux[50];
    sprintf(aux,"%c",object);
    write(s_tty, aux, strlen(aux));
    sprintf(aux,"sending:    %c\n",object);
    rprint(aux, SPAMtty_2);
}

