/* #include "uart_plot.h"
*
* Creada por: Ing. Abiezer Hernandez O.
* Fecha de creacion: 28/07/2020
* Electronica y Circuitos
*
*/

#include "uart_plot.h"

void Uart_Read_Plot(char b_ini, char b_fin, char* tr_or, char* n_str, int s_buf)
{
    int conta_ini = 0;
    int conta_fin = 0;
    for(int i=0; i<s_buf; i++)
    {
        if(tr_or[i] == b_ini){
            conta_ini = i;
            break;
        }
    }
    for(int j=0; j<s_buf; j++)
    {
        if(tr_or[j] == b_fin){
            conta_fin = j;
            break;
        }
    }
    Uart_Read_Substring(tr_or, n_str, conta_ini+1, conta_fin-1);
}