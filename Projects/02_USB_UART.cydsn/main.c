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
#include <stdio.h>  /* sprintf */
#include <stdlib.h> /* atoi */

uint8 Count;
uint8 Buffer[128];
char8 str[80];
char * pch;
int led_value[3];
uint8 data_count;


int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    USBUART_1_Start(0, USBUART_1_3V_OPERATION);//!!NOTE!! Make sure this matches your board voltage!
    while(!USBUART_1_bGetConfiguration());
    USBUART_1_CDC_Init();
    PWM_LED_Start();
    
    for(;;)
    {
        /* Place your application code here. */
        //Count = USBUART_1_bGetRxCount(); //OLD API
        Count = USBUART_1_GetCount();
        if(Count != 0) /* Check for input data from PC */
        {
        	//USBUART_1_ReadAll(Buffer); //OLD API
            USBUART_1_GetAll(Buffer);
        	//USBUART_1_Write(Buffer, Count); /* Echo data back to PC */ //OLD API
            USBUART_1_PutData(Buffer, Count);
        	//while(!USBUART_1_bTxIsReady()){} /* Wait for Tx to finish */ //OLD API
            while(!USBUART_1_CDCIsReady()){}
            
            memset(str,0,strlen(str));
            sprintf(str, ", Count = %u \r\n", Count);
            USBUART_1_PutString(str);
            
            data_count = 0;
            led_value[0] = 0;
            led_value[1] = 0;
            pch = NULL;
            pch = strtok ((char *)Buffer," ,.-");
             
            while (pch != NULL)
            {
            led_value[data_count] = atoi (pch);

            // memset(str,0,strlen(str));
            // sprintf(str,"Str [%d] = %s\n",data_count, pch);
            // USBUART_1_PutString(str);
            // sprintf(str,"Data[%d] = %d\n",data_count, led_value[data_count]);
            // USBUART_1_PutString(str);

            pch = strtok (NULL, " ,.-");
            data_count++;
            }
            
            memset(str,0,strlen(str));
            sprintf(str,"data_count = %d\n",data_count);
            USBUART_1_PutString(str);
            
            if(data_count == 2){
                PWM_LED_WriteCompare1((uint8)led_value[0]);
                PWM_LED_WriteCompare2((uint8)led_value[1]);
                
                memset(str,0,strlen(str));
                sprintf(str,"SET LEF = [%d,%d].\n",PWM_LED_ReadCompare1(), PWM_LED_ReadCompare2());
                USBUART_1_PutString(str);
            } //end if
        } // end if
    } // end for
} // end main

/* [] END OF FILE */
