/*******************************************************************************
* File Name: MODX_3_IO.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MODX_3_IO_H) /* Pins MODX_3_IO_H */
#define CY_PINS_MODX_3_IO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MODX_3_IO_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MODX_3_IO__PORT == 15 && ((MODX_3_IO__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MODX_3_IO_Write(uint8 value);
void    MODX_3_IO_SetDriveMode(uint8 mode);
uint8   MODX_3_IO_ReadDataReg(void);
uint8   MODX_3_IO_Read(void);
void    MODX_3_IO_SetInterruptMode(uint16 position, uint16 mode);
uint8   MODX_3_IO_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MODX_3_IO_SetDriveMode() function.
     *  @{
     */
        #define MODX_3_IO_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MODX_3_IO_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MODX_3_IO_DM_RES_UP          PIN_DM_RES_UP
        #define MODX_3_IO_DM_RES_DWN         PIN_DM_RES_DWN
        #define MODX_3_IO_DM_OD_LO           PIN_DM_OD_LO
        #define MODX_3_IO_DM_OD_HI           PIN_DM_OD_HI
        #define MODX_3_IO_DM_STRONG          PIN_DM_STRONG
        #define MODX_3_IO_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MODX_3_IO_MASK               MODX_3_IO__MASK
#define MODX_3_IO_SHIFT              MODX_3_IO__SHIFT
#define MODX_3_IO_WIDTH              1u

/* Interrupt constants */
#if defined(MODX_3_IO__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MODX_3_IO_SetInterruptMode() function.
     *  @{
     */
        #define MODX_3_IO_INTR_NONE      (uint16)(0x0000u)
        #define MODX_3_IO_INTR_RISING    (uint16)(0x0001u)
        #define MODX_3_IO_INTR_FALLING   (uint16)(0x0002u)
        #define MODX_3_IO_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MODX_3_IO_INTR_MASK      (0x01u) 
#endif /* (MODX_3_IO__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MODX_3_IO_PS                     (* (reg8 *) MODX_3_IO__PS)
/* Data Register */
#define MODX_3_IO_DR                     (* (reg8 *) MODX_3_IO__DR)
/* Port Number */
#define MODX_3_IO_PRT_NUM                (* (reg8 *) MODX_3_IO__PRT) 
/* Connect to Analog Globals */                                                  
#define MODX_3_IO_AG                     (* (reg8 *) MODX_3_IO__AG)                       
/* Analog MUX bux enable */
#define MODX_3_IO_AMUX                   (* (reg8 *) MODX_3_IO__AMUX) 
/* Bidirectional Enable */                                                        
#define MODX_3_IO_BIE                    (* (reg8 *) MODX_3_IO__BIE)
/* Bit-mask for Aliased Register Access */
#define MODX_3_IO_BIT_MASK               (* (reg8 *) MODX_3_IO__BIT_MASK)
/* Bypass Enable */
#define MODX_3_IO_BYP                    (* (reg8 *) MODX_3_IO__BYP)
/* Port wide control signals */                                                   
#define MODX_3_IO_CTL                    (* (reg8 *) MODX_3_IO__CTL)
/* Drive Modes */
#define MODX_3_IO_DM0                    (* (reg8 *) MODX_3_IO__DM0) 
#define MODX_3_IO_DM1                    (* (reg8 *) MODX_3_IO__DM1)
#define MODX_3_IO_DM2                    (* (reg8 *) MODX_3_IO__DM2) 
/* Input Buffer Disable Override */
#define MODX_3_IO_INP_DIS                (* (reg8 *) MODX_3_IO__INP_DIS)
/* LCD Common or Segment Drive */
#define MODX_3_IO_LCD_COM_SEG            (* (reg8 *) MODX_3_IO__LCD_COM_SEG)
/* Enable Segment LCD */
#define MODX_3_IO_LCD_EN                 (* (reg8 *) MODX_3_IO__LCD_EN)
/* Slew Rate Control */
#define MODX_3_IO_SLW                    (* (reg8 *) MODX_3_IO__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MODX_3_IO_PRTDSI__CAPS_SEL       (* (reg8 *) MODX_3_IO__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MODX_3_IO_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MODX_3_IO__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MODX_3_IO_PRTDSI__OE_SEL0        (* (reg8 *) MODX_3_IO__PRTDSI__OE_SEL0) 
#define MODX_3_IO_PRTDSI__OE_SEL1        (* (reg8 *) MODX_3_IO__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MODX_3_IO_PRTDSI__OUT_SEL0       (* (reg8 *) MODX_3_IO__PRTDSI__OUT_SEL0) 
#define MODX_3_IO_PRTDSI__OUT_SEL1       (* (reg8 *) MODX_3_IO__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MODX_3_IO_PRTDSI__SYNC_OUT       (* (reg8 *) MODX_3_IO__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MODX_3_IO__SIO_CFG)
    #define MODX_3_IO_SIO_HYST_EN        (* (reg8 *) MODX_3_IO__SIO_HYST_EN)
    #define MODX_3_IO_SIO_REG_HIFREQ     (* (reg8 *) MODX_3_IO__SIO_REG_HIFREQ)
    #define MODX_3_IO_SIO_CFG            (* (reg8 *) MODX_3_IO__SIO_CFG)
    #define MODX_3_IO_SIO_DIFF           (* (reg8 *) MODX_3_IO__SIO_DIFF)
#endif /* (MODX_3_IO__SIO_CFG) */

/* Interrupt Registers */
#if defined(MODX_3_IO__INTSTAT)
    #define MODX_3_IO_INTSTAT            (* (reg8 *) MODX_3_IO__INTSTAT)
    #define MODX_3_IO_SNAP               (* (reg8 *) MODX_3_IO__SNAP)
    
	#define MODX_3_IO_0_INTTYPE_REG 		(* (reg8 *) MODX_3_IO__0__INTTYPE)
#endif /* (MODX_3_IO__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MODX_3_IO_H */


/* [] END OF FILE */
