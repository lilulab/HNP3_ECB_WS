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
#include <project.h>
//#include <device.h>

uint8 Count;
uint8 Buffer[128];


int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
//    USBUART_1_Start(0, USBUART_1_3V_OPERATION);//!!NOTE!! Make sure this matches your board voltage!
//    while(!USBUART_1_bGetConfiguration());
//    USBUART_1_CDC_Init();
    
    for(;;)
    {
        /* Place your application code here. */
        
        // Toggle Green LED
        LED_G_Write(~LED_G_Read());
                
//        Count = USBUART_1_GetCount();
//        if(Count != 0) /* Check for input data from PC */
//        {
//            USBUART_1_GetAll(Buffer);
//            USBUART_1_PutData(Buffer, Count); // Echo data back to PC
//            while(!USBUART_1_CDCIsReady()){} // Wait for Tx to finish
//        }
        
        // Delay 500ms
        CyDelay(500);

    }
}

/* [] END OF FILE */
