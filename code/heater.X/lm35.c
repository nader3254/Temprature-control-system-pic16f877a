/*
 * File:   lm35.c
 * Author: Nader
 *
 * Created on June 7, 2022, 2:06 PM
 */

#include "lm35.h"


 void init_lm35()
 {
     
     ADCON0 = 0x41;  // Turn ADC ON, Select AN0 Channel, ADC Clock = Fosc/8
     ADCON1 = 0x80; // All 8 Channels Are Analog, Result is "Right-Justified"
      
     ADIF = 0;  // Clear ADC Interrupt Flag
     ADIE = 1;  // ADC Interrupt Enable Bit
     PEIE = 1;  // Peripherals Interrupt Enable Bit
     GIE  = 1;   // Global Interrupts Enable Bit
     
     
 }
 
  void start_lm35(uint8_t channle)
  {

    ADCON0 &= 0b11000101;                        // Clear The Channel Selection Bits
    ADCON0 |= channle<<3;                       // Select The Required Channel (ANC)
    __delay_us(30);                            // Wait The Aquisition Time
                                            // The Minimum Tacq = 20us, So That should be enough
    GO_DONE = 1;                             
      
      
  }
  
   void reset_lm35()
   {
       IS_LM35_CONERSION_DONE = 0 ;
   }
  
 uint16_t read_lm35()
 {
   
    return ((ADRESH << 8) + ADRESL);      // Return The Right-Justified 10-Bit Result
}
 
 //analog voltage =( 5 * adc value )/1023
 
 
 uint8_t  actual_temprature(uint16_t adc_conversion)
 {
     
     uint8_t analog_volt = (5 * adc_conversion )/1023;
     
     
     //lm35 transfer function  : VOUT  = 10 mv/°F × T
     
     uint8_t temprature = (analog_volt * 0.0);
     
     return temprature;
     
     
 }
     
