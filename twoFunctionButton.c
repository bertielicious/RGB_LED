#include "constantsVariables.h"
void twoFunctionButton(uint8_t *statePtr) //statePtr points to buttonState, with is 0 on reset
{
    switch (*statePtr)
    {
       case 0:
          statePtr = 1;
          break;
          
        case 1:
            while(PORTAbits.RA2 == HI)   //wait while button is not pressed
            {
                statePtr = 1;
            }
            statePtr = 2;
            break;
            
        case 2:
            while(PORTAbits.RA2 == LO)
            {
                if(dutyCycle < 1023)
                {
                    dutyCycle= dutyCycle + 1;  
                    __delay_ms(10);
                }
            }
            statePtr = 3;
            break;
         
        case 3:
            while(PORTAbits.RA2 == LO)
            {
                statePtr = 3;
            }
            statePtr = 4;
            break;
            
        case 4:
            while(PORTAbits.RA2 == HI)   //wait while button is not pressed
            {
                statePtr = 4;
            }
            statePtr = 5;
            break;
        
        case 5:
            while(PORTAbits.RA2 == LO)
            {
                if(dutyCycle >0)
                {
                    dutyCycle= dutyCycle - 1;
                    __delay_ms(10);
                }
            }
            statePtr = 6;
            break;
            
        case 6:
             while(PORTAbits.RA2 == LO)
             {
                 statePtr = 6;
             }
             statePtr = 1;
             break;
    }
    buttonState = statePtr;
}
