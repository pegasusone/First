//*****************************************************************************
//
 //! �ṩһ����ȷ����ʱ�� 
 //!
 //! \param ulCount Ϊ��Ҫ��ʱ��ʱ�����ڡ� 
 //!
 //! �������ṩһ����ȷ����ʱ���ṩ�˲�ͬ�������Ļ�����ԡ�
 //!
 //! һ��ѭ����Ҫʹ��3��ʱ�����ڡ� 
 //!
 //! \return �ޡ� 
 //
 //*****************************************************************************
#include "delay.h"
extern unsigned int SystemCoreClock;
 /**
 * @breif ��ʱ���� 
 * @param ms ��ʱ��ʱ��
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
* @breif ��ʱnop����
* @param n:��ʱn��nop
**/
void Delay_nop(unsigned int n)
{
	unsigned int  i;
	for(i=0;i<n;i++)
	{
		__nop();
	}
}


