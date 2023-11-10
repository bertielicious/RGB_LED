
#include "constantsVariables.h"
void configOsc(void)
{
    /*8MHz HF INTERNAL OSC IMPLEMENTED
     bit 7 Unimplemented: Read as ?0?
bit 6-4 IRCF<2:0>: Internal Oscillator Frequency Select bits
111 = 8MHz
110 = 4 MHz (default)
101 = 2MHz
100 = 1MHz
011 = 500 kHz
010 = 250 kHz
001 = 125 kHz
000 = 31 kHz (LFINTOSC)
bit 3 OSTS: Oscillator Start-up Time-out Status bit(1)
1 = Device is running from the external clock defined by FOSC<2:0> of the CONFIG register
0 = Device is running from the internal oscillator (HFINTOSC or LFINTOSC)
bit 2 HTS: HFINTOSC Status bit (High Frequency ? 8 MHz to 125 kHz)
1 = HFINTOSC is stable
0 = HFINTOSC is not stable
bit 1 LTS: LFINTOSC Stable bit (Low Frequency ? 31 kHz)
1 = LFINTOSC is stable
0 = LFINTOSC is not stable
bit 0 SCS: System Clock Select bit
1 = Internal oscillator is used for system clock
0 = Clock source defined by FOSC<2:0> of the CONFIG register
     
     
     */
    OSCCONbits.IRCF2 = HI;  // 8MHz Fosc
    OSCCONbits.IRCF1 = HI;
    OSCCONbits.IRCF0 = HI;
    OSCCONbits.OSTS = LO;
    OSCCONbits.SCS = LO;    //Clock source defined by FOSC<2:0> of the CONFIG register
    
}
