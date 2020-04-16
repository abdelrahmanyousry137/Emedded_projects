/*
 * File:   functions.c
 * Author: mohab
 *
 * Created on 10 ?????, 2020, 10:49 ?
 */


#include <xc.h>
#include "kitconfig.h"

//set pin as high as output

void setPINA(int pinNum) {
    PORTA |= (1 << pinNum);
}

void setPINB(int pinNum) {
    PORTB |= (1 << pinNum);
}

void setPINC(int pinNum) {
    PORTC |= (1 << pinNum);
}

void setPIND(int pinNum) {
    PORTD |= (1 << pinNum);
}

//set pin as low as output

void resetPINA(int pinNum) {
    PORTA &= ~(1 << pinNum);
}

void resetPINB(int pinNum) {
    PORTB &= ~(1 << pinNum);
}

void resetPINC(int pinNum) {
    PORTC &= ~(1 << pinNum);
}

void resetPIND(int pinNum) {
    PORTD &= ~(1 << pinNum);
}

//set pin data direction aka DDR

void setDDRA(int pinNum, int dir) {
    switch (dir) {
        case out:
            DDRA |= (1 << pinNum);
            break;
        case in:
            DDRA &= ~(1 << pinNum);
            break;
    
    }
}

void setDDRB(int pinNum, int dir) {
    switch (dir) {
        case out:
            DDRB |= (1 << pinNum);
            break;
        case in:
            DDRB &= ~(1 << pinNum);
            break;
 
    }
}

void setDDRC(int pinNum, int dir) {
    switch (dir) {
        case out:
            DDRC |= (1 << pinNum);
            break;
        case in:
            DDRC &= ~(1 << pinNum);
            break;
    }
}

void setDDRD(int pinNum, int dir) {
    switch (dir) {
        case out:
            DDRD |= (1 << pinNum);
            break;
        case in:
            DDRD &= ~(1 << pinNum);
            break;

    }
}

int IspressedA(int pinNum) {
    if (PINA & (1 << pinNum))
        return 1;
    else
        return 0;
}

int IspressedB(int pinNum) {
    if (PINB & (1 << pinNum))
        return 1;
    else
        return 0;
}

int IspressedC(int pinNum) {
    if (PINC & (1 << pinNum))
        return 1;
    else
        return 0;
}

int IspressedD(int pinNum) {
    if (PIND & (1 << pinNum))
        return 1;
    else
        return 0;
}
