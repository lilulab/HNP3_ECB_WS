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
uint8 led_pwm_value[2] = {0,0};

uint16 sweep_counter = 0;
int16 sweep_dir = 0;
#define SWEEP_MIN 0
#define SWEEP_MAX 255
#define SWEEP_STEP 1


void run_sweep(void);

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
//    USBUART_1_Start(0, USBUART_1_3V_OPERATION);//!!NOTE!! Make sure this matches your board voltage!
//    while(!USBUART_1_bGetConfiguration());
//    USBUART_1_CDC_Init();
    PWM_LED_Start();
    
    
    for(;;)
    {
        /* Place your application code here. */
        
        // Toggle Green LED
        //LED_G_Write(~LED_G_Read());
        
        // assign led pwm value
        led_pwm_value[0] = (uint8)sweep_counter;
        led_pwm_value[1] = 255 - (uint8)sweep_counter;
        
        
        PWM_LED_WriteCompare1(led_pwm_value[0]);
        PWM_LED_WriteCompare2(led_pwm_value[1]);
                
//        Count = USBUART_1_GetCount();
//        if(Count != 0) /* Check for input data from PC */
//        {
//            USBUART_1_GetAll(Buffer);
//            USBUART_1_PutData(Buffer, Count); // Echo data back to PC
//            while(!USBUART_1_CDCIsReady()){} // Wait for Tx to finish
//        }
        
        // run sweep function
        run_sweep();
        
        // Delay 5ms
        CyDelay(5);

    }
}

void run_sweep(void){
    if (sweep_counter <= SWEEP_MIN){
        sweep_dir = SWEEP_STEP;
        sweep_counter = SWEEP_MIN;
    }
    if (sweep_counter >= SWEEP_MAX){
        sweep_dir = -SWEEP_STEP;
        sweep_counter = SWEEP_MAX;
    }
    sweep_counter = sweep_counter + sweep_dir;
}

/* [] END OF FILE */
