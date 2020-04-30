/*
 * File:   main.c
 * Author: guest-027de80a-9e4c-4d7f-b286-23c56ddd4f8a@transim.com
 *
 * Created on 4/30/2020 7:41:21 PM UTC
 * "Created in MPLAB Xpress"
 */


#define F_CPU 16000000UL
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "Kitconfig.h"
#include "functions.h"
#include "ADC.h"

#include "lcd.h"



char x[20];
char y[]="Temp is ";
char z[]=" C";

int main(void) {
    
     Inti_ADC();
     LCD_Init ();
     
     short result ;
     
     while(1){
         
     result= ADC_Read(1);
     result=result*0.0048828;
     result=result/0.01;
     itoa(result,x,10);
     
     LCD_String(y);
     LCD_String(x);
     LCD_String(z);
     _delay_ms(2000);
     LCD_Clear();
     setDDRA(buzzer,out);
     if(result >= 80)
     {
     setPINA(buzzer);
     }
     else
     {
      resetPINA(buzzer);
     }
    
 }
    return 0;
}
