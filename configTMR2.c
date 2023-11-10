#include "constantsVariables.h"
void configTMR2(void)
{
    INTCONbits.GIE = HI;
    INTCONbits.PEIE = HI;
    /*bit 2 TMR2ON: Timer2 On bit
    1 = Timer2 is on
    0 = Timer2 is off*/
    T2CONbits.TMR2ON = LO;  // TMR2 is off
    
    /*bit 1-0 T2CKPS<1:0>: Timer2 Clock Prescale Select bits
    00 = Prescaler is 1
    01 = Prescaler is 4
    1x = Prescaler is 16*/
    T2CONbits.T2CKPS1 = HI; // prescaler is 1:1
    T2CONbits.T2CKPS0 = HI;
    
    /*bit 6-3 TOUTPS<3:0>: Timer2 Output Postscale Select bits
    0000 =1:1 postscale
    0001 =1:2 postscale
    ?
    ?
    ?
    1111 =1:16 postscale*/
    T2CONbits.TOUTPS3 = HI; // postscaler = 1:2 to allow a Tosc(0.5us) count up to 2000
    T2CONbits.TOUTPS2 = HI;
    T2CONbits.TOUTPS1 = HI;
    T2CONbits.TOUTPS0 = HI; 
    
    /*The Timer2 module has an 8-bit period register, PR2.
    Timer2 increments from 00h until it matches PR2 and
    then resets to 00h on the next increment cycle. PR2 is
    a readable and writable register.*/
    
    TMR2 = 0x00;    // start TMR2 counting from 0 (8-bit register))
    PR2 =255;     // PR2 is set to 255, so when TMR2 increments from 0 to 255, it will initiate a TMR2 interrupt (8-bit register))
    
    INTCONbits.GIE = HI;
    INTCONbits.PEIE = HI;
    PIE1bits.TMR2IE = HI;
    
    PIR1bits.TMR2IF = LO;
    T2CONbits.TMR2ON = HI;  // TMR2 is on
}
