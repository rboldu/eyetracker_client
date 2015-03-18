//
//  ProcesData.h
//  car_server
//
//  Created by Roger Boldu on 17/3/15.
//  Copyright (c) 2015 Roger Boldú. All rights reserved.
//

#ifndef __car_server__ProcesData__
#define __car_server__ProcesData__

#include <stdio.h>
#include "api.h"

#define OBJECT_A_X0 400
#define OBJECT_A_Y0 500
#define OBJECT_A_X1 800
#define OBJECT_A_Y1 3000

#define OBJECT_B_X0 1000
#define OBJECT_B_Y0 500
#define OBJECT_B_X1 1400
#define OBJECT_B_Y1 3000


#define OBJECT_C_X0 659
#define OBJECT_C_Y0 0
#define OBJECT_C_X1 1100
#define OBJECT_C_Y1 4000

char procesDataFindObject(Position p);

#endif /* defined(__car_server__ProcesData__) */
