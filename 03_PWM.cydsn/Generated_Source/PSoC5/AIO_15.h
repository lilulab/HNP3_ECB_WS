/*******************************************************************************
* File Name: AIO_15.h  
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

#if !defined(CY_PINS_AIO_15_H) /* Pins AIO_15_H */
#define CY_PINS_AIO_15_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AIO_15_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AIO_15__PORT == 15 && ((AIO_15__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AIO_15_Write(uint8 value);
void    AIO_15_SetDriveMode(uint8 mode);
uint8   AIO_15_ReadDataReg(void);
uint8   AIO_15_Read(void);
void    AIO_15_SetInterruptMode(uint16 position, uint16 mode);
uint8   AIO_15_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AIO_15_SetDriveMode() function.
     *  @{
     */
        #define AIO_15_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define AIO_15_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define AIO_15_DM_RES_UP          PIN_DM_RES_UP
        #define AIO_15_DM_RES_DWN         PIN_DM_RES_DWN
        #define AIO_15_DM_OD_LO           PIN_DM_OD_LO
        #define AIO_15_DM_OD_HI           PIN_DM_OD_HI
        #define AIO_15_DM_STRONG          PIN_DM_STRONG
        #define AIO_15_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AIO_15_MASK               AIO_15__MASK
#define AIO_15_SHIFT              AIO_15__SHIFT
#define AIO_15_WIDTH              1u

/* Interrupt constants */
#if defined(AIO_15__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AIO_15_SetInterruptMode() function.
     *  @{
     */
        #define AIO_15_INTR_NONE      (uint16)(0x0000u)
        #define AIO_15_INTR_RISING    (uint16)(0x0001u)
        #define AIO_15_INTR_FALLING   (uint16)(0x0002u)
        #define AIO_15_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define AIO_15_INTR_MASK      (0x01u) 
#endif /* (AIO_15__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AIO_15_PS                     (* (reg8 *) AIO_15__PS)
/* Data Register */
#define AIO_15_DR                     (* (reg8 *) AIO_15__DR)
/* Port Number */
#define AIO_15_PRT_NUM                (* (reg8 *) AIO_15__PRT) 
/* Connect to Analog Globals */                                                  
#define AIO_15_AG                     (* (reg8 *) AIO_15__AG)                       
/* Analog MUX bux enable */
#define AIO_15_AMUX                   (* (reg8 *) AIO_15__AMUX) 
/* Bidirectional Enable */                                                        
#define AIO_15_BIE                    (* (reg8 *) AIO_15__BIE)
/* Bit-mask for Aliased Register Access */
#define AIO_15_BIT_MASK               (* (reg8 *) AIO_15__BIT_MASK)
/* Bypass Enable */
#define AIO_15_BYP                    (* (reg8 *) AIO_15__BYP)
/* Port wide control signals */                                                   
#define AIO_15_CTL                    (* (reg8 *) AIO_15__CTL)
/* Drive Modes */
#define AIO_15_DM0                    (* (reg8 *) AIO_15__DM0) 
#define AIO_15_DM1                    (* (reg8 *) AIO_15__DM1)
#define AIO_15_DM2                    (* (reg8 *) AIO_15__DM2) 
/* Input Buffer Disable Override */
#define AIO_15_INP_DIS                (* (reg8 *) AIO_15__INP_DIS)
/* LCD Common or Segment Drive */
#define AIO_15_LCD_COM_SEG            (* (reg8 *) AIO_15__LCD_COM_SEG)
/* Enable Segment LCD */
#define AIO_15_LCD_EN                 (* (reg8 *) AIO_15__LCD_EN)
/* Slew Rate Control */
#define AIO_15_SLW                    (* (reg8 *) AIO_15__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AIO_15_PRTDSI__CAPS_SEL       (* (reg8 *) AIO_15__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AIO_15_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AIO_15__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AIO_15_PRTDSI__OE_SEL0        (* (reg8 *) AIO_15__PRTDSI__OE_SEL0) 
#define AIO_15_PRTDSI__OE_SEL1        (* (reg8 *) AIO_15__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AIO_15_PRTDSI__OUT_SEL0       (* (reg8 *) AIO_15__PRTDSI__OUT_SEL0) 
#define AIO_15_PRTDSI__OUT_SEL1       (* (reg8 *) AIO_15__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AIO_15_PRTDSI__SYNC_OUT       (* (reg8 *) AIO_15__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(AIO_15__SIO_CFG)
    #define AIO_15_SIO_HYST_EN        (* (reg8 *) AIO_15__SIO_HYST_EN)
    #define AIO_15_SIO_REG_HIFREQ     (* (reg8 *) AIO_15__SIO_REG_HIFREQ)
    #define AIO_15_SIO_CFG            (* (reg8 *) AIO_15__SIO_CFG)
    #define AIO_15_SIO_DIFF           (* (reg8 *) AIO_15__SIO_DIFF)
#endif /* (AIO_15__SIO_CFG) */

/* Interrupt Registers */
#if defined(AIO_15__INTSTAT)
    #define AIO_15_INTSTAT            (* (reg8 *) AIO_15__INTSTAT)
    #define AIO_15_SNAP               (* (reg8 *) AIO_15__SNAP)
    
	#define AIO_15_0_INTTYPE_REG 		(* (reg8 *) AIO_15__0__INTTYPE)
#endif /* (AIO_15__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AIO_15_H */


/* [] END OF FILE */
