#ifndef DZ_LED_H
#define DZ_LED_H

#include "lib/utils.h"

#define LED_ON 0
#define LED_OFF 1

#define turnOnLED(led) set(led, LED_ON)
#define turnOffLED(led) set(led, LED_OFF)

#endif