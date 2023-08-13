#include "ADC.h"

// Función para configurar el ADC en un canal específico
void initializeADC(int channel) {
    if (channel <= 13) {
        ADCON0bits.CHS = channel;
    } else {
        ADCON0bits.CHS = 0b0000;
    }
    
    // Configuración del ADC
    ADCON1bits.VCFG0 = 0; // Voltaje referenciado a 0V
    ADCON1bits.VCFG1 = 0; // Voltaje referenciado a 5V
    ADCON0bits.ADCS = 0b10; // Fosc/32
     
    ADCON1bits.ADFM = 0; // Justificación a la izquierda
    ADCON0bits.ADON = 1; // Encendemos el módulo del ADC
     
    // Banderas e interrupciones
    PIR1bits.ADIF = 0; // Apagamos la bandera del ADC
    INTCONbits.PEIE = 1; // Habilitar interrupciones periféricas
    PIE1bits.ADIE = 1; // Habilitar interrupciones del ADC
    INTCONbits.GIE = 1; // Habilitar interrupciones globales
    ADCON0bits.GO = 1; // Activamos la lectura del ADC
    return;
}

// Leer el valor del ADC
int readADC() {
    return ADRESH;
}

// Cambiar el canal del ADC
void changeADCChannel(int channel) {
    if (channel <= 13) { 
        ADCON0bits.CHS = channel;
    } else {
        ADCON0bits.CHS = 0b0000;
    }
    return;
}

// Obtener el canal actual del ADC
int getCurrentADCChannel() {
    char channel = ADCON0bits.CHS; // Asignamos el número de canal del ADC a la variable 'channel'
    return channel;
}

// Función para mapear un valor de entrada a un rango deseado
float mapValue(int inputValue, int inputMin, int inputMax, int outputMin, int outputMax) {
    float mappedValue;
    mappedValue = (float)(inputValue - inputMin) * (outputMax - outputMin) / (inputMax - inputMin) + outputMin; 
    return mappedValue;
}
