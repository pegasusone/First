#ifndef _delay_H_
#define _delay_H_


#ifdef __cplusplus
extern "C" {
#endif

__asm void SysCtlDelay(unsigned long ulCount);
void Delay_nop(unsigned int n);
void DelayMs(unsigned int ms);


#ifdef __cplusplus
}
#endif


#endif

