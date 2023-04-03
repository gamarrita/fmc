/* @file fm_module.c
 *
 * @brief Aqui se tienen los valores de fabrica, se usan al menos en las
 * siguientes situaciones:
 * Al encender el equipo por primera vez las variables de entorno
 * tomaran estos valores.
 * Si el usuario tiene problemas puede resetear a valores de fabrica.
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 *
 */

// Includes.

#include "fm_factory.h"
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

/*Los valores de fabrica por el momento coinciden con los de configuracion,
no con los de entorno. En algun momento se puede necesitar separar valor
de fabrica con los d econfiguraicon.
*/


static fmc_totalizer_t ttl_config =
{
    .pulse = 24680000,
    .volume.num = 123400,
    .volume.res = 2,
    .factor.num = 200000, // pulsos / unidad_volumen
    .factor.res = 3,
    .unit_volume = UNIT_LITER,
 };

static fmc_totalizer_t acm_config =
{
    .pulse = 1002,
    .volume.num = 0,
    .volume.res = 3,
    .factor.num = 200000,
    .factor.res = 3,
    .unit_volume = UNIT_LITER,
 };


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

fmc_totalizer_t fm_factory_get_acm()
{
    return acm_config;
}

fmc_totalizer_t fm_factory_get_ttl()
{
    return ttl_config;
}

void fm_factory_set_acm(fmc_totalizer_t totalizer)
{
    acm_config = fm_factory_get_acm();
}




// Interrupts

/*** end of file ***/
