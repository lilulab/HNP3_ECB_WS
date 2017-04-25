/*******************************************************************************
* File Name: MOT_RUN.h  
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

#if !defined(CY_PINS_MOT_RUN_H) /* Pins MOT_RUN_H */
#define CY_PINS_MOT_RUN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MOT_RUN_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MOT_RUN__PORT == 15 && ((MOT_RUN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MOT_RUN_Write(uint8 value);
void    MOT_RUN_SetDriveMode(uint8 mode);
uint8   MOT_RUN_ReadDataReg(void);
uint8   MOT_RUN_Read(void);
void    MOT_RUN_SetInterruptMode(uint16 position, uint16 mode);
uint8   MOT_RUN_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MOT_RUN_SetDriveMode() function.
     *  @{
     */
        #define MOT_RUN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MOT_RUN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MOT_RUN_DM_RES_UP          PIN_DM_RES_UP
        #define MOT_RUN_DM_RES_DWN         PIN_DM_RES_DWN
        #define MOT_RUN_DM_OD_LO           PIN_DM_OD_LO
        #define MOT_RUN_DM_OD_HI           PIN_DM_OD_HI
        #define MOT_RUN_DM_STRONG          PIN_DM_STRONG
        #define MOT_RUN_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MOT_RUN_MASK               MOT_RUN__MASK
#define MOT_RUN_SHIFT              MOT_RUN__SHIFT
#define MOT_RUN_WIDTH              1u

/* Interrupt constants */
#if defined(MOT_RUN__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MOT_RUN_SetInterruptMode() function.
     *  @{
     */
        #define MOT_RUN_INTR_NONE      (uint16)(0x0000u)
        #define MOT_RUN_INTR_RISING    (uint16)(0x0001u)
        #define MOT_RUN_INTR_FALLING   (uint16)(0x0002u)
        #define MOT_RUN_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MOT_RUN_INTR_MASK      (0x01u) 
#endif /* (MOT_RUN__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MOT_RUN_PS                     (* (reg8 *) MOT_RUN__PS)
/* Data Register */
#define MOT_RUN_DR                     (* (reg8 *) MOT_RUN__DR)
/* Port Number */
#define MOT_RUN_PRT_NUM                (* (reg8 *) MOT_RUN__PRT) 
/* Connect to Analog Globals */                                                  
#define MOT_RUN_AG                     (* (reg8 *) MOT_RUN__AG)                       
/* Analog MUX bux enable */
#define MOT_RUN_AMUX                   (* (reg8 *) MOT_RUN__AMUX) 
/* Bidirectional Enable */                                                        
#define MOT_RUN_BIE                    (* (reg8 *) MOT_RUN__BIE)
/* Bit-mask for Aliased Register Access */
#define MOT_RUN_BIT_MASK               (* (reg8 *) MOT_RUN__BIT_MASK)
/* Bypass Enable */
#define MOT_RUN_BYP                    (* (reg8 *) MOT_RUN__BYP)
/* Port wide control signals */                                                   
#define MOT_RUN_CTL                    (* (reg8 *) MOT_RUN__CTL)
/* Drive Modes */
#define MOT_RUN_DM0                    (* (reg8 *) MOT_RUN__DM0) 
#define MOT_RUN_DM1                    (* (reg8 *) MOT_RUN__DM1)
#define MOT_RUN_DM2                    (* (reg8 *) MOT_RUN__DM2) 
/* Input Buffer Disable Override */
#define MOT_RUN_INP_DIS                (* (reg8 *) MOT_RUN__INP_DIS)
/* LCD Common or Segment Drive */
#define MOT_RUN_LCD_COM_SEG            (* (reg8 *) MOT_RUN__LCD_COM_SEG)
/* Enable Segment LCD */
#define MOT_RUN_LCD_EN                 (* (reg8 *) MOT_RUN__LCD_EN)
/* Slew Rate Control */
#define MOT_RUN_SLW                    (* (reg8 *) MOT_RUN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MOT_RUN_PRTDSI__CAPS_SEL       (* (reg8 *) MOT_RUN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MOT_RUN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MOT_RUN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MOT_RUN_PRTDSI__OE_SEL0        (* (reg8 *) MOT_RUN__PRTDSI__OE_SEL0) 
#define MOT_RUN_PRTDSI__OE_SEL1        (* (reg8 *) MOT_RUN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MOT_RUN_PRTDSI__OUT_SEL0       (* (reg8 *) MOT_RUN__PRTDSI__OUT_SEL0) 
#define MOT_RUN_PRTDSI__OUT_SEL1       (* (reg8 *) MOT_RUN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MOT_RUN_PRTDSI__SYNC_OUT       (* (reg8 *) MOT_RUN__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MOT_RUN__SIO_CFG)
    #define MOT_RUN_SIO_HYST_EN        (* (reg8 *) MOT_RUN__SIO_HYST_EN)
    #define MOT_RUN_SIO_REG_HIFREQ     (* (reg8 *) MOT_RUN__SIO_REG_HIFREQ)
    #define MOT_RUN_SIO_CFG            (* (reg8 *) MOT_RUN__SIO_CFG)
    #define MOT_RUN_SIO_DIFF           (* (reg8 *) MOT_RUN__SIO_DIFF)
#endif /* (MOT_RUN__SIO_CFG) */

/* Interrupt Registers */
#if defined(MOT_RUN__INTSTAT)
    #define MOT_RUN_INTSTAT            (* (reg8 *) MOT_RUN__INTSTAT)
    #define MOT_RUN_SNAP               (* (reg8 *) MOT_RUN__SNAP)
    
	#define MOT_RUN_0_INTTYPE_REG 		(* (reg8 *) MOT_RUN__0__INTTYPE)
#endif /* (MOT_RUN__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MOT_RUN_H */


/* [] END OF FILE */
