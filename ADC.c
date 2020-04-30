/*
 * File:   ADC.c
 * Author: mohab
 *
 * Created on 22 ?????, 2020, 06:33 ?
 */


#include <avr/io.h>
#include "kitconfig.h"
#include "ADC.h"
/*#define Ref 0
#define prescaler 1
#define LorD 2
#define channelNum 3
#define AREF 4
#define AVCC 5 */

/*
void ADC_inti(int Ref,int prescaler,int LorD,int channelNum){
    DDRA=0x00;
    ADCSRA |=(1<<ADEN);
    switch (Ref){
        case AREF:
            ADMUX = ADMUX | 0x00;
            break;
        case AVCC:
            ADMUX = ADMUX | 0b01000000;
            break;
        case 2.56:
            ADMUX = ADMUX | 0b11000000;
            break;
    }
    switch (prescaler){
        case 128:
            ADCSRA = ADCSRA | 0b00000111;
            break;
        case 64:
            ADCSRA = ADCSRA | 0b00000110;
            break;
        case 32:
            ADCSRA = ADCSRA | 0b00000101;
            break;
        case 16:
            ADCSRA = ADCSRA | 0b00000100;
            break;
        case 8:
            ADCSRA = ADCSRA | 0b00000011;
            break;
        case 4:
            ADCSRA = ADCSRA | 0b00000010;
            break;
        case 2:
            ADCSRA = ADCSRA | 0b00000001;
            break;
    }
    switch(LorD){
        case 0:
            ADMUX &=~(1<<ADLAR);
            break;
        case 1:
            ADMUX |=(1<<ADLAR);
            break;  
    }
    switch(channelNum){
        case 0:
            ADMUX = ADMUX |(0b00000000);
            break;
        case 1:
            ADMUX = ADMUX |(0b00000001);
            break;
        case 2:
            ADMUX = ADMUX |(0b00000010);
            break;
        case 3:
            ADMUX = ADMUX |(0b00000011);
            break;
        case 4:
            ADMUX = ADMUX |(0b00000100);
            break;
        case 5:
            ADMUX = ADMUX |(0b00000101);
            break;
        case 6:
            ADMUX = ADMUX |(0b00000110);
            break;
        case 7:
            ADMUX = ADMUX |(0b00000111);
            break;
    }
}
*/

void Inti_ADC(void){
    ADMUX |=(1<<REFS0); //AVCC as refrence
    ADCSRA |=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);  // Enable & 128 prescaler 
}

void ADC_Conv(){
    ADCSRA |=(1<<ADSC);
}

short ADC_Read(char channel){
    ADMUX &=0xF0; //clear the previous channel chosen
    ADMUX |= channel;
    ADC_Conv();
    while(ADCSRA & (1<<ADSC));
    return ADC;
}


