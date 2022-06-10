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
#ifndef SEVEN_SEGMENT_H
#define	SEVEN_SEGMENT_H

#include "config.h"

#include <xc.h> // include processor files - each processor file is guarded.  
  

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

 
    
#define DIGIT1             PORTDbits.RD7
#define DIGIT2             PORTDbits.RD6
#define DIGIT1_INIT        TRISDbits.TRISD7  
#define DIGIT2_INIT        TRISDbits.TRISD6 

#define DATA_7SEG           PORTB
#define DATA_7SEG_INIT      TRISB


#define TENS         0
#define HUNDREDS     1
#define THOUTHANDS   2


unsigned int seven_data = 0;

/*****************  F U N C T I O N    P R O T O T Y P I N G  *****************/

void init_7seg();
void write_7seg(unsigned int);
void selec_7seg(unsigned char);
void evaluate(unsigned char); 
void DEL_write_7seg(unsigned int,unsigned int);


#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* SEVEN_SEGMENT_H */

