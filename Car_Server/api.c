//
//  api.c
//  Car_Server
//
//  Created by Roger Boldu on 17/3/15.
//  Copyright (c) 2015 Roger Boldú. All rights reserved.
//

#include <stdio.h>
#include "api.h"

void rprint(char cadena[256],char p){
    
    if (p==1&&SPAM==1) {
        write(1, cadena, strlen(cadena));
    }
}