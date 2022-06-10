/*
 * File:   seven_segment.c
 * Author: Nader
 *
 * Created on June 7, 2022, 8:03 AM
 */



#include"seven_segment.h"


void init_7seg()
{
    //selection lines and data lines is outputs
     
    DATA_7SEG_INIT = 0x01;

    DIGIT2_INIT = 0;
    DIGIT1_INIT = 0;
    
    INTEDG = 1;   //interrupt at pin B0 rising edge
    INTE   = 1;   // enable interrupt 
    GIE    = 1;   //enable global interrupt
    
    

}

void DEL_write_7seg(unsigned val,unsigned time)
{
    for(int i=0;i<time;i++ )
    {
        write_7seg(val);
    }
}
void write_7seg(unsigned int x)
{
    uint8_t d1 = x % 10;
    uint8_t d2 = (x %100)/10;
   // uint8_t d3 = x /100;
   /*__________________ F I R S T    D I G I T ________________________*/ 
    selec_7seg(TENS);
   // DATA_7SEG = d1;
     evaluate(d1);
    __delay_ms(5);
   /*__________________ S E C O N D    D I G I T _______________________*/  
    selec_7seg(HUNDREDS);
   // DATA_7SEG = d2;
     evaluate(d2);
    __delay_ms(5);
    /*__________________ T H I R D    D I G I T ________________________*/ 
   // selec_7seg(THOUTHANDS);
   // PORTC = d3;
   // evaluate(d3);
   // __delay_ms(5);
}

void selec_7seg(unsigned char sel )
{
    switch(sel)
    {
        case TENS      :  DIGIT1 = 0;   DIGIT2 = 1;    break;
        case HUNDREDS  :  DIGIT1 = 1;   DIGIT2 = 0;    break;
       // case THOUTHANDS:  DIGIT1 = 0;   DIGIT2 = 0;    break;
        default :
            break;
        
    }

}

void evaluate(unsigned char x)
{
     switch(x)
    {
        case 0  : DATA_7SEG = 0xfc;     break; 
        case 1  : DATA_7SEG = 0x60;     break;
        case 2  : DATA_7SEG = 0xda;     break;
        case 3  : DATA_7SEG = 0xf2;     break;
        
        case 4  : DATA_7SEG = 0x66;     break;
        case 5  : DATA_7SEG = 0xb6;     break;
        case 6  : DATA_7SEG = 0xbe;     break;
        
        case 7  : DATA_7SEG = 0xe0;     break;
        case 8  : DATA_7SEG = 0xfe;     break;
        case 9  : DATA_7SEG = 0xf6;     break;
        
        default :
             DATA_7SEG = 0xfc;     break; 
            break;
        
    }
    
    
    
}