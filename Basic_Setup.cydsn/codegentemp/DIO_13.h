/*******************************************************************************
* File Name: DIO_13.h  
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

#if !defined(CY_PINS_DIO_13_H) /* Pins DIO_13_H */
#define CY_PINS_DIO_13_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DIO_13_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DIO_13__PORT == 15 && ((DIO_13__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DIO_13_Write(uint8 value);
void    DIO_13_SetDriveMode(uint8 mode);
uint8   DIO_13_ReadDataReg(void);
uint8   DIO_13_Read(void);
void    DIO_13_SetInterruptMode(uint16 position, uint16 mode);
uint8   DIO_13_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DIO_13_SetDriveMode() function.
     *  @{
     */
        #define DIO_13_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DIO_13_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DIO_13_DM_RES_UP          PIN_DM_RES_UP
        #define DIO_13_DM_RES_DWN         PIN_DM_RES_DWN
        #define DIO_13_DM_OD_LO           PIN_DM_OD_LO
        #define DIO_13_DM_OD_HI           PIN_DM_OD_HI
        #define DIO_13_DM_STRONG          PIN_DM_STRONG
        #define DIO_13_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DIO_13_MASK               DIO_13__MASK
#define DIO_13_SHIFT              DIO_13__SHIFT
#define DIO_13_WIDTH              1u

/* Interrupt constants */
#if defined(DIO_13__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DIO_13_SetInterruptMode() function.
     *  @{
     */
        #define DIO_13_INTR_NONE      (uint16)(0x0000u)
        #define DIO_13_INTR_RISING    (uint16)(0x0001u)
        #define DIO_13_INTR_FALLING   (uint16)(0x0002u)
        #define DIO_13_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DIO_13_INTR_MASK      (0x01u) 
#endif /* (DIO_13__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DIO_13_PS                     (* (reg8 *) DIO_13__PS)
/* Data Register */
#define DIO_13_DR                     (* (reg8 *) DIO_13__DR)
/* Port Number */
#define DIO_13_PRT_NUM                (* (reg8 *) DIO_13__PRT) 
/* Connect to Analog Globals */                                                  
#define DIO_13_AG                     (* (reg8 *) DIO_13__AG)                       
/* Analog MUX bux enable */
#define DIO_13_AMUX                   (* (reg8 *) DIO_13__AMUX) 
/* Bidirectional Enable */                                                        
#define DIO_13_BIE                    (* (reg8 *) DIO_13__BIE)
/* Bit-mask for Aliased Register Access */
#define DIO_13_BIT_MASK               (* (reg8 *) DIO_13__BIT_MASK)
/* Bypass Enable */
#define DIO_13_BYP                    (* (reg8 *) DIO_13__BYP)
/* Port wide control signals */                                                   
#define DIO_13_CTL                    (* (reg8 *) DIO_13__CTL)
/* Drive Modes */
#define DIO_13_DM0                    (* (reg8 *) DIO_13__DM0) 
#define DIO_13_DM1                    (* (reg8 *) DIO_13__DM1)
#define DIO_13_DM2                    (* (reg8 *) DIO_13__DM2) 
/* Input Buffer Disable Override */
#define DIO_13_INP_DIS                (* (reg8 *) DIO_13__INP_DIS)
/* LCD Common or Segment Drive */
#define DIO_13_LCD_COM_SEG            (* (reg8 *) DIO_13__LCD_COM_SEG)
/* Enable Segment LCD */
#define DIO_13_LCD_EN                 (* (reg8 *) DIO_13__LCD_EN)
/* Slew Rate Control */
#define DIO_13_SLW                    (* (reg8 *) DIO_13__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DIO_13_PRTDSI__CAPS_SEL       (* (reg8 *) DIO_13__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DIO_13_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DIO_13__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DIO_13_PRTDSI__OE_SEL0        (* (reg8 *) DIO_13__PRTDSI__OE_SEL0) 
#define DIO_13_PRTDSI__OE_SEL1        (* (reg8 *) DIO_13__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DIO_13_PRTDSI__OUT_SEL0       (* (reg8 *) DIO_13__PRTDSI__OUT_SEL0) 
#define DIO_13_PRTDSI__OUT_SEL1       (* (reg8 *) DIO_13__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DIO_13_PRTDSI__SYNC_OUT       (* (reg8 *) DIO_13__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DIO_13__SIO_CFG)
    #define DIO_13_SIO_HYST_EN        (* (reg8 *) DIO_13__SIO_HYST_EN)
    #define DIO_13_SIO_REG_HIFREQ     (* (reg8 *) DIO_13__SIO_REG_HIFREQ)
    #define DIO_13_SIO_CFG            (* (reg8 *) DIO_13__SIO_CFG)
    #define DIO_13_SIO_DIFF           (* (reg8 *) DIO_13__SIO_DIFF)
#endif /* (DIO_13__SIO_CFG) */

/* Interrupt Registers */
#if defined(DIO_13__INTSTAT)
    #define DIO_13_INTSTAT            (* (reg8 *) DIO_13__INTSTAT)
    #define DIO_13_SNAP               (* (reg8 *) DIO_13__SNAP)
    
	#define DIO_13_0_INTTYPE_REG 		(* (reg8 *) DIO_13__0__INTTYPE)
#endif /* (DIO_13__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DIO_13_H */


/* [] END OF FILE */
