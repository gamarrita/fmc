/* @file fm_module.c
 *
 * @brief Each source file shall be comprised of some or all of the following
 * sections, in the order listed down below.
 * Comenzar cada nuevo archivo usando un template. Hay un templeate general a
 * todos los proyectos que puede ser usado hata el momento de introducir un
 * cambio que solo respondera a un proyecto en progreso, es ese caso el
 * template pasara a ser parte del proyecto.
 *
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 *
 */

// Includes.

#include "fmc.h"
#include "lcd.h"
#include "string.h"

// Typedef.

/*
 * The names of all new data types, including structures, unions, and
 * enumerations, shall consist only of lowercase characters and internal
 * underscores and end with ‘_t’.
 *
 * All new structures, unions, and enumerations shall be named via a typedef.
 *
 */

// Const data.

// Defines.

//Debug.

/*
 * To temporaly disable a block of code, use preprocessor's conditional
 * compilation features, eg, the following one should be used to increase the
 * the debug output information.
 *
 */
#ifndef NDEBUG
#endif

// Project variables, non-static, at least used in other file.

// External variables.

// Global variables, statics.

// Private function prototypes.

// Private function bodies.

// Public function bodies.

/*
 * Convierte un entero 32 bits sin signo a numero a texto.
 *
 * @param num un entero sin signo de 32 bits.
 * @param leading_char caracter de relleno, cero para no rellenar.
 * @param al rellenar debemos indicar a que ancho con esta variable.
 * @param p_str string destino, por referencia.
 * @param str_size tamaño del string
 */
int fm_lcd_u32_to_str(uint32_t num, char leading_char, int str_width, char *p_str, int str_size)
{
    int idx_1 = 0;

    /*
     * Este es el unico chequeo de contorno. Verifica que el tamaño del string
     * no sea menor a LINE_BUFFER_SIZE, calculado como suficiente para operar
     * con las lineas del lcd.
     */
    if(str_size < LINE_BUFFER_SIZE)
    {
        return -1;
    }

    // Esta linea es necesaria para representa bien a num = 0
    p_str[idx_1] = num  % 10 + '0';

    while(num)
    {
        idx_1++;
        num /= 10;
        p_str[idx_1] = num % 10 + '0';
    }

    if(leading_char)
    {
        while(idx_1 < str_width - 1)
        {
            idx_1++;
            p_str[idx_1] = leading_char;
        }
    }
    p_str[idx_1] = '\0';
    idx_1--;

    int idx_2 = 0;
    char ch_temp;

    while(idx_1 > idx_2)
    {
        ch_temp = p_str[idx_1];
        p_str[idx_1] = p_str[idx_2];
        p_str[idx_2] = ch_temp;
        idx_1--;
        idx_2++;
    }
    return 0;
}

/*
 * Agrega el punto decimal a un string que representa un entero.
 * Esta funcion es tipicamente usada luego de  fm_lcd_u32_to_str();
 *
 * @param fp numero con punto decimal
 * @param p_str puntero al string destino
 * @param str_size tamaño del string
 *
 */
int fm_lcd_fp_add_dot(fmc_fp_t fp, char *p_str, int str_size)
{
    int idx_end;
    int idx_now;


    if(fp.res == 0)
    {
        return 0;
    }

    // Como indice apunta a terminador nulo
    idx_now = strlen(p_str);

    // Si largo del string + 1 + termiando nulo + lugar para el punto es mayor
    // o igual que el tamaño del string entonces no entra el '.'
    if((idx_now + 1 + 1) >= str_size)
    {
        return -1;
    }

    // Como indice apunta a donde debe ir el '.'
    idx_end = idx_now - fp.res;

    while(idx_now != idx_end)
    {
       p_str[idx_now + 1] = p_str[idx_now];
       idx_now --;
    }
    p_str[idx_now + 1] = p_str[idx_now];
    p_str[idx_now] = '.';

    return 0;
}

// Interrupts

/*** end of file ***/
