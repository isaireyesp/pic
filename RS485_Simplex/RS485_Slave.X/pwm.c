/* #include "adc.h"
*
* Creada por: Ing. Abiezer Hernandez O.
* Fecha de creacion: 16/02/2021
* Electronica y Circuitos
*
*/

#include "pwm.h"

void PWM_Init(void)
{
    PR2 = 0x3E;                             // Valor del periodo
    #ifdef USE_PWM_1
    CCPR1L = 0;                             // Inicia el CCP1 en 0
    TRISCbits.TRISC2 = 0;                   // Pin C2 como salida
    #endif

    #ifdef USE_PWM_2
    CCPR2L = 0;                             // Inicia el CCP2 en 0
    TRISCbits.TRISC1 = 0;                   // Pin C1 como salida
    #endif
    T2CON = 0x03;                           // Configuracion del timer 2
    
    #ifdef USE_PWM_1
    CCP1CON = 0x0C;                         // Configura el CCP1 en modo PWM
    #endif
    #ifdef USE_PWM_2
    CCP2CON = 0x0C;                         // Configura el CCP2 en modo PWM
    #endif
    TMR2 = 0;                               // Timer 2 en 0
    T2CONbits.TMR2ON = 1;                   // Timer 2 ON
}

void PWM_1_Set_Duty(unsigned char value)
{
    CCPR1L = (value >> 2);
}

void PWM_2_Set_Duty(unsigned char value)
{
    CCPR2L = (value >> 2);
}