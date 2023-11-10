#include "constantsVariables.h"
void configPWM(void)
{
     TRISCbits.TRISC5 = LO; 
     
     PR2 = 255;             //Set the PWM period by loading the PR2 register
     TMR2 = 0x00;
    CCP1CONbits.P1M1 = LO;  //PWM config pins, Single output; P1A modulated; P1B, P1C, P1D assigned as port pins
    CCP1CONbits.P1M0 = LO;
    
    CCP1CONbits.CCP1M3 = HI;    //PWM mode; P1A, P1C active-high; P1B, P1D active-high
    CCP1CONbits.CCP1M2 = HI;
    CCP1CONbits.CCP1M1 = LO;
    CCP1CONbits.CCP1M0 = LO;
    
    
    
   
   
  
    /*11.3.7 SETUP FOR PWM OPERATION
The following steps should be taken when configuring
the CCP module for PWM operation:
1. Disable the PWM pin (CCP1) output driver by
setting the associated TRIS bit.
2. Set the PWM period by loading the PR2 register.
3. Configure the CCP module for the PWM mode
by loading the CCP1CON register with the
appropriate values.
4. Set the PWM duty cycle by loading the CCPR1L
register and DC1B<1:0> bits of the CCP1CON
register.
5. Configure and start Timer2:
? Clear the TMR2IF interrupt flag bit of the
PIR1 register.
? Set the Timer2 prescale value by loading the
T2CKPS bits of the T2CON register.
? Enable Timer2 by setting the TMR2ON bit of
the T2CON register.
6. Enable PWM output after a new PWM cycle has
started:
? Wait until Timer2 overflows (TMR2IF bit of
the PIR1 register is set).
? Enable the CCP1 pin output driver by clearing
the associated TRIS bit.*/
}
