/*******************************************************************************
* File Name: AIO_11.h  
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

#if !defined(CY_PINS_AIO_11_H) /* Pins AIO_11_H */
#define CY_PINS_AIO_11_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AIO_11_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AIO_11__PORT == 15 && ((AIO_11__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AIO_11_Write(uint8 value);
void    AIO_11_SetDriveMode(uint8 mode);
uint8   AIO_11_ReadDataReg(void);
uint8   AIO_11_Read(void);
void    AIO_11_SetInterruptMode(uint16 position, uint16 mode);
uint8   AIO_11_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AIO_11_SetDriveMode() function.
     *  @{
     */
        #define AIO_11_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define AIO_11_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define AIO_11_DM_RES_UP          PIN_DM_RES_UP
        #define AIO_11_DM_RES_DWN         PIN_DM_RES_DWN
        #define AIO_11_DM_OD_LO           PIN_DM_OD_LO
        #define AIO_11_DM_OD_HI           PIN_DM_OD_HI
        #define AIO_11_DM_STRONG          PIN_DM_STRONG
        #define AIO_11_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AIO_11_MASK               AIO_11__MASK
#define AIO_11_SHIFT              AIO_11__SHIFT
#define AIO_11_WIDTH              1u

/* Interrupt constants */
#if defined(AIO_11__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AIO_11_SetInterruptMode() function.
     *  @{
     */
        #define AIO_11_INTR_NONE      (uint16)(0x0000u)
        #define AIO_11_INTR_RISING    (uint16)(0x0001u)
        #define AIO_11_INTR_FALLING   (uint16)(0x0002u)
        #define AIO_11_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define AIO_11_INTR_MASK      (0x01u) 
#endif /* (AIO_11__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AIO_11_PS                     (* (reg8 *) AIO_11__PS)
/* Data Register */
#define AIO_11_DR                     (* (reg8 *) AIO_11__DR)
/* Port Number */
#define AIO_11_PRT_NUM                (* (reg8 *) AIO_11__PRT) 
/* Connect to Analog Globals */                                                  
#define AIO_11_AG                     (* (reg8 *) AIO_11__AG)                       
/* Analog MUX bux enable */
#define AIO_11_AMUX                   (* (reg8 *) AIO_11__AMUX) 
/* Bidirectional Enable */                                                        
#define AIO_11_BIE                    (* (reg8 *) AIO_11__BIE)
/* Bit-mask for Aliased Register Access */
#define AIO_11_BIT_MASK               (* (reg8 *) AIO_11__BIT_MASK)
/* Bypass Enable */
#define AIO_11_BYP                    (* (reg8 *) AIO_11__BYP)
/* Port wide control signals */                                                   
#define AIO_11_CTL                    (* (reg8 *) AIO_11__CTL)
/* Drive Modes */
#define AIO_11_DM0                    (* (reg8 *) AIO_11__DM0) 
#define AIO_11_DM1                    (* (reg8 *) AIO_11__DM1)
#define AIO_11_DM2                    (* (reg8 *) AIO_11__DM2) 
/* Input Buffer Disable Override */
#define AIO_11_INP_DIS                (* (reg8 *) AIO_11__INP_DIS)
/* LCD Common or Segment Drive */
#define AIO_11_LCD_COM_SEG            (* (reg8 *) AIO_11__LCD_COM_SEG)
/* Enable Segment LCD */
#define AIO_11_LCD_EN                 (* (reg8 *) AIO_11__LCD_EN)
/* Slew Rate Control */
#define AIO_11_SLW                    (* (reg8 *) AIO_11__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AIO_11_PRTDSI__CAPS_SEL       (* (reg8 *) AIO_11__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AIO_11_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AIO_11__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AIO_11_PRTDSI__OE_SEL0        (* (reg8 *) AIO_11__PRTDSI__OE_SEL0) 
#define AIO_11_PRTDSI__OE_SEL1        (* (reg8 *) AIO_11__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AIO_11_PRTDSI__OUT_SEL0       (* (reg8 *) AIO_11__PRTDSI__OUT_SEL0) 
#define AIO_11_PRTDSI__OUT_SEL1       (* (reg8 *) AIO_11__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AIO_11_PRTDSI__SYNC_OUT       (* (reg8 *) AIO_11__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(AIO_11__SIO_CFG)
    #define AIO_11_SIO_HYST_EN        (* (reg8 *) AIO_11__SIO_HYST_EN)
    #define AIO_11_SIO_REG_HIFREQ     (* (reg8 *) AIO_11__SIO_REG_HIFREQ)
    #define AIO_11_SIO_CFG            (* (reg8 *) AIO_11__SIO_CFG)
    #define AIO_11_SIO_DIFF           (* (reg8 *) AIO_11__SIO_DIFF)
#endif /* (AIO_11__SIO_CFG) */

/* Interrupt Registers */
#if defined(AIO_11__INTSTAT)
    #define AIO_11_INTSTAT            (* (reg8 *) AIO_11__INTSTAT)
    #define AIO_11_SNAP               (* (reg8 *) AIO_11__SNAP)
    
	#define AIO_11_0_INTTYPE_REG 		(* (reg8 *) AIO_11__0__INTTYPE)
#endif /* (AIO_11__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AIO_11_H */


/* [] END OF FILE */
