/* #include "pwm.h"
*
* Creada por: Ing. Abiezer Hernandez O.
* Fecha de creacion: 16/02/2021
* Electronica y Circuitos
*
*/

#include <xc.h>
#define _XTAL_FREQ 48000000

#define USE_PWM_1
//#define USE_PWM_2

void PWM_Init(void);
#ifdef USE_PWM_1
void PWM_1_Set_Duty(unsigned char value);
#endif

#ifdef USE_PWM_2
void PWM_2_Set_Duty(unsigned char value);
#endif