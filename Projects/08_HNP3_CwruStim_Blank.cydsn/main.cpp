/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "cwru_stim_psoc.hpp"

Stim stimBrd1(STIM_CHANNEL_UART0);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    stimBrd1.init(STIM_MODE_SURF);
    for(;;)
    {
        /* Place your application code here. */
    }
}


/* [] END OF FILE */
