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

#include "pwm.h"                            // Libreria del pwm
#include "uart.h"                           // Libreria del modulo USART
#include "uart_plot.h"                      // Libreria para leer tramas desde el puerto serial

char cad_p[14];                             // Almacena la cadena principal
char buffer[2][4];

void main()
{
    ADCON1bits.PCFG = 0x0F;                 // Coloca todos los pines como digitales
    TRISDbits.RD0 = 0;                      // Pin RD0 como salida
    TRISDbits.RD1 = 0;                      // Pin RD1 como salida
    LATDbits.LD0 = 0;
    LATDbits.LD1 = 0;
    PWM_Init();                             // Inicializa el pwm, solo el canal 1
    Uart_Init(9600);                        // Inicializa la comunicacion serial a 9600 baudios
    
    while(1)
    {
        if(Uart_Available() > 0)            // Verifica si ha recibido datos
        {
            Uart_Read_String(cad_p, 14);
            Uart_Read_Plot('I', 'N', cad_p, buffer[0], strlen(cad_p));
            Uart_Read_Plot('N', 'F', cad_p, buffer[1], strlen(cad_p));
            
            short estado_led1 = (buffer[0][0] - '0');
            short estado_led2 = (buffer[0][1] - '0');
            unsigned char valor_pwm = atoi(buffer[1]);
            
            LATDbits.LD0 = estado_led1;
            LATDbits.LD1 = estado_led2;
            PWM_1_Set_Duty(valor_pwm);
        }
    }
}