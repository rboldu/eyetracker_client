//
//  api.h
//  car_server
//
//  Created by Roger Boldu on 17/3/15.
//  Copyright (c) 2015 Roger Boldú. All rights reserved.
//

#ifndef car_server_api_h
#define car_server_api_h

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <math.h>
#include <sys/wait.h>
#include <sys/shm.h>

#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<errno.h>
#include<stdint.h>

#include <dirent.h>
#include <sys/stat.h>
#include <time.h>


//#include "tty_connecion.h"


#include <sys/ttydev.h>



#include <sys/uio.h>



#include <termios.h>


#include <sys/time.h> /* En Linux no cal */
#include <sys/select.h>
#include "api.h"



#include <netdb.h>
#include <pthread.h>

#define SPAM 1
#define SPAMSocket 0
#define SPAMProcess_1 0
#define SPAMProcess_2 0
#define SPAMtty_1 0
#define SPAMtty_2 1

typedef struct {
    float x;
    float y;
} Position;

void rprint(char cadena[256],char p);
#endif
