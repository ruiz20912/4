
#include <stdio.h>
#include <xc.h>
#include <stdint.h>
#include <stdlib.h>
#include <pic16f887.h>

#ifndef ADC_H
#define	ADC_H

void initializeADC(int channel);
int readADC();
void changeADCChannel(int channel);
int getCurrentADCChannel();
float mapValue(int inputValue, int inputMin, int inputMax, int outputMin, int outputMax);

#endif	/* ADC_H */



