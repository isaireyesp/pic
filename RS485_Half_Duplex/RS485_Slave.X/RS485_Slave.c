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
#include <stdlib.h>
#include <string.h>

#include "uart.h"                                   // Libreria del modulo USART

#define RS_MODE_DIR TRISCbits.RC2                   // RS_MODE 0 -> receptor, RS_MODE 1 -> transmisor
#define RS_MODE_PIN LATCbits.LC2

char buffer_rx[10];                                 // Almacena los datos recibidos del maestro
char buffer_tx[10];                                 // Almacena los datos para enviar al maestro
short bit_flag = 1;

void main()
{
    ADCON1bits.PCFG = 0x0F;                         // Coloca todos los pines como digitales
    TRISB = 0xFF;                                   // Puerto B como entrada
    TRISDbits.RD0 = 0;                              // Pin RD0 como salida
    TRISDbits.RD1 = 0;                              // Pin RD1 como salida
    TRISDbits.RD2 = 0;                              // Pin RD2 como salida
    TRISDbits.RD3 = 0;                              // Pin RD3 como salida
    LATD = 0x00;                                    // Limpia el puerto D
    RS_MODE_DIR = 0;                                // Pin RS_MODE como salida
    RS_MODE_PIN = 0;                                // Inicializa en 0 el pin RS_MODE
    Uart_Init(9600);                                // Inicializa la comunicacion serial a 9600 baudios
    
    while(1)
    {
        while(bit_flag == 1)
        {
            RS_MODE_PIN = 0;                        // Modo receptor
            Uart_Read_String(buffer_rx, 10);        // Lee el dato del maestro
            char dato_rx = atoi(buffer_rx);
            LATD = dato_rx;
            __delay_ms(10);
            bit_flag = 0;
        }
        
        RS_MODE_PIN = 1;                             // Modo transmisor
        __delay_ms(2);
        char v_dato = PORTB & 0x0F;
        sprintf(buffer_tx, "%u\r\n", v_dato);
        Uart_Send_String(buffer_tx);                // Envia los datos al maestro
        __delay_ms(2);
        bit_flag = 1;
    }
}