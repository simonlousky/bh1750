#include "mgos.h"

/* TODO: edit info

This is a library for the BH1750FVI Digital Light Sensor
breakout board.

The BH1750 board uses I2C for communication. Two pins are required to
interface to the device. Configuring the I2C bus is expected to be done
in user code. The BH1750 library doesn't do this automatically.

Datasheet: http://rohmfs.rohm.com/en/products/databook/datasheet/ic/sensor/light/bh1750fvi-e.pdf

Written by Christopher Laws, March, 2013.

*/

#ifndef MGOS_BH1750_h
#define MGOS_BH1750_h


typedef enum
{
    UNCONFIGURED = 0,
    CONTINUOUS_HIGH_RES_MODE,
    // Measurement at 0.5lx resolution. Measurement time is approx 120ms.
    CONTINUOUS_HIGH_RES_MODE_2,
    // Measurement at 4lx resolution. Measurement time is approx 16ms.
    CONTINUOUS_LOW_RES_MODE,
    // Measurement at 1lx resolution. Measurement time is approx 120ms.
    ONE_TIME_HIGH_RES_MODE,
    // Measurement at 0.5lx resolution. Measurement time is approx 120ms.
    ONE_TIME_HIGH_RES_MODE_2,
    // Measurement at 1lx resolution. Measurement time is approx 120ms.
    ONE_TIME_LOW_RES_MODE,

    MODE_NUM_OF
} Mode;

typedef struct{
    Mode mode;
    int BH1750_I2CADDR;
    uint16_t addr;
} bh1750_t; 

// No active state
#define BH1750_POWER_DOWN 0x00

// Wating for measurement command
#define BH1750_POWER_ON 0x01

// Reset data register value - not accepted in POWER_DOWN mode
#define BH1750_RESET 0x07

/* 
doc
*/
bh1750_t bh1750_init(byte addr);

/*
doc
*/
bool begin(Mode mode);

/*
doc
*/
bool configure(Mode mode);

/*
doc
*/
uint16_t readLightLevel(bool maxWait);

#endif /* MGOS_BH1750 */
