/* @file fm_module.h
 *
 * @brief A description of the module’s purpose.
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 */

#ifndef FM_MODULE_H_
#define FM_MODULE_H_

// includes

// Macros, defines, microcontroller pins (dhs).

// Tamaño suficiente para representar en forma de string lo que se quiera escribir
// en la linea 1 o 2 del lcd
// Notar que para un entero no se necesitan mas de 8 ejemplos: 00001234 o 12345678
// Pero lo anterio no es lo mayor en tamaño que se quiciera repressentar ejemplo:
// 31.03.2023 una fecha = 9 + terminador nulo
// 1.2.3.4.5.6.7.8 = 15 + terminador nulo
#define LINE_BUFFER_SIZE 20

//
// En el firmware hay desproligidad y duplicacion de estas macros, mejorar!!!
#define LINE_1_DIGITS (8+1) // digitos linea 1 + terminador nulo.
#define LINE_2_DIGITS (7+1) // digitos linea 2 + terminador nulo.
#define LINE_1_DIGITS_DOT (8+1+1) // digitos liena 1 + punto + terminador nulo.
#define LINE_2_DIGITS_DOT (7+1+1) // digitos liena 2 + punto + terminador nulo.


// Typedef.

// Defines.

// Function prototypes

int fm_lcd_u32_to_str(uint32_t num, char leading_char, int str_width, char *p_str, int str_size);
int fm_lcd_fp_add_dot(fmc_fp_t fp, char *p_str, int str_size);

#endif /* MODULE_H */

/*** end of file ***/
