/* #include "uart_plot.h"
*
* Creada por: Ing. Abiezer Hernandez O.
* Fecha de creacion: 28/07/2020
* Electronica y Circuitos
*
*/

#include <xc.h>
#define _XTAL_FREQ 48000000

#include "uart.h"

void Uart_Read_Plot(char b_ini, char b_fin, char* tr_or, char* n_str, int s_buf);