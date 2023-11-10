/* 
 * File:   constantsVariables.h
 * Author: User
 *
 * Created on 06 October 2023, 21:49
 */

#ifndef CONSTANTSVARIABLES_H
#define	CONSTANTSVARIABLES_H

#include <xc.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
typedef struct
{
   uint8_t redButton:1;
   uint8_t grnButton:1;
   uint8_t bluButton:1;
   uint8_t redPWM:1;
   uint8_t grnPWM:1;
   uint8_t bluPWM:1;
}rgb;


 
 
//input RGB pins
  // pin 17
   // pin 3
   // pin 13*/

//output PWM pins
#define rgbptr -> r PORTCbits.RC5   // pin 5
/*#define grnPWM PORTCbits.RC4   // pin 6
#define bluPWM PORTCbits.RC3   // pin 7*/

enum{LO,
    HI};
uint16_t pwm = 0;

uint16_t dutyCycle = 0;

 uint8_t buttonState = 0;




        
// diagnostic LED yellow
#define yellowDiagnostic LATCbits.RC1;
#define _XTAL_FREQ 8000000
#endif	/* CONSTANTSVARIABLES_H */

