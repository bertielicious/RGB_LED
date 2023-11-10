
#include "constantsVariables.h"
void configPorts(void)
{
    OPTION_REGbits.nRABPU = LO; // enable weak pull up's on input pins
    // configure input pins to accept buttons)
    TRISAbits.TRISA2 = HI;  // button RED
    ANSELbits.ANS2 = LO;    // Digital I/O assigned to port pin
    ANSELHbits.ANS10 = LO;
    CM1CON0bits.C1OUT = LO; // Comparator off
    CM2CON0bits.C2R = LO;
    WPUAbits.WPU2 = HI; // weak pullup resistor enabled
  //  IOCAbits.IOCA2 = HI; // interrupt on change enabled
    
    
    TRISAbits.TRISA4 = HI;  // button GREEN
    ANSELbits.ANS3 = LO;    // Digital I/O assigned to port pin
    CCP1CONbits.DC1B0 = LO;
    CM1CON0bits.C1POL = LO; // Comparator off
    CM2CON0bits.C2POL = LO;
    WPUAbits.WPUA4 = HI;    // weak pullup resistor enabled
  //  IOCAbits.IOCA4 = HI;    // interrupt on change enabled
    
    
    
    TRISBbits.TRISB4 = HI;  // button BLUE
    
    ANSEL =  LO;
    ANSELH = LO;
    
    WPUBbits.WPUB4 = HI;    // weak pullup resistor enabled
  //  IOCBbits.IOCB4 = HI;    // interrupt on change enabled
    
    /*Configure PWM output ports*/
    TRISCbits.TRISC5 = LO;  // Digital I/O assigned to port pin output
    TRISCbits.TRISC4 = LO;
    TRISCbits.TRISC3 = LO;
    
    // disgnostic LED yellow
    TRISCbits.TRISC1 = LO;      // output on pin 15
    
    // disgnostic LED blue
    TRISCbits.TRISC0 = LO;      // output on pin 16
    
}
