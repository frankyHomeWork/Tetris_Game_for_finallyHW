#ifndef _USER_CONTROL_H
#define _USER_CONTROL_H
#include "gameControler.h"

void control_Block0();

static const struct
{
    void ( *control_Block0)();
    
} UserControl = {
    control_Block0
};

#endif
