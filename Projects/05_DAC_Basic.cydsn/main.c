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
CY_ISR_PROTO(ISR_CAN);

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
    PWM_LED_Start();
    CAN_Start();
    VDAC8_1_Start();
    VDAC8_2_Start();
    
    /* Set CAN interrupt handler to local routine */
    CyIntSetVector(CAN_ISR_NUMBER, ISR_CAN);
    
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
                // set LED pwm value
                PWM_LED_WriteCompare1((uint8)led_value[0]);
                PWM_LED_WriteCompare2((uint8)led_value[1]);
                
                VDAC8_1_SetValue((uint8)led_value[0]);
                VDAC8_2_SetValue((uint8)led_value[1]);
                                
                // output result to USB-UART
                memset(str,0,strlen(str));
                sprintf(str,"SET LED = [%d,%d].\n \n",
                                PWM_LED_ReadCompare1(), 
                                PWM_LED_ReadCompare2());
                
                USBUART_1_PutString(str);
            } //end if
        } // end if
        
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
                CAN_TX_DATA_BYTE1(CAN_TX_MAILBOX_M_SWITCH_STATUS) = SWITCH_PRESSED;
                sprintf(str,"SW1 = %d, pressed. \n",switchState);
            }
            else
            {
                CAN_TX_DATA_BYTE1(CAN_TX_MAILBOX_M_SWITCH_STATUS) = SWITCH_RELEASED;
                sprintf(str,"SW1 = %d, released. \n",switchState);
            }
            
            /* Send USB-UART message with switch state */
            USBUART_1_PutString(str);
            
            // new string for CAN states
            // memset(str,0,strlen(str));
            // sprintf(str,"SW1 = %d.\n \n",switchState);
            // USBUART_1_PutString(str);
            
            // send out switch status CAN messages
            CAN_TX_DATA_BYTE2(CAN_TX_MAILBOX_M_SWITCH_STATUS) = switchState;
            CAN_TX_DATA_BYTE3(CAN_TX_MAILBOX_M_SWITCH_STATUS) = 0u;
            CAN_TX_DATA_BYTE4(CAN_TX_MAILBOX_M_SWITCH_STATUS) = 0u;
            CAN_TX_DATA_BYTE5(CAN_TX_MAILBOX_M_SWITCH_STATUS) = 0u;
            CAN_TX_DATA_BYTE6(CAN_TX_MAILBOX_M_SWITCH_STATUS) = 0u;
            CAN_TX_DATA_BYTE7(CAN_TX_MAILBOX_M_SWITCH_STATUS) = 0u;
            CAN_TX_DATA_BYTE8(CAN_TX_MAILBOX_M_SWITCH_STATUS) = 0u;            

            /* Send CAN message with switch state */
            can_tx_status = CAN_SendMsgM_SWITCH_STATUS();
            
            // send USB-UART messages
            sprintf(str,"CAN_TX_MAILBOX_M_SWITCH_STATUS = %d; return flag is %d.\n", 
                switchState, 
                can_tx_status);
            USBUART_1_PutString(str);            
            
            // send out LED status CAN messages
            CAN_TX_DATA_BYTE1(CAN_TX_MAILBOX_M_LED_STATUS) = (uint8)led_value[0];
            CAN_TX_DATA_BYTE2(CAN_TX_MAILBOX_M_LED_STATUS) = (uint8)led_value[1];
            CAN_TX_DATA_BYTE3(CAN_TX_MAILBOX_M_LED_STATUS) = 0u;
            CAN_TX_DATA_BYTE4(CAN_TX_MAILBOX_M_LED_STATUS) = 0u;
            CAN_TX_DATA_BYTE5(CAN_TX_MAILBOX_M_LED_STATUS) = 0u;
            CAN_TX_DATA_BYTE6(CAN_TX_MAILBOX_M_LED_STATUS) = 0u;
            CAN_TX_DATA_BYTE7(CAN_TX_MAILBOX_M_LED_STATUS) = 0u;
            CAN_TX_DATA_BYTE8(CAN_TX_MAILBOX_M_LED_STATUS) = 0u;
            
            can_tx_status = CAN_SendMsgM_LED_STATUS();
            
            // send USB-UART messages
            sprintf(str,"CAN_TX_MAILBOX_M_LED_STATUS = %d,%d; return flag is %d.\n", 
                (uint8)led_value[0], 
                (uint8)led_value[1], 
                can_tx_status);
            USBUART_1_PutString(str); 
            
            
        } // end switchState
    } // end for(;;) loop
} // end main

/*******************************************************************************
* Function Name: ISR_CAN
********************************************************************************
*
* Summary:
*  This ISR is executed at a Receive Message event and set the isrFlag.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
CY_ISR(ISR_CAN)
{
    /* Clear Receive Message flag */
    CAN_INT_SR_REG.byte[1u] = CAN_RX_MESSAGE_MASK;

    /* Set the isrFlag */
    isrFlag = 1u;

    /* Acknowledges receipt of new message */
    CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_0);
    
    memset(str,0,strlen(str));
    sprintf(str,"Recive Message in CAN_RX_MAILBOX_0. \n \n");
    USBUART_1_PutString(str);
}


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
