#include "constantsVariables.h"
__interrupt() void MY_ISR(void)
{
    if(INTCONbits.T0IF && INTCONbits.T0IE == HI)
    {
        PORTCbits.RC1 = ~PORTCbits.RC1; // Yellow LED pin 15
        INTCONbits.T0IF = LO;
        TMR0 = 0x00;
    }
   
    
    if(PIR1bits.TMR2IF && PIE1bits.TMR2IE == HI)
    {
       
        PORTCbits.RC0 = ~PORTCbits.RC0; // RED LED  pin 16
       
       /*The following two lines of code defines the pulse width*/
        CCPR1L = dutyCycle >> 2;
        CCP1CON = (CCP1CON | ((dutyCycle & 0x03)<<4));
       
         
       
        PIR1bits.TMR2IF = LO;
        TMR2 = 0;
        PR2 = 255;
    }
    
}
