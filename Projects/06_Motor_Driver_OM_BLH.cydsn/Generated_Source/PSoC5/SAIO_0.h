/*******************************************************************************
* File Name: SAIO_0.h  
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

#if !defined(CY_PINS_SAIO_0_H) /* Pins SAIO_0_H */
#define CY_PINS_SAIO_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SAIO_0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SAIO_0__PORT == 15 && ((SAIO_0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SAIO_0_Write(uint8 value);
void    SAIO_0_SetDriveMode(uint8 mode);
uint8   SAIO_0_ReadDataReg(void);
uint8   SAIO_0_Read(void);
void    SAIO_0_SetInterruptMode(uint16 position, uint16 mode);
uint8   SAIO_0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SAIO_0_SetDriveMode() function.
     *  @{
     */
        #define SAIO_0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SAIO_0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SAIO_0_DM_RES_UP          PIN_DM_RES_UP
        #define SAIO_0_DM_RES_DWN         PIN_DM_RES_DWN
        #define SAIO_0_DM_OD_LO           PIN_DM_OD_LO
        #define SAIO_0_DM_OD_HI           PIN_DM_OD_HI
        #define SAIO_0_DM_STRONG          PIN_DM_STRONG
        #define SAIO_0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SAIO_0_MASK               SAIO_0__MASK
#define SAIO_0_SHIFT              SAIO_0__SHIFT
#define SAIO_0_WIDTH              1u

/* Interrupt constants */
#if defined(SAIO_0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SAIO_0_SetInterruptMode() function.
     *  @{
     */
        #define SAIO_0_INTR_NONE      (uint16)(0x0000u)
        #define SAIO_0_INTR_RISING    (uint16)(0x0001u)
        #define SAIO_0_INTR_FALLING   (uint16)(0x0002u)
        #define SAIO_0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SAIO_0_INTR_MASK      (0x01u) 
#endif /* (SAIO_0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SAIO_0_PS                     (* (reg8 *) SAIO_0__PS)
/* Data Register */
#define SAIO_0_DR                     (* (reg8 *) SAIO_0__DR)
/* Port Number */
#define SAIO_0_PRT_NUM                (* (reg8 *) SAIO_0__PRT) 
/* Connect to Analog Globals */                                                  
#define SAIO_0_AG                     (* (reg8 *) SAIO_0__AG)                       
/* Analog MUX bux enable */
#define SAIO_0_AMUX                   (* (reg8 *) SAIO_0__AMUX) 
/* Bidirectional Enable */                                                        
#define SAIO_0_BIE                    (* (reg8 *) SAIO_0__BIE)
/* Bit-mask for Aliased Register Access */
#define SAIO_0_BIT_MASK               (* (reg8 *) SAIO_0__BIT_MASK)
/* Bypass Enable */
#define SAIO_0_BYP                    (* (reg8 *) SAIO_0__BYP)
/* Port wide control signals */                                                   
#define SAIO_0_CTL                    (* (reg8 *) SAIO_0__CTL)
/* Drive Modes */
#define SAIO_0_DM0                    (* (reg8 *) SAIO_0__DM0) 
#define SAIO_0_DM1                    (* (reg8 *) SAIO_0__DM1)
#define SAIO_0_DM2                    (* (reg8 *) SAIO_0__DM2) 
/* Input Buffer Disable Override */
#define SAIO_0_INP_DIS                (* (reg8 *) SAIO_0__INP_DIS)
/* LCD Common or Segment Drive */
#define SAIO_0_LCD_COM_SEG            (* (reg8 *) SAIO_0__LCD_COM_SEG)
/* Enable Segment LCD */
#define SAIO_0_LCD_EN                 (* (reg8 *) SAIO_0__LCD_EN)
/* Slew Rate Control */
#define SAIO_0_SLW                    (* (reg8 *) SAIO_0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SAIO_0_PRTDSI__CAPS_SEL       (* (reg8 *) SAIO_0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SAIO_0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SAIO_0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SAIO_0_PRTDSI__OE_SEL0        (* (reg8 *) SAIO_0__PRTDSI__OE_SEL0) 
#define SAIO_0_PRTDSI__OE_SEL1        (* (reg8 *) SAIO_0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SAIO_0_PRTDSI__OUT_SEL0       (* (reg8 *) SAIO_0__PRTDSI__OUT_SEL0) 
#define SAIO_0_PRTDSI__OUT_SEL1       (* (reg8 *) SAIO_0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SAIO_0_PRTDSI__SYNC_OUT       (* (reg8 *) SAIO_0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SAIO_0__SIO_CFG)
    #define SAIO_0_SIO_HYST_EN        (* (reg8 *) SAIO_0__SIO_HYST_EN)
    #define SAIO_0_SIO_REG_HIFREQ     (* (reg8 *) SAIO_0__SIO_REG_HIFREQ)
    #define SAIO_0_SIO_CFG            (* (reg8 *) SAIO_0__SIO_CFG)
    #define SAIO_0_SIO_DIFF           (* (reg8 *) SAIO_0__SIO_DIFF)
#endif /* (SAIO_0__SIO_CFG) */

/* Interrupt Registers */
#if defined(SAIO_0__INTSTAT)
    #define SAIO_0_INTSTAT            (* (reg8 *) SAIO_0__INTSTAT)
    #define SAIO_0_SNAP               (* (reg8 *) SAIO_0__SNAP)
    
	#define SAIO_0_0_INTTYPE_REG 		(* (reg8 *) SAIO_0__0__INTTYPE)
#endif /* (SAIO_0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SAIO_0_H */


/* [] END OF FILE */
