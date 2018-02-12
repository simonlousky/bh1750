#include "mgos_bh1750.h"
#include "mgos_i2c.h"


bool mgos_bh1750_init(void){
    return true;
}

/* 
doc
*/
bool bh1750_init(byte addr){
    return true;
}

/*
doc
*/
bool begin(Mode mode){
    
}

/*
doc
*/
bool configure(Mode mode);

/*
doc
*/
uint16_t readLightLevel(bool maxWait);

