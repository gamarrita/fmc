/* @file fm_module.h
 *
 * @brief A description of the module’s purpose.
 *
 * @par
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 */

#ifndef FMC_H_
#define FMC_H_

// includes

#include <stdint.h> // defeniciones del tipo uint32_t


// Macros, defines, microcontroller pins (dhs).

typedef enum
{
    UNIT_LITER = 'L',
    UNIT_METER_CUBIC = 'M',
    UNIT_VOLUME_END = 0xFF,
}fmc_unit_volume_t;

typedef enum
{
    UNIT_DAY = 'D',
    UNIT_HOUR = 'H',
    UNIT_MINUTE = 'M',
    UNIT_SECOND = 'S',
    UNIT_TIME_END = 0xFF,
}fmc_unit_time_t;

// Typedef.

typedef struct
{
    uint32_t num;
    uint8_t res;
}fmc_fp_t;

typedef struct
{
    uint64_t pulse;
    fmc_fp_t volume;
    fmc_fp_t factor; // Factor en pulsos x unidad de volumen
    fmc_unit_volume_t unit_volume;
}fmc_totalizer_t;

typedef struct
{
    uint32_t delta_pulse;
    fmc_fp_t rate;
    fmc_fp_t factor; // Factor en pulsos x unidad de volumen
    fmc_unit_time_t unit_time;
    char str_time[2];
}fmc_rate_t;

// Function prototypes

fmc_totalizer_t fmc_totalizer_init(fmc_totalizer_t totalizer);
void fmc_totalizer_refresh(fmc_totalizer_t *p_totalizer);
void fmc_totalizer_clear_pulse(fmc_totalizer_t *totalizer);

#endif /* MODULE_H */

/*** end of file ***/
