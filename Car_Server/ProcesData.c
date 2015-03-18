//
//  ProcesData.c
//  car_server
//
//  Created by Roger Boldu on 17/3/15.
//  Copyright (c) 2015 Roger Boldú. All rights reserved.
//

#include "ProcesData.h"
#include "api.h"

int procesData(char buffer[256]);

char procesDataFindObject(Position p){
    //Here it sopouse to go all the objects
    char aux[256];
    sprintf(aux,"x:%f,y:%f\n",p.x,p.y);
    rprint(aux,SPAMProcess_1);
    if (p.x>OBJECT_A_X0&&OBJECT_A_X1>p.x&&(p.y>OBJECT_A_Y0&&OBJECT_A_Y1>p.y)){
        rprint("object_1\n",SPAMProcess_2);
        return 'a';
    }else{
        if (p.x>OBJECT_B_X0&&OBJECT_B_X1>p.x && (p.y>OBJECT_B_Y0&&OBJECT_B_Y1>p.y)){
            rprint("object_2\n",SPAMProcess_2);
            return 'b';
        }else{
            rprint("object_3\n",SPAMProcess_2);
            return 'c';
        }
    }

    return -1;
}
