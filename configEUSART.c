#include "constantsVariables.h"
void configEUSART(void)
{
    /*The operation of the EUSART module is controlled
    through three registers:
     Transmit Status and Control (TXSTA)
     Receive Status and Control (RCSTA)
     Baud Rate Control (BAUDCTL)
     Baud Rate registers (SPBRGH:SPBRG)
     PORT baud rate 9600*/
    
    
   
    TXSTAbits.TXEN = HI;    /*Setting the TXEN bit of the TXSTA register enables the
                             transmitter circuitry of the EUSART.*/
    RCSTAbits.SPEN = HI;    /*Setting the SPEN bit of the
                            RCSTA register enables the EUSART and automatically
                            configures the TX/CK I/O pin as an output. If the TX/CK
                            pin is shared with an analog peripheral, the analog I/O
                            function must be disabled by clearing the corresponding
                            ANSEL bit. The TXIF Transmitter Interrupt flag is set
                            when the TXEN enable bit is set.*/
    TXSTAbits.SYNC = LO;    /*Clearing the SYNC bit of the TXSTA register configures
                             the EUSART for asynchronous operation.*/
    
     TRISBbits.TRISB7 = LO;  // pin 10 is the TX pin
    SPBRG = 12;             // Baud rate = 9600
    
    /*To set up an Asynchronous Transmission:
    1. Initialise the SPBRGH:SPBRG registers for the
    appropriate baud rate. Set or clear the BRGH
    and BRG16 bits, as required, to achieve the
    desired baud rate.
    2. Enable the asynchronous serial port by clearing
    bit SYNC and setting bit SPEN.
    3. If interrupts are desired, set enable bit TXIE.
    4. If 9-bit transmission is desired, set transmit bit
    TX9. Can be used as address/data bit.
    5. Enable the transmission by setting bit TXEN,
    which will also set bit TXIF.
    6. If 9-bit transmission is selected, the ninth bit
    should be loaded in bit TX9D.
    7. Load data to the TXREG register (starts
    transmission).*/
}
