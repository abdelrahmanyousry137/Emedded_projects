/*
 * File:   functions.c
 * Author: mohab
 *
 * Created on 10 ?????, 2020, 10:49 ?
 */


#include <xc.h>
#include "kitconfig.h"
#include "functions.h"

#define Risingedge  1
#define Fallingedge 2
#define Toggle      3
#define Lowlevel    4

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
                   /*default :
# warning "wrong argument input to function , use out or in"
            break;
            */
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
                   /*default :
# warning "wrong argument input to function , use out or in"
            break;
            */
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
                   /*default :
# warning "wrong argument input to function , use out or in"
            break;
            */
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
                   /*default :
# warning "wrong argument input to function , use out or in"
            break;
            */
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

//interrupt functions 

void INT0_init(int type) {
    switch(type){
        case(Risingedge):
    MCUCR |= (1 << ISC01) | (1 << ISC00); // Rising Edge
    GICR |= (1 << INT0);
    break;
        case(Fallingedge):
           MCUCR |= (1 << ISC01);
           MCUCR &=~(1 << ISC00);
           GICR |= (1 << INT0);
           break;
        case(Toggle):
            MCUCR |= (1 << ISC00);
           MCUCR &=~(1 << ISC01);
           GICR |= (1 << INT0);
           break;
           case(Lowlevel):
            MCUCR &=~(1 << ISC00);
           MCUCR &=~(1 << ISC01);
           GICR |= (1 << INT0);
           break;
    }
}


void INT1_init(int type) {
    switch(type){
        case(Risingedge):
    MCUCR |= (1 << ISC11) | (1 << ISC10); // Rising Edge
    GICR |= (1 << INT1);
    break;
        case(Fallingedge):
           MCUCR |= (1 << ISC11);
           MCUCR &=~(1 << ISC10);
           GICR |= (1 << INT1);
           break;
        case(Toggle):
            MCUCR |= (1 << ISC10);
           MCUCR &=~(1 << ISC11);
           GICR |= (1 << INT1);
           break;
           case(Lowlevel):
            MCUCR &=~(1 << ISC10);
           MCUCR &=~(1 << ISC11);
           GICR |= (1 << INT1);
           break;
    }
}


void INT2_init(int type) {
    switch(type){
        case(Risingedge):
    MCUCSR |= (1 << ISC2); // Rising Edge
    GICR |= (1 << INT2);
    break;
        case(Fallingedge):
           MCUCSR &=~(1 << ISC2);
           GICR |= (1 << INT2);
           break;
    }
}