#include <stdint.h> 
#include <stdbool.h> 
#include "tm4c123gh6pm.h" 
int main(void) 
{ 
SYSCTL_RCGC2_R |=   0x00000020; 
GPIO_PORTF_LOCK_R = 0x4C4F434B; 
GPIO_PORTF_CR_R   = 0x1F; 
GPIO_PORTF_DEN_R  = 0x1E; 
GPIO_PORTF_DIR_R  = 0x0E; 
GPIO_PORTF_PUR_R  = 0x10; 
GPIO_PORTF_DATA_R = 0x0; 
long int x; 
long int delay = 675000; 
GPIO_PORTF_DIR_R &= ~(0x11); 
GPIO_PORTF_DEN_R |= 0x11; 
while (1) { 
if (((GPIO_PORTF_DATA_R & 0x01) == 0) && ((GPIO_PORTF_DATA_R & 0x10) == 0)) { 
GPIO_PORTF_DATA_R = 0x08; 
x=0; 
while ( x < delay) 
x ++ ;} 
else if ((GPIO_PORTF_DATA_R & 0x10) == 0) { 
GPIO_PORTF_DATA_R = 0x02; 
x=0; 
while ( x < delay) 
x ++ ;} 
else if ((GPIO_PORTF_DATA_R & 0x01) == 0) { 
GPIO_PORTF_DATA_R = 0x04; 
x=0; 
while ( x < delay) 
x ++ ; 
} 
else { 
GPIO_PORTF_DATA_R = 0x00; 
x=0; 
while ( x < delay) 
x ++ ; 
} 
} 
} 