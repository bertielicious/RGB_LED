/*
 * File:   main.c
 * Author: Phil Glazzard
 * C standard C99
 * C Compiler Microchip XC8 v2.36
 * Created on 06 October 2023, 21:40
 */



#include "constantsVariables.h"
#include "configurationBits.h"
#include "configOsc.h"
#include "configPorts.h"
#include "configTMR0.h"
#include "configTMR2.h"
#include "configPWM.h"
#include "putch.h"
#include "configEUSART.h"
#include "twoFunctionButton.h"
#include <stdio.h>

void main(void) 
{
    configOsc();
    configPorts();
    configEUSART();
    configTMR0();
    configTMR2();
    configPWM();
    
    RC5 = 0;
    RC4 = 0;
    RC3 = 0;
    printf("hello Philboy!\n");
    printf("%d\n", dutyCycle);
    rgb data;
    rgb *ptr;
    ptr = &data;
    
   // static uint8_t buttonState = 0;// starting state of buttonState variable used in twoFunctionButton func
    
    while(1)
    {
        if(PORTAbits.RA2 == HI) //data.redButton == HI)
        {
            //PORTCbits.RC5 = LO;
            
            ptr -> grnPWM = LO;
            PORTCbits.RC4 = ptr -> grnPWM;
        }
        if(PORTAbits.RA2 == LO) //data.redButton == LO)
        {
            twoFunctionButton(&buttonState);
            //PORTCbits.RC5 = HI;
           // if(dutyCycle < 1023)
            //{
           //     dutyCycle++;
           //     __delay_ms(50);
            //}
            printf("%d\n", dutyCycle);
            //printf("%d\n", buttonState);
         //   ptr -> grnPWM = HI;
         //   PORTCbits.RC4 = ptr -> grnPWM;
        }
      
    }
  
}
