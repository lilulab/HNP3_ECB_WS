/*******************************************************************************
* File Name: project.h
* 
* PSoC Creator  4.0
*
* Description:
* It contains references to all generated header files and should not be modified.
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2016 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cyfitter_cfg.h"
#include "cydevice.h"
#include "cydevice_trm.h"
#include "CyScBoostClk.h"
#include "cyfitter.h"
#include "cydisabledsheets.h"
#include "LIO_6_aliases.h"
#include "LIO_6.h"
#include "LIO_5_aliases.h"
#include "LIO_5.h"
#include "AIO_0_aliases.h"
#include "AIO_0.h"
#include "AIO_1_aliases.h"
#include "AIO_1.h"
#include "AIO_2_aliases.h"
#include "AIO_2.h"
#include "AIO_3_aliases.h"
#include "AIO_3.h"
#include "AIO_8_aliases.h"
#include "AIO_8.h"
#include "AIO_9_aliases.h"
#include "AIO_9.h"
#include "AIO_10_aliases.h"
#include "AIO_10.h"
#include "AIO_11_aliases.h"
#include "AIO_11.h"
#include "AIO_12_aliases.h"
#include "AIO_12.h"
#include "AIO_13_aliases.h"
#include "AIO_13.h"
#include "AIO_14_aliases.h"
#include "AIO_14.h"
#include "AIO_15_aliases.h"
#include "AIO_15.h"
#include "AIO_7_aliases.h"
#include "AIO_7.h"
#include "AIO_6_aliases.h"
#include "AIO_6.h"
#include "AIO_5_aliases.h"
#include "AIO_5.h"
#include "AIO_4_aliases.h"
#include "AIO_4.h"
#include "DIO_0_aliases.h"
#include "DIO_0.h"
#include "DIO_1_aliases.h"
#include "DIO_1.h"
#include "DIO_2_aliases.h"
#include "DIO_2.h"
#include "DIO_3_aliases.h"
#include "DIO_3.h"
#include "DIO_4_aliases.h"
#include "DIO_4.h"
#include "DIO_5_aliases.h"
#include "DIO_5.h"
#include "DIO_6_aliases.h"
#include "DIO_6.h"
#include "DIO_7_aliases.h"
#include "DIO_7.h"
#include "DIO_8_aliases.h"
#include "DIO_8.h"
#include "DIO_9_aliases.h"
#include "DIO_9.h"
#include "DIO_10_aliases.h"
#include "DIO_10.h"
#include "DIO_11_aliases.h"
#include "DIO_11.h"
#include "DIO_12_aliases.h"
#include "DIO_12.h"
#include "DIO_13_aliases.h"
#include "DIO_13.h"
#include "DIO_14_aliases.h"
#include "DIO_14.h"
#include "DIO_15_aliases.h"
#include "DIO_15.h"
#include "SAIO_0_aliases.h"
#include "SAIO_0.h"
#include "SAIO_1_aliases.h"
#include "SAIO_1.h"
#include "SDIO_0_aliases.h"
#include "SDIO_0.h"
#include "MODX_3_IO_aliases.h"
#include "MODX_3_IO.h"
#include "SDIO_1_aliases.h"
#include "SDIO_1.h"
#include "LED_G_aliases.h"
#include "LED_G.h"
#include "LED_B_aliases.h"
#include "LED_B.h"
#include "KEY_1_aliases.h"
#include "KEY_1.h"
#include "KEY_2_aliases.h"
#include "KEY_2.h"
#include "USBUART_1.h"
#include "USBUART_1_audio.h"
#include "USBUART_1_cdc.h"
#include "USBUART_1_hid.h"
#include "USBUART_1_midi.h"
#include "USBUART_1_pvt.h"
#include "USBUART_1_cydmac.h"
#include "USBUART_1_msc.h"
#include "BUZZER_aliases.h"
#include "BUZZER.h"
#include "CAN_1.h"
#include "CAN_TX_aliases.h"
#include "CAN_TX.h"
#include "CAN_RX_aliases.h"
#include "CAN_RX.h"
#include "UART_MODX_1.h"
#include "UART_MODX_0.h"
#include "UART_MODX_2.h"
#include "UART_STIM_0.h"
#include "UART_STIM_1.h"
#include "MODX_1_IO_aliases.h"
#include "MODX_1_IO.h"
#include "MODX_2_IO_aliases.h"
#include "MODX_2_IO.h"
#include "Clock_1.h"
#include "PWM_LED.h"
#include "Clock_2.h"
#include "LIO_4_aliases.h"
#include "LIO_4.h"
#include "LIO_3_aliases.h"
#include "LIO_3.h"
#include "LIO_2_aliases.h"
#include "LIO_2.h"
#include "LIO_0_aliases.h"
#include "LIO_0.h"
#include "LIO_7_aliases.h"
#include "LIO_7.h"
#include "LIO_8_aliases.h"
#include "LIO_8.h"
#include "LIO_9_aliases.h"
#include "LIO_9.h"
#include "LIO_10_aliases.h"
#include "LIO_10.h"
#include "LIO_11_aliases.h"
#include "LIO_11.h"
#include "LIO_12_aliases.h"
#include "LIO_12.h"
#include "LIO_13_RST_aliases.h"
#include "LIO_13_RST.h"
#include "LIO_1_aliases.h"
#include "LIO_1.h"
#include "LED_R_aliases.h"
#include "LED_R.h"
#include "USBUART_1_Dm_aliases.h"
#include "USBUART_1_Dm.h"
#include "USBUART_1_Dp_aliases.h"
#include "USBUART_1_Dp.h"
#include "core_cm3_psoc5.h"
#include "CyDmac.h"
#include "CyFlash.h"
#include "CyLib.h"
#include "cypins.h"
#include "cyPm.h"
#include "CySpc.h"
#include "cytypes.h"

/*[]*/

