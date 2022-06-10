/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef IOPREPHERALS_H
#define	IOPREPHERALS_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "config.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    
    
#define COOLER_INIT     TRISCbits.TRISC4
#define HEATER_INIT     TRISCbits.TRISC5    
#define UP_SW_INIT      TRISCbits.TRISC6 
#define DOWN_SW_INIT    TRISCbits.TRISC7   
    
#define COOLER          PORTCbits.RC4
#define HEATER          PORTCbits.RC5 
#define UP_SW           PORTCbits.RC6
#define DOWN_SW         PORTCbits.RC7    
    
 
typedef  enum
{
   UP_SWITCH_PRESSED   ,
   NOTHING_PRESSED     ,        
   DOWN_SWITCH_PRESSED
           
}sw_event;
    

    void init_switches();
    void init_cooler_heater();
    
    
    void cooler_on();
    void heater_on();
    
    void cooler_off();
    void heater_off();
    
    sw_event sw_check();
    
    
    
    
    
    
    
    
 
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* IOPREPHERALS_H */

