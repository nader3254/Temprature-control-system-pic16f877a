/*
 * File:   main.c
 * Author: Nader
 *
 * Created on June 7, 2022, 6:57 AM
 */


#include <xc.h>
#include "config.h"
#include "seven_segment.h"
//#include "timer.h"
#include "io_prepherals.h"
#include "lm35.h"

uint8_t desired_temprature = 0;
uint8_t current_temprature = 0;

uint8_t display_desirered_value =0;



void prepheral_testing();

void main(void) {
     
   // timer1_compare_init();
   
    init_7seg();
    init_lm35();
    init_switches();
    init_cooler_heater();
    
    prepheral_testing();  //test all prepheals
    
    start_lm35(AN0);  //read actual temprature value  on analog pin RA0
    __delay_ms(1000);
    desired_temprature = current_temprature;
    
    
    
    
    while(1)
    {
        
       start_lm35(AN0);  //read actual temprature value  on analog pin RA0

       //displaying temprature here    
       if(display_desirered_value == 1)
       {
           for(int i=0;i<900;i++)
           {
              write_7seg(desired_temprature);
           }
           
           display_desirered_value = 0;
       }
       else
       {
           DEL_write_7seg(current_temprature,25);
       }

      
      //check the difference between desired and actual temp then start take action according to it 
      if(desired_temprature > current_temprature)
      {
          heater_on();
      }
      if(desired_temprature < current_temprature)
      {
          cooler_on();
      }
       
       
      if(desired_temprature == current_temprature)
        {
          heater_off();
          cooler_off();
        }
       
       //make sure that one output only is on   
      if((COOLER== 1) && (HEATER==1 ))
      {
          heater_off(); cooler_off();
      if(desired_temprature > current_temprature)
      {
          heater_on();
      }
      if(desired_temprature < current_temprature)
      {
          cooler_on();
      } 
           
           
      } 
   
     
      //  
    }
    
    return;
}





// Write The ISR Handler
void interrupt ISR()
{
     
 

 /***********************************************************************************************/ 
 /*          T H I S    F O R    L M 3 5     C O N V E R T I O N    P R O C E S S              */
/**********************************************************************************************/ 
    
  if ( IS_LM35_CONERSION_DONE  )
  {
      //here some shit '
      int tmp = read_lm35();
      current_temprature =  tmp * 0.01;
       reset_lm35();
    
  }
 /**********************************************************************************************/ 
   
  
  if(INTF)
  {
      
      
        // check if any switch pressed       
    if(sw_check()== UP_SWITCH_PRESSED)
        {
             __delay_ms(250);
             desired_temprature++;
     
             
        
        }
        
         if(sw_check()== DOWN_SWITCH_PRESSED)
        {
         
             __delay_ms(250);
             desired_temprature--;
             
        }
        if(desired_temprature == current_temprature)
        {
          heater_off();
          cooler_off();
        }
        
      //make sure that one output only is on   
      if(COOLER==1&&HEATER==1)
      {
      if(desired_temprature > current_temprature)
      {
          heater_on();
      }
      if(desired_temprature < current_temprature)
      {
          cooler_on();
      } 
           
           
      }
    
    
        display_desirered_value = 1;
      INTF=0;
   }
  
  
  
  
  
}

void prepheral_testing()
{
    //test seven segment 
    DIGIT1 = 0;
    for (int i=0;i<7;i++)
    {
        DATA_7SEG   = 0;
        DATA_7SEG |= (1<<i);
        __delay_ms(150);
        
    }
     DIGIT1 = 1;
     DIGIT2 = 0;
    for (int i=0;i<7;i++)
    {
        DATA_7SEG   = 0;
        DATA_7SEG |= (1<<i);
         __delay_ms(150);
    }
    DIGIT2 = 1;
    DATA_7SEG   = 0;
    
    //test cooler and heater
      heater_on();
     __delay_ms(150);
      heater_off();
      __delay_ms(150);
       cooler_on;
     __delay_ms(150);
       cooler_off; 
     // __delay_ms(150);
   
}



/*
 * 
 *       if(display_desirered_value == 1)
       {
           DEL_write_7seg(desired_temprature,20);
           display_desirered_value==0;
           heater_off();
           cooler_off;
       }
      else
      {
          DEL_write_7seg(current_temprature,20);   
      }
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *   /*   for(int i=0;i<99;i++)
        {
           // sleep(1);
           
            
               DEL_write_7seg(i,50);
              
      
             RD1=!RD1;
        }
     */
 /*       
 * 
 * 
 * 
 * 
 * 
 * if (!is_Timeout())   
    {
      
        continue_counting();
      
    }
    else
    {
        reset();
    }
 * 
 * 
 * 
 * 0000
 * 
 * 
 * 
 * 
   heater_on();
        __delay_ms(500);
        heater_off();
         __delay_ms(500);
         
          cooler_on();
        __delay_ms(500);
        cooler_off();
        __delay_ms(500);
 * 
 *    if(DOWN_SW == 1)
        {
        cooler_on();
        __delay_ms(500);
        cooler_off();
        __delay_ms(500);
        }
        
        
         if(RC6 == 1)
        {
        heater_on();
        __delay_ms(500);
        heater_off();
        __delay_ms(500);
        }
 
 
 
 
 
 
 
 
 
 
 */