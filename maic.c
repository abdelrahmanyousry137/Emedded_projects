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

 char a[]="LED0 is ON ";
    char b[]="LED0 is OFF ";
    
    char c[]="LED1 is ON ";
    char d[]="LED1 is OFF ";
    
    char e[]="LED2 is ON ";
    char f[]="LED2 is OFF ";
    
    int flag=0;

int main(void) {
    LCD_Init();
    /* Replace with your application code */
    
    //declare buttons as input
    setDDRB(Button0,in); 
    setDDRB(Button1,in); 
    setDDRD(Button2,in); 
    
    //declare outputs
    setDDRC(LED0,out); //DDRC |= (1 << LED0);
    setDDRC(LED1,out); //DDRC |= (1 << LED1);
    setDDRD(LED2,out); //DDRD |= (1 << LED2);
    
   

    while (1) {
        if((IspressedB(Button0))&&(flag==0)){
            _delay_ms(200);
            flag=1;
            if(flag==1){
            LCD_Clear();
            setPINC(LED0);
            LCD_String(a);
            }
            
        }
         if((IspressedB(Button0))&&(flag==1)){
             _delay_ms(200);
            flag=0;
            if(flag==0){
            LCD_Clear();
            resetPINC(LED0);
             LCD_String(b);
            }
        }
          if((IspressedB(Button1))&&(flag==0)){
              _delay_ms(200);
               flag=1;
            if(flag==1){
            LCD_Clear();
            setPINC(LED1);
            LCD_String(c);
            }
        }
         if((IspressedB(Button1))&&(flag==1)){
             _delay_ms(200);
             flag=0;
            if(flag==0){
            LCD_Clear();
            resetPINC(LED1);
             LCD_String(d);
            }
        }
        
          if((IspressedD(Button2))&&(flag==0)){
              _delay_ms(200);
               flag=1;
            if(flag==1){
            LCD_Clear();
            setPIND(LED2);
            LCD_String(e);
            }
        }
         if((IspressedD(Button2))&&(flag==1)){
             _delay_ms(200);
             flag=0;
            if(flag==0){
            LCD_Clear();
            resetPIND(LED2);
             LCD_String(f);
            }
        }
        
    }
    return 0;
}
