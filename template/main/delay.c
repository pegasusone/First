//*****************************************************************************
//
 //! 提供一个精确的延时。 
 //!
 //! \param ulCount 为需要延时的时钟周期。 
 //!
 //! 本函数提供一个精确的延时。提供了不同工具链的汇编语言。
 //!
 //! 一次循环需要使用3个时钟周期。 
 //!
 //! \return 无。 
 //
 //*****************************************************************************
#include "delay.h"
extern unsigned int SystemCoreClock;
 /**
 * @breif 延时毫秒 
 * @param ms 延时的时间
 **/
 void DelayMs(unsigned int ms)
 {
   SysCtlDelay((ms * (SystemCoreClock/3000)));
 }

 #if defined(__ICCARM__) 
 void SysCtlDelay(unsigned long ulCount)
 {
     __asm("    subs    r0, #1\n"
           "    bne.n   SysCtlDelay\n"
           "    bx      lr");
 }
 #endif

//#if defined(_CCARM_) 
 __asm void SysCtlDelay(unsigned long ulCount)
 {
     subs    r0, #1;
     bne     SysCtlDelay;
     bx      lr;
 }
//#endif
/**
* @breif 延时nop函数
* @param n:延时n个nop
**/
void Delay_nop(unsigned int n)
{
	unsigned int  i;
	for(i=0;i<n;i++)
	{
		__nop();
	}
}


