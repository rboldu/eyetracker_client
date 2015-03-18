//
//  Socket.h
//  car_server
//
//  Created by Roger Boldu on 17/3/15.
//  Copyright (c) 2015 Roger Boldú. All rights reserved.
//

#ifndef __car_server__Socket__
#define __car_server__Socket__

#include <stdio.h>
#include "api.h"
int socketInit(int port, char ip[50]);
int socketReadMessage(int sockfd, Position *p);


#endif /* defined(__car_server__Socket__) */
