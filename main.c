#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fmc.h"
#include "lcd.h"
#include "fm_factory.h"



int main()
{
    char buffer[LINE_BUFFER_SIZE];

    fmc_totalizer_t acm;
    fmc_totalizer_t ttl;
    fmc_rate_t rate;

    acm = fm_factory_get_acm(acm);
    acm = fmc_totalizer_init(acm);

    fm_lcd_u32_to_str(acm.volume.num, '0', LINE_1_DIGITS, buffer, sizeof(buffer));
    printf("ACM = %s\n", buffer);

    fm_lcd_fp_add_dot(acm.volume, buffer, sizeof(buffer));
    printf("ACM = %s\n", buffer);

    acm.pulse += 100;
    fmc_totalizer_refresh(&acm);

    fm_lcd_u32_to_str(acm.volume.num, '0', LINE_1_DIGITS, buffer, sizeof(buffer));
    fm_lcd_fp_add_dot(acm.volume, buffer, sizeof(buffer));
    printf("ACM = %s\n", buffer);


    fmc_totalizer_clear_pulse(&acm);

    fm_lcd_u32_to_str(acm.volume.num, '0', LINE_1_DIGITS, buffer, sizeof(buffer));
    fm_lcd_fp_add_dot(acm.volume, buffer, sizeof(buffer));
    printf("ACM = %s\n", buffer);




    return 0;
}

