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

/* Switch state defines */
#define SWITCH_PRESSED         (0u)
#define SWITCH_RELEASED        (1u)

/* Switch debounce delay in milliseconds */
#define SWITCH_DEBOUNCE_UNIT   (1u)

/* Number of debounce units to count delay, before consider that switch is pressed */
#define SWITCH_DEBOUNCE_PERIOD (10u)

/* Function prototypes */
static uint32 ReadSw1Switch(void);

/* Global variables*/
uint8 Count;
uint8 Buffer[128];
char8 str[80];
char * pch;
int led_value[3];
uint8 data_count;

uint8 can_tx_status;

/* Global variable used to store switch state */
uint8 switchState = SWITCH_RELEASED;

/* Global variable used to store ISR flag */
volatile uint8 isrFlag = 0u;

int main()
{
    /* Enable global interrupts. */
    CyGlobalIntEnable; 
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    USBUART_1_Start(0, USBUART_1_3V_OPERATION);//!!NOTE!! Make sure this matches your board voltage!
    while(!USBUART_1_bGetConfiguration());
    USBUART_1_CDC_Init();
    VDAC8_1_Start();
    VDAC8_2_Start();
    DVDAC_1_Start();
    WaveDAC8_1_Start();
        
    for(;;)
    {
        /* Place your application code here. */
        
        // Try to input x,y in the serial terminal
        // x, y value are mapped to the LED pwm.
        // For example: 0,0 means both LED is off
        //              255,0 only turn on the red led at full brightness
        
        Count = USBUART_1_GetCount();
        
        /* Check for input data from PC */
        if(Count != 0) { 

            USBUART_1_GetAll(Buffer);
            USBUART_1_PutData(Buffer, Count);
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
                
                VDAC8_1_SetValue((uint8)led_value[0]);
                VDAC8_2_SetValue((uint8)led_value[1]);
                                
                // output result to USB-UART
                memset(str,0,strlen(str));
                sprintf(str,"SET LED = [%d,%d].\n \n",(uint8)led_value[0], (uint8)led_value[1]);
                
                USBUART_1_PutString(str);
            } //end if(Count != 0)
        } // end if (Count != 0)
        
                /* Change configuration at switch press or release event */
        if (switchState != ReadSw1Switch())    /* Switch state changed status */
        {
            switchState = ReadSw1Switch();    /* Store the current switch state */
            
            // output result to USB-UART
            memset(str,0,strlen(str));
            // sprintf(str,"SW1 = %d.\n \n",switchState);
            // USBUART_1_PutString(str);

            if (switchState == SWITCH_RELEASED)
            {
                sprintf(str,"SW1 = %d, pressed. \n",switchState);
                LED_B_Write(0u);
            }
            else
            {
                sprintf(str,"SW1 = %d, released. \n",switchState);
                LED_B_Write(1u);
            }
            
            /* Send USB-UART message with switch state */
            USBUART_1_PutString(str);
        } // end switchState
    } // end for(;;) loop
} // end main

/*******************************************************************************
* Function Name: ReadSw1Switch
********************************************************************************
* Summary:
*  Reads and returns the current status of the switch.
*
* Parameters:
*  None
*
* Return:
*  Returns a non-zero value, if switch is pressed, and a zero value otherwise.
*
*******************************************************************************/
static uint32 ReadSw1Switch(void)
{
    uint32 heldDown;
    uint32 swStatus;

    swStatus = 0u;  /* Switch is not active */
    heldDown = 0u;  /* Reset debounce counter */

    /* Wait for debounce period before determining whether the switch is pressed */
    while (KEY_1_Read() == SWITCH_PRESSED)
    {
        /* Count debounce period */
        CyDelay(SWITCH_DEBOUNCE_UNIT);
        ++heldDown;

        if (heldDown > SWITCH_DEBOUNCE_PERIOD)
        {
            swStatus = 1u; /* Switch is pressed */
            break;
        }
    }

    return (swStatus);
}

/* [] END OF FILE */
