#include<msp430.h>

void main()
{
char *Flash_ptr = (char*) 0x1040;

WDTCTL = WDTPW + WDTHOLD;
BCSCTL1 = CALBC1_1MHZ;
DCOCTL = CALDCO_1MHZ;
DCOCTL = CALDCO_1MHZ;

__no_operation();
FCTL3 = FWKEY;
FCTL1 = FWKEY + WRT;

FCTL1 = FWKEY + WRT;

*Flash_ptr = 0xAA;
__no_operation();
*Flash_ptr = 0xAA;

__no_operation();
*Flash_ptr = 0x00;
__no_operation();

while(1)
{
__no_operation();
}
}
