/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

/* TODO Application specific user parameters used in user.c may go here */

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */

void InitApp(void);         /* I/O and Peripheral Initialization */
#define STEP LATBbits.LATB15
#define DIR LATBbits.LATB14
#define SLP LATBbits.LATB13
#define RST LATBbits.LATB12
#define ECHO PORTBbits.RB10 
#define TRIG LATBbits.LATB11
#define ARDUINO LATBbits.LATB5
#define RETOUR PORTBbits.RB6

#define UART_BAUDRATE 1000000
#define UART_BRG ((FCY/UART_BAUDRATE)/16) - 1

#define SERVO_ID 2




