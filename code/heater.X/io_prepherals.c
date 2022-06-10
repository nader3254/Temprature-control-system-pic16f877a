/*
 * File:   io_prepherals.c
 * Author: Nader
 *
 * Created on June 7, 2022, 11:14 AM
 */


#include "io_prepherals.h"


   void init_switches()
   {
       //make up and down switches as inputs
       UP_SW_INIT   = 1;
       DOWN_SW_INIT = 1;
   }
   void init_cooler_heater()
   {
       //make cooler and heater as outputs
       TRISDbits.TRISD1=0;
       COOLER_INIT = 0;
       HEATER_INIT = 0;
       
       PORTDbits.RD1 =0;
       cooler_off();
       heater_off();
   }

    void cooler_on()
    {
        COOLER = 1;
    }
    void heater_on()
    {
        HEATER = 1;
        PORTDbits.RD1 =1;
    }
    
    void cooler_off()
    {
        COOLER = 0;
    }
    void heater_off()
    {
        HEATER = 0;
        PORTDbits.RD1 =0;
    }
    
    
    sw_event sw_check()
    {
        if(UP_SW == 1)
        {
            return UP_SWITCH_PRESSED ;
        }
        else 
        {
           if( DOWN_SW == 1)
           {
              return DOWN_SWITCH_PRESSED ;
           }
           else
           {
               return NOTHING_PRESSED;
           }
        }
        
        
    }