/*******************************************************************************
* File Name: MOT_CW.h  
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

#if !defined(CY_PINS_MOT_CW_H) /* Pins MOT_CW_H */
#define CY_PINS_MOT_CW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MOT_CW_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MOT_CW__PORT == 15 && ((MOT_CW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MOT_CW_Write(uint8 value);
void    MOT_CW_SetDriveMode(uint8 mode);
uint8   MOT_CW_ReadDataReg(void);
uint8   MOT_CW_Read(void);
void    MOT_CW_SetInterruptMode(uint16 position, uint16 mode);
uint8   MOT_CW_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MOT_CW_SetDriveMode() function.
     *  @{
     */
        #define MOT_CW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MOT_CW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MOT_CW_DM_RES_UP          PIN_DM_RES_UP
        #define MOT_CW_DM_RES_DWN         PIN_DM_RES_DWN
        #define MOT_CW_DM_OD_LO           PIN_DM_OD_LO
        #define MOT_CW_DM_OD_HI           PIN_DM_OD_HI
        #define MOT_CW_DM_STRONG          PIN_DM_STRONG
        #define MOT_CW_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MOT_CW_MASK               MOT_CW__MASK
#define MOT_CW_SHIFT              MOT_CW__SHIFT
#define MOT_CW_WIDTH              1u

/* Interrupt constants */
#if defined(MOT_CW__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MOT_CW_SetInterruptMode() function.
     *  @{
     */
        #define MOT_CW_INTR_NONE      (uint16)(0x0000u)
        #define MOT_CW_INTR_RISING    (uint16)(0x0001u)
        #define MOT_CW_INTR_FALLING   (uint16)(0x0002u)
        #define MOT_CW_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MOT_CW_INTR_MASK      (0x01u) 
#endif /* (MOT_CW__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MOT_CW_PS                     (* (reg8 *) MOT_CW__PS)
/* Data Register */
#define MOT_CW_DR                     (* (reg8 *) MOT_CW__DR)
/* Port Number */
#define MOT_CW_PRT_NUM                (* (reg8 *) MOT_CW__PRT) 
/* Connect to Analog Globals */                                                  
#define MOT_CW_AG                     (* (reg8 *) MOT_CW__AG)                       
/* Analog MUX bux enable */
#define MOT_CW_AMUX                   (* (reg8 *) MOT_CW__AMUX) 
/* Bidirectional Enable */                                                        
#define MOT_CW_BIE                    (* (reg8 *) MOT_CW__BIE)
/* Bit-mask for Aliased Register Access */
#define MOT_CW_BIT_MASK               (* (reg8 *) MOT_CW__BIT_MASK)
/* Bypass Enable */
#define MOT_CW_BYP                    (* (reg8 *) MOT_CW__BYP)
/* Port wide control signals */                                                   
#define MOT_CW_CTL                    (* (reg8 *) MOT_CW__CTL)
/* Drive Modes */
#define MOT_CW_DM0                    (* (reg8 *) MOT_CW__DM0) 
#define MOT_CW_DM1                    (* (reg8 *) MOT_CW__DM1)
#define MOT_CW_DM2                    (* (reg8 *) MOT_CW__DM2) 
/* Input Buffer Disable Override */
#define MOT_CW_INP_DIS                (* (reg8 *) MOT_CW__INP_DIS)
/* LCD Common or Segment Drive */
#define MOT_CW_LCD_COM_SEG            (* (reg8 *) MOT_CW__LCD_COM_SEG)
/* Enable Segment LCD */
#define MOT_CW_LCD_EN                 (* (reg8 *) MOT_CW__LCD_EN)
/* Slew Rate Control */
#define MOT_CW_SLW                    (* (reg8 *) MOT_CW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MOT_CW_PRTDSI__CAPS_SEL       (* (reg8 *) MOT_CW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MOT_CW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MOT_CW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MOT_CW_PRTDSI__OE_SEL0        (* (reg8 *) MOT_CW__PRTDSI__OE_SEL0) 
#define MOT_CW_PRTDSI__OE_SEL1        (* (reg8 *) MOT_CW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MOT_CW_PRTDSI__OUT_SEL0       (* (reg8 *) MOT_CW__PRTDSI__OUT_SEL0) 
#define MOT_CW_PRTDSI__OUT_SEL1       (* (reg8 *) MOT_CW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MOT_CW_PRTDSI__SYNC_OUT       (* (reg8 *) MOT_CW__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MOT_CW__SIO_CFG)
    #define MOT_CW_SIO_HYST_EN        (* (reg8 *) MOT_CW__SIO_HYST_EN)
    #define MOT_CW_SIO_REG_HIFREQ     (* (reg8 *) MOT_CW__SIO_REG_HIFREQ)
    #define MOT_CW_SIO_CFG            (* (reg8 *) MOT_CW__SIO_CFG)
    #define MOT_CW_SIO_DIFF           (* (reg8 *) MOT_CW__SIO_DIFF)
#endif /* (MOT_CW__SIO_CFG) */

/* Interrupt Registers */
#if defined(MOT_CW__INTSTAT)
    #define MOT_CW_INTSTAT            (* (reg8 *) MOT_CW__INTSTAT)
    #define MOT_CW_SNAP               (* (reg8 *) MOT_CW__SNAP)
    
	#define MOT_CW_0_INTTYPE_REG 		(* (reg8 *) MOT_CW__0__INTTYPE)
#endif /* (MOT_CW__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MOT_CW_H */


/* [] END OF FILE */
