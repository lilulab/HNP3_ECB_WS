/*******************************************************************************
* File Name: SDIO_0.h  
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

#if !defined(CY_PINS_SDIO_0_H) /* Pins SDIO_0_H */
#define CY_PINS_SDIO_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SDIO_0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SDIO_0__PORT == 15 && ((SDIO_0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SDIO_0_Write(uint8 value);
void    SDIO_0_SetDriveMode(uint8 mode);
uint8   SDIO_0_ReadDataReg(void);
uint8   SDIO_0_Read(void);
void    SDIO_0_SetInterruptMode(uint16 position, uint16 mode);
uint8   SDIO_0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SDIO_0_SetDriveMode() function.
     *  @{
     */
        #define SDIO_0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SDIO_0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SDIO_0_DM_RES_UP          PIN_DM_RES_UP
        #define SDIO_0_DM_RES_DWN         PIN_DM_RES_DWN
        #define SDIO_0_DM_OD_LO           PIN_DM_OD_LO
        #define SDIO_0_DM_OD_HI           PIN_DM_OD_HI
        #define SDIO_0_DM_STRONG          PIN_DM_STRONG
        #define SDIO_0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SDIO_0_MASK               SDIO_0__MASK
#define SDIO_0_SHIFT              SDIO_0__SHIFT
#define SDIO_0_WIDTH              1u

/* Interrupt constants */
#if defined(SDIO_0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SDIO_0_SetInterruptMode() function.
     *  @{
     */
        #define SDIO_0_INTR_NONE      (uint16)(0x0000u)
        #define SDIO_0_INTR_RISING    (uint16)(0x0001u)
        #define SDIO_0_INTR_FALLING   (uint16)(0x0002u)
        #define SDIO_0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SDIO_0_INTR_MASK      (0x01u) 
#endif /* (SDIO_0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SDIO_0_PS                     (* (reg8 *) SDIO_0__PS)
/* Data Register */
#define SDIO_0_DR                     (* (reg8 *) SDIO_0__DR)
/* Port Number */
#define SDIO_0_PRT_NUM                (* (reg8 *) SDIO_0__PRT) 
/* Connect to Analog Globals */                                                  
#define SDIO_0_AG                     (* (reg8 *) SDIO_0__AG)                       
/* Analog MUX bux enable */
#define SDIO_0_AMUX                   (* (reg8 *) SDIO_0__AMUX) 
/* Bidirectional Enable */                                                        
#define SDIO_0_BIE                    (* (reg8 *) SDIO_0__BIE)
/* Bit-mask for Aliased Register Access */
#define SDIO_0_BIT_MASK               (* (reg8 *) SDIO_0__BIT_MASK)
/* Bypass Enable */
#define SDIO_0_BYP                    (* (reg8 *) SDIO_0__BYP)
/* Port wide control signals */                                                   
#define SDIO_0_CTL                    (* (reg8 *) SDIO_0__CTL)
/* Drive Modes */
#define SDIO_0_DM0                    (* (reg8 *) SDIO_0__DM0) 
#define SDIO_0_DM1                    (* (reg8 *) SDIO_0__DM1)
#define SDIO_0_DM2                    (* (reg8 *) SDIO_0__DM2) 
/* Input Buffer Disable Override */
#define SDIO_0_INP_DIS                (* (reg8 *) SDIO_0__INP_DIS)
/* LCD Common or Segment Drive */
#define SDIO_0_LCD_COM_SEG            (* (reg8 *) SDIO_0__LCD_COM_SEG)
/* Enable Segment LCD */
#define SDIO_0_LCD_EN                 (* (reg8 *) SDIO_0__LCD_EN)
/* Slew Rate Control */
#define SDIO_0_SLW                    (* (reg8 *) SDIO_0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SDIO_0_PRTDSI__CAPS_SEL       (* (reg8 *) SDIO_0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SDIO_0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SDIO_0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SDIO_0_PRTDSI__OE_SEL0        (* (reg8 *) SDIO_0__PRTDSI__OE_SEL0) 
#define SDIO_0_PRTDSI__OE_SEL1        (* (reg8 *) SDIO_0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SDIO_0_PRTDSI__OUT_SEL0       (* (reg8 *) SDIO_0__PRTDSI__OUT_SEL0) 
#define SDIO_0_PRTDSI__OUT_SEL1       (* (reg8 *) SDIO_0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SDIO_0_PRTDSI__SYNC_OUT       (* (reg8 *) SDIO_0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SDIO_0__SIO_CFG)
    #define SDIO_0_SIO_HYST_EN        (* (reg8 *) SDIO_0__SIO_HYST_EN)
    #define SDIO_0_SIO_REG_HIFREQ     (* (reg8 *) SDIO_0__SIO_REG_HIFREQ)
    #define SDIO_0_SIO_CFG            (* (reg8 *) SDIO_0__SIO_CFG)
    #define SDIO_0_SIO_DIFF           (* (reg8 *) SDIO_0__SIO_DIFF)
#endif /* (SDIO_0__SIO_CFG) */

/* Interrupt Registers */
#if defined(SDIO_0__INTSTAT)
    #define SDIO_0_INTSTAT            (* (reg8 *) SDIO_0__INTSTAT)
    #define SDIO_0_SNAP               (* (reg8 *) SDIO_0__SNAP)
    
	#define SDIO_0_0_INTTYPE_REG 		(* (reg8 *) SDIO_0__0__INTTYPE)
#endif /* (SDIO_0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SDIO_0_H */


/* [] END OF FILE */
