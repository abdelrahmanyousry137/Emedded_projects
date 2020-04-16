/*
 * File:   maic.c
 * Author: mohab
 *
 * Created on 10 ?????, 2020, 09:27 ?
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include "Kitconfig.h"
#include "functions.h"
#include "lcd.h"
#include <util/delay.h>

int i;


void main(void) {

    /* Replace with your application code */
    
    //declare buttons as input
    setDDRB(Button0,in); 
    setDDRB(Button1,in); 
    setDDRD(Button2,in); 
    
    //declare outputs
    setDDRC(LED0,out); //DDRC |= (1 << LED0);
    setDDRC(LED1,out); //DDRC |= (1 << LED1);
    setDDRD(LED2,out); //DDRD |= (1 << LED2);
    
   

    while (1) 
    {
        if( IspressedB(Button0) )
        {
            for (i=0;( ( IspressedB(Button1) || IspressedD(Button2) ) != 1 );i++)
            {
              resetPIND(LED2);
              setPINC(LED0);
              _delay_ms(500);
             
             resetPINC(LED0);
             setPINC(LED1);
              _delay_ms(500);
             
             resetPINC(LED1);
             setPIND(LED2);
              _delay_ms(500);
            }
        }
        if( IspressedB(Button1) )
        {
          resetPINC(LED0); 
          resetPINC(LED1);
          resetPIND(LED2);
        }
        
         if( IspressedD(Button2) )
        {
            for (i=0;( ( IspressedB(Button1) || IspressedB(Button0) ) != 1 );i++)
            {
              resetPINC(LED0);
              setPIND(LED2);
              _delay_ms(500);
             
             resetPIND(LED2);
             setPINC(LED1);
              _delay_ms(500);
             
             resetPINC(LED1);
             setPINC(LED0);
              _delay_ms(500);
            }
        }
        if( IspressedB(Button1) )
        {
          resetPINC(LED0); 
          resetPINC(LED1);
          resetPIND(LED2);
        }
    }
}
    

