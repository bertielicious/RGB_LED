#include "constantsVariables.h"
void configTMR0(void)
{
    OPTION_REGbits.T0CS = LO;
    OPTION_REGbits.PSA = LO;
    OPTION_REGbits.PS2 = HI;
    OPTION_REGbits.PS1 = HI;
    OPTION_REGbits.PS0 = HI;
    TMR0 = 0;
    INTCONbits.T0IE = HI;
    INTCONbits.T0IF = LO;
    INTCONbits.PEIE = HI;
    INTCONbits.GIE = HI;
    
}
