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


#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */
#include <stdio.h>
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */
#include <libpic30.h>
#include <p33FJ128MC802.h>
#include "time.h"
#include "xc.h"


 
/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */



void delay_us(unsigned int us) {
    __delay32(us * (FCY / 1000000UL));
}


void Timer_Init (void){ // Timer 2 pour ECHO Ultrason distance
    
    T1CONbits.TON = 0;      // Turn off Timer1
    T1CONbits.TCS = 0;      // Select internal clock (Fosc/2)
    T1CONbits.TCKPS = 0b00; // Set prescaler to 1:1
    T1CONbits.TGATE = 0;    // Disable gated timer mode
    TMR1 = 0x0000;          // Clear Timer1 register

    // Configure Input Capture 1
    IC1CONbits.ICM = 0b000; // Disable Input Capture module
    IC1CONbits.ICTMR = 1;   // Select Timer1 as the capture source
    IC1CONbits.ICI = 0b00;  // Interrupt on every capture event
    IC1CONbits.ICM = 0b001; // Enable Input Capture module

    // Configure interrupts
    IFS0bits.IC1IF = 0;     // Clear IC1 interrupt flag
    IEC0bits.IC1IE = 1;     // Enable IC1 interrupt
    IPC0bits.IC1IP = 4;     // Set IC1 interrupt priority
}


    
 void RotMot(int angle){
     
     int i=0;
        for(i;i<(angle/1.8);i++){
        STEP=1;
        __delay_ms(5); //modifier le delay modifiera la vitesse
        STEP=0;
        __delay_ms(5);
            
        }
 }
 
 
 void Ultrason(void){
     
     TRIG=1;
     __delay_us(10);
     TRIG=0;
 }
 
 
void UART_Init(){
    
    U1BRG = UART_BRG; // Baud rate setting
    U1MODEbits.BRGH = 0; // Low-speed mode

    U1MODEbits.UEN = 0b00; // Only RX and TX enabled
    U1MODEbits.PDSEL = 0b00; // 8-bit data, no parity
    U1MODEbits.STSEL = 0; // 1 stop bit

    U1STAbits.UTXEN = 1; // Enable transmission
    U1MODEbits.UARTEN = 1; // Enable UART module
    
    
}

void UART_Write(uint8_t data) {
    while (!U1STAbits.TRMT);    // Wait until transmit shift register is empty
    U1TXREG = data;             // Load data into transmit register
}

void Servo_MoveTo(unsigned char servoID, unsigned int angle)
{
    unsigned char command[7];
    unsigned int position = (unsigned int)(angle * 100) / 90; // Convert angle to position value

    // Construct the command packet
    command[0] = 0xFF; // Start byte
    command[1] = 0xFF; // Start byte
    command[2] = servoID; // Servo ID
    command[3] = 0x04; // Data length
    command[4] = 0x03; // Write command type
    command[5] = 0x2A; // Goal position address
    command[6] = position & 0xFF; // Goal position (LSB)
    command[7] = (position >> 8) & 0xFF; // Goal position (MSB)

    // Send the command packet via UART
    U1BRG = 1;

    // Send the command packet via UART
    unsigned char i;
    
    for (i = 0; i < 8; i++)
    {
        while (!U1STAbits.TRMT); // Wait for the transmit buffer to be empty
        U1TXREG = command[i]; // Send the byte
    }
}

unsigned int distance;

unsigned int measure_distance() {
    

    // Trigger ultrasonic sensor
    Ultrason();

    // Wait for the echo pin to go high
    while (!ECHO);

    // Measure the duration of the echo pulse
    unsigned int pulse_duration = 0;
    while (ECHO) {
        delay_us(10);
        pulse_duration += 10;
    }

    // Calculate distance in centimeters
    distance = pulse_duration/58;

    return distance;
}

int16_t main(void){

    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitApp();
    

    /* TODO <INSERT USER APPLICATION CODE HERE> */
    DIR=1;
    SLP=1;
    RST=1;
    
    TRIG=0;
    
    PLLFBD = 38;            // M=40
    CLKDIVbits.PLLPOST = 0; // N1=2
    CLKDIVbits.PLLPRE = 0;  // N2=2
    OSCTUN = 0;

    // Disable Watchdog Timer
    RCONbits.SWDTEN = 0;
    ARDUINO=0;
    int D,j;
    
    
    
    while(1)
    {

        for (j = 0; j < 20; j++) {
            D = measure_distance();
            __delay_ms(500);
            if (D < 10) {
                ARDUINO = 1;

                while (RETOUR != 1) {
                    ARDUINO = 1;
                }

                // ARDUINO=0;
                //__delay_ms(200);

                RotMot(90);
                __delay_ms(500);

                //ARDUINO=1;
                while (RETOUR != 1) {
                    ARDUINO = 1;
                    __delay_ms(500);
                }

                ARDUINO = 0;
                RotMot(90);
                ;
            }
        }






    }

    return 0;



}






    

        
    
    
    
        
        
        
        
    

