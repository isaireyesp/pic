#pragma config PLLDIV = 2, CPUDIV = OSC1_PLL2, USBDIV = 2
#pragma config FOSC = HSPLL_HS, FCMEN = OFF, IESO = OFF
#pragma config PWRT = OFF, BOR = OFF, BORV = 3, VREGEN = OFF
#pragma config WDT = OFF
#pragma config WDTPS = 32768
#pragma config CCP2MX = ON, PBADEN = OFF, LPT1OSC = OFF, MCLRE = ON
#pragma config STVREN = ON, LVP = OFF, ICPRT = OFF, XINST = OFF
#pragma config CP0 = OFF, CP1 = OFF, CP2 = OFF, CP3 = OFF
#pragma config CPB = OFF, CPD = OFF
#pragma config WRT0 = OFF, WRT1 = OFF, WRT2 = OFF, WRT3 = OFF
#pragma config WRTC = OFF, WRTB = OFF, WRTD = OFF
#pragma config EBTR0 = OFF, EBTR1 = OFF, EBTR2 = OFF, EBTR3 = OFF
#pragma config EBTRB = OFF

#define _XTAL_FREQ 48000000
#include <xc.h>
#include <stdio.h>

#include "adc.h"                            // Libreria del ADC
#include "uart.h"                           // Libreria del modulo USART
#include "map_function.h"                   // Libreria para realizar conversiones

char buffer_tx[14];

void main()
{
    ADC_Init(AN0_ANALOG);                   // Inicializa el ADC
    TRISBbits.RB0 = 1;                      // Pin RB0 como entrada
    TRISBbits.RB1 = 1;                      // Pin RB1 como entrada
    Uart_Init(9600);                        // Inicializa la comunicacion serial a 9600 baudios
    
    while(1)
    {
        short b1 = PORTBbits.RB0;
        short b2 = PORTBbits.RB1;
        unsigned char pwm = map(ADC_Read(0), 0, 1023, 0, 250);
        sprintf(buffer_tx, "I%u%uN%uF\r\n", b1, b2, pwm);
        Uart_Send_String(buffer_tx);
        __delay_ms(10);
    }
}