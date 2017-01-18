/*******************************************************************************
* File Name: LIO_12.h  
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

#if !defined(CY_PINS_LIO_12_H) /* Pins LIO_12_H */
#define CY_PINS_LIO_12_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LIO_12_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LIO_12__PORT == 15 && ((LIO_12__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LIO_12_Write(uint8 value);
void    LIO_12_SetDriveMode(uint8 mode);
uint8   LIO_12_ReadDataReg(void);
uint8   LIO_12_Read(void);
void    LIO_12_SetInterruptMode(uint16 position, uint16 mode);
uint8   LIO_12_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LIO_12_SetDriveMode() function.
     *  @{
     */
        #define LIO_12_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LIO_12_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LIO_12_DM_RES_UP          PIN_DM_RES_UP
        #define LIO_12_DM_RES_DWN         PIN_DM_RES_DWN
        #define LIO_12_DM_OD_LO           PIN_DM_OD_LO
        #define LIO_12_DM_OD_HI           PIN_DM_OD_HI
        #define LIO_12_DM_STRONG          PIN_DM_STRONG
        #define LIO_12_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LIO_12_MASK               LIO_12__MASK
#define LIO_12_SHIFT              LIO_12__SHIFT
#define LIO_12_WIDTH              1u

/* Interrupt constants */
#if defined(LIO_12__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LIO_12_SetInterruptMode() function.
     *  @{
     */
        #define LIO_12_INTR_NONE      (uint16)(0x0000u)
        #define LIO_12_INTR_RISING    (uint16)(0x0001u)
        #define LIO_12_INTR_FALLING   (uint16)(0x0002u)
        #define LIO_12_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LIO_12_INTR_MASK      (0x01u) 
#endif /* (LIO_12__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LIO_12_PS                     (* (reg8 *) LIO_12__PS)
/* Data Register */
#define LIO_12_DR                     (* (reg8 *) LIO_12__DR)
/* Port Number */
#define LIO_12_PRT_NUM                (* (reg8 *) LIO_12__PRT) 
/* Connect to Analog Globals */                                                  
#define LIO_12_AG                     (* (reg8 *) LIO_12__AG)                       
/* Analog MUX bux enable */
#define LIO_12_AMUX                   (* (reg8 *) LIO_12__AMUX) 
/* Bidirectional Enable */                                                        
#define LIO_12_BIE                    (* (reg8 *) LIO_12__BIE)
/* Bit-mask for Aliased Register Access */
#define LIO_12_BIT_MASK               (* (reg8 *) LIO_12__BIT_MASK)
/* Bypass Enable */
#define LIO_12_BYP                    (* (reg8 *) LIO_12__BYP)
/* Port wide control signals */                                                   
#define LIO_12_CTL                    (* (reg8 *) LIO_12__CTL)
/* Drive Modes */
#define LIO_12_DM0                    (* (reg8 *) LIO_12__DM0) 
#define LIO_12_DM1                    (* (reg8 *) LIO_12__DM1)
#define LIO_12_DM2                    (* (reg8 *) LIO_12__DM2) 
/* Input Buffer Disable Override */
#define LIO_12_INP_DIS                (* (reg8 *) LIO_12__INP_DIS)
/* LCD Common or Segment Drive */
#define LIO_12_LCD_COM_SEG            (* (reg8 *) LIO_12__LCD_COM_SEG)
/* Enable Segment LCD */
#define LIO_12_LCD_EN                 (* (reg8 *) LIO_12__LCD_EN)
/* Slew Rate Control */
#define LIO_12_SLW                    (* (reg8 *) LIO_12__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LIO_12_PRTDSI__CAPS_SEL       (* (reg8 *) LIO_12__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LIO_12_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LIO_12__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LIO_12_PRTDSI__OE_SEL0        (* (reg8 *) LIO_12__PRTDSI__OE_SEL0) 
#define LIO_12_PRTDSI__OE_SEL1        (* (reg8 *) LIO_12__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LIO_12_PRTDSI__OUT_SEL0       (* (reg8 *) LIO_12__PRTDSI__OUT_SEL0) 
#define LIO_12_PRTDSI__OUT_SEL1       (* (reg8 *) LIO_12__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LIO_12_PRTDSI__SYNC_OUT       (* (reg8 *) LIO_12__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LIO_12__SIO_CFG)
    #define LIO_12_SIO_HYST_EN        (* (reg8 *) LIO_12__SIO_HYST_EN)
    #define LIO_12_SIO_REG_HIFREQ     (* (reg8 *) LIO_12__SIO_REG_HIFREQ)
    #define LIO_12_SIO_CFG            (* (reg8 *) LIO_12__SIO_CFG)
    #define LIO_12_SIO_DIFF           (* (reg8 *) LIO_12__SIO_DIFF)
#endif /* (LIO_12__SIO_CFG) */

/* Interrupt Registers */
#if defined(LIO_12__INTSTAT)
    #define LIO_12_INTSTAT            (* (reg8 *) LIO_12__INTSTAT)
    #define LIO_12_SNAP               (* (reg8 *) LIO_12__SNAP)
    
	#define LIO_12_0_INTTYPE_REG 		(* (reg8 *) LIO_12__0__INTTYPE)
#endif /* (LIO_12__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LIO_12_H */


/* [] END OF FILE */
