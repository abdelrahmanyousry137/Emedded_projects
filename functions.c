/*
 * File:   functions.c
 * Author: mohab
 *
 * Created on 10 ?????, 2020, 10:49 ?
 */


#include <xc.h>
#include "kitconfig.h"

void setPINA(int pinNum){
    PORTA |=(1 << pinNum);
}

void setPINB(int pinNum){
    PORTB |=(1 << pinNum);
}

void setPINC(int pinNum){
    PORTC |=(1 << pinNum);
}

void setPIND(int pinNum){
    PORTD |=(1 << pinNum);
}

void resetPINA(int pinNum){
    PORTA &=~(1 << pinNum);
}

void resetPINB(int pinNum){
    PORTB &=~(1 << pinNum);
}

void resetPINC(int pinNum){
    PORTC &=~(1 << pinNum);
}

void resetPIND(int pinNum){
    PORTD &=~(1 << pinNum);
}

int IspressedA(int pinNum){
    if(PINA & (1 << pinNum))
        return 1;
    else
        return 0;
}

int IspressedB(int pinNum){
    if(PINB & (1 << pinNum))
        return 1;
    else
        return 0;
}

int IspressedC(int pinNum){
    if(PINC & (1 << pinNum))
        return 1;
    else
        return 0;
}

int IspressedD(int pinNum){
    if(PIND & (1 << pinNum))
        return 1;
    else
        return 0;
}
