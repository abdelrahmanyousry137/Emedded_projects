/*
 * File:   maic.c
 * Author: mohab
 *
 * Created on 10 ?????, 2020, 09:27 ?
 */


#include <avr/io.h>
#include "functions.h"
#include "kitconfig.h"

int main(void) {
    /* Replace with your application code */
    
    DDRA = 0xFF;
    PORTA = 0x00;
    
    //declare buttons as input
    DDRB &= ~(1 << Button0); //input pin
    DDRB &= ~(1 << Button1); //input pin
    DDRD &= ~(1 << Button2); //input pin
    
    //declare outputs
    DDRC |= (1 << LED0);
    DDRC |= (1 << LED1);
    DDRD |= (1 << LED2);

    while (1) {
        if(IspressedB(Button0))
            setPINC(LED0);
        else 
            resetPINC(LED0);
        
        if(IspressedB(Button1))
            setPINC(LED1);
        else 
            resetPINC(LED1);
        
        if(IspressedD(Button2))
            setPIND(LED2);
        else 
            resetPIND(LED2);
    }
}
