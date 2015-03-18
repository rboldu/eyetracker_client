//
//  Socket.c
//  car_server
//
//  Created by Roger Boldu on 17/3/15.
//  Copyright (c) 2015 Roger Boldú. All rights reserved.
//

#include "Socket.h"

int socketInit(int portno, char ip[50]){
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    /* Create a socket point */
     server = gethostbyname(ip);
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }
    
    
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
    /* Now connect to the server */
    if (connect(sockfd,&serv_addr,sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(1);
    }
    
    /* Now ask for a message from the user, this message
     * will be read by server
     */
    return sockfd;

}


void readNumber(char buffer[256],Position *p){
    char aux1[50];
    char aux2[50];
    bzero(aux1, 50);
    bzero(aux2, 50);
    int i=0;
    int f=0;
    
    while (buffer[i]!='\0'&&buffer[i]!=','&&buffer[i]!='\n') {
        aux1[i]=buffer[i];
        i++;
    }
    aux1[i]='\0';
    i++;
    f=i;
    while (buffer[i]!='\0'&&buffer[i]!=','&&buffer[i]!='\n') {
        aux2[i-f]=buffer[i];
        i++;
    }
    aux2[i-f]='\0';
    char aux[100];

    
    p->x=atof(aux1);
    p->y=atof(aux2);
    sprintf(aux, "he llegit :%f",p->x);
    rprint(aux,SPAMSocket);
    sprintf(aux, ",%f\n",p->y);
    rprint(aux,SPAMSocket);
    
}

// return nomber of bits
//important this function blocks
int socketReadMessage(int sockfd, Position *p){
    int n;
    char buffer[256];
    bzero(buffer,256);
    
    rprint("reading\n",SPAMSocket);
    n = read(sockfd,buffer,255);
    if (n<1) {
        write(1, "Error reading", strlen("Error reading"));
       exit(-1);
    }else{
        readNumber(buffer,p);
    }
    
    return n;
}