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

static const uint32_t g_scalar[] = {1, 10, 100, 1000, 10000, 100000, 1000000};


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


void fmc_totalizer_clear_pulse(fmc_totalizer_t *p_totalizer)
{
    p_totalizer->pulse = 0;
    fmc_totalizer_refresh(p_totalizer);
}

fmc_totalizer_t fmc_totalizer_init(fmc_totalizer_t totalizer)
{
    fmc_totalizer_refresh(&totalizer);

    return totalizer;
}


void fmc_totalizer_refresh(fmc_totalizer_t *p_totalizer)
{
    uint64_t result;

    result = (uint64_t) p_totalizer->pulse;
    // pulsos escalados en el factor y en la resolucion a mostrar
    result *= g_scalar[p_totalizer->factor.res + p_totalizer->volume.res];
    result /= p_totalizer->factor.num;
    p_totalizer->volume.num = (uint32_t)result;
}

// Interrupts

/*** end of file ***/
