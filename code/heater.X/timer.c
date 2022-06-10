/*
 * File:   timer.c
 * Author: Nader
 *
 * Created on June 7, 2022, 8:36 AM
 */

#include "timer.h"

/*********************** C O M P A R E   M O D E ********************/
// compare the TMR1 With CCPR1

void timer1_compare_init()
{

 
 
  //--[ Configure The Timer1 Module To Operate In Timer Mode ]--
  TMR1 = 0;
   //prescaler 1:1
  T1CKPS0 = 0;
  T1CKPS1 = 0;
  //selecting clock source as internal clock source (fosc/4)
  TMR1CS = 0;
  //enable timer 1
  TMR1ON = 1;
 
  //--[ Configure The CCP1 Module To Operate in Compare Mode ]--
  // Preload The CCPR1 Register
  CCPR1 = 5;
  // CCP in Compare Mode, CCPx Pin Is Unchanged & Trigger Special Event
  CCP1M0 = 1;
  CCP1M1 = 1;
  CCP1M2 = 0;
  CCP1M3 = 1;
 
  // Enable CCP1 Interrupt
  CCP1IE = 1;
  PEIE = 1;
  GIE = 1;
 
}

void  sleep(float time)
{
      X2 = time * 31;
}
 void  continue_counting()
 {
     X++;
 }
 uint8_t   is_Timeout()
 {
    if(X==X2)  
    {
        return 1;
    }
    else
    {
        return 0;   
    }
 }
void       reset()
{
    X  = 0;
    X2 = 0;
}


