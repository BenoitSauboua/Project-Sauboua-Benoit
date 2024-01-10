/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC33E__)
    	#include <p33Exxxx.h>
    #elif defined(__dsPIC33F__)
    	#include <p33Fxxxx.h>
    #endif
#endif

#include <stdint.h>          /* For uint16_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include "user.h" 
#include <libpic30.h>             

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    /* TODO Initialize User Ports/Peripherals/Project here */

    /* Setup analog functionality and port direction */

    /* Initialize peripherals */
    
    TRISBbits.TRISB13=0;
    TRISBbits.TRISB14=0;
    TRISBbits.TRISB15=0;
    TRISBbits.TRISB12=0;
    TRISBbits.TRISB10=1;
    TRISBbits.TRISB11=0;
    TRISBbits.TRISB6 = 1;   
    TRISBbits.TRISB5=0;
    
    
    
    
}

 void PWM_init(void){
        
        
        TRISBbits.TRISB15 = 0;
        PTCONbits.PTOPS = 1; // PWM timer post-scale
        PTCONbits.PTCKPS = 0; // PWM timer pre-scale
        PTCONbits.PTMOD = 2; // PWM operates in Up-down Mode continuously

        PTMR = 0; // PWM counter value, start at 0
        PTPER = 1000; // PWM Timebase period

       
        PWMCON1bits.PMOD1 = 0; // PWM in complimentary mode

       
        
        PWMCON1bits.PEN1H = 1; // PWM High pin is enabled

        
        PWMCON1bits.PEN1L = 1; // PWM Low pin enabled (direction control later?)

        DTCON1bits.DTAPS = 0; //DeadTime pre-scaler
        DTCON1bits.DTA = 59; //DeadTime value for 4 us. 

        PDC1 = 11; // PWM#1 Duty Cycle register (11-bit)
        

        PTCONbits.PTEN = 1; // Enable PWM Timerbase!
        
}
 /*
 void ConfigTimer(){
     T1CONbits.TON=0;
     T1CONbits.TCS=0;
     T1CONbits.TCKPS=0b10;
 }
 
 void TimerStart(){
     unsigned long start = 0;
     start=TMR1;
     T1CONbits.TON=1;
 }
 
 void TimerStop(){
     unsigned long stop =0;
     stop=TMR1;
     T1CONbits.TON=0;
 }
 */
 

