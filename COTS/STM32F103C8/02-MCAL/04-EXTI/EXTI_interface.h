/**
 * @brief This module contains functions for configuring and controlling the External Interrupt (EXTI) peripheral.
 *
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 02 Jul 2023
 * @version V01
 *
 * This module provides functions for configuring the interrupt source, trigger type, and enabling/disabling EXTI lines.
 * It also includes functions for clearing the EXTI pending flag and getting the interrupt status. It is designed to be
 * used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */
#ifndef __EXTI_INTERFACE_H__
#define __EXTI_INTERFACE_H__


/*******************************< Macros for configuration *******************************/
/**
 * @brief Defines the line numbers for external interrupts.
 * @note Your options: FROM LINE0 TO LINE15
 */
#define MEXTI_LINE0 				0     /**< The line number for interrupt line 0. */
#define MEXTI_LINE1 				1     /**< The line number for interrupt line 1. */
#define MEXTI_LINE2 				2     /**< The line number for interrupt line 2. */
#define MEXTI_LINE3 				3     /**< The line number for interrupt line 3. */
#define MEXTI_LINE4 				4     /**< The line number for interrupt line 4. */
#define MEXTI_LINE5 				5     /**< The line number for interrupt line 5. */
#define MEXTI_LINE6 				6     /**< The line number for interrupt line 6. */
#define MEXTI_LINE7 				7     /**< The line number for interrupt line 7. */
#define MEXTI_LINE8 				8     /**< The line number for interrupt line 8. */
#define MEXTI_LINE9 				9     /**< The line number for interrupt line 9. */
#define MEXTI_LINE10 				10    /**< The line number for interrupt line 10. */
#define MEXTI_LINE11 				11    /**< The line number for interrupt line 11. */
#define MEXTI_LINE12 				12    /**< The line number for interrupt line 12. */
#define MEXTI_LINE13 				13    /**< The line number for interrupt line 13. */
#define MEXTI_LINE14 				14    /**< The line number for interrupt line 14. */
#define MEXTI_LINE15 				15    /**< The line number for interrupt line 15. */



/**
 * @brief The mode for external interrupts.
 * @note Your options: RISING, FALLING, ON_CHANGE
 */
#define MEXTI_RISING 			    0    	  /**< The rising edge mode for external interrupts. */
#define MEXTI_FALLING 			    1    	  /**< The falling edge mode for external interrupts. */
#define MEXTI_ON_CHANGE 		    2    	  /**< The on-change mode for external interrupts. */


/********************************< FUNCTIONs PROTOTYPE ********************************/
/**
 * @brief Initializes the External Interrupt/Event Controller (EXTI) module.
 *
 * This function disables the interrupt for the selected EXTI line and sets the sensing mode for the line based on the configuration in the EXTI_SENSE_MODE macro.
 *
 * @param None
 *
 * @retval None
 */

 void MEXTI_voidInit(void);


/**
 * @brief Sets the signal latch mode for the selected External Interrupt/Event Controller (EXTI) line.
 *
 * This function sets the signal latch mode for the selected EXTI line based on the configuration in the Copy_u8Mode parameter.
 *
 * @param[in] Copy_u8Line: The EXTI line to set the signal latch mode for. This parameter should be one of the following options:
 *                          - MEXTI_LINE0
 *                          - MEXTI_LINE1
 *                          - MEXTI_LINE2
 *                          - MEXTI_LINE3
 *                          - MEXTI_LINE4
 *                          - MEXTI_LINE5
 *                          - MEXTI_LINE6
 *                          - MEXTI_LINE7
 *                          - MEXTI_LINE8
 *                          - MEXTI_LINE9
 *                          - MEXTI_LINE10
 *                          - MEXTI_LINE11
 *                          - MEXTI_LINE12
 *                          - MEXTI_LINE13
 *                          - MEXTI_LINE14
 *                          - MEXTI_LINE15
 *
 * @param[in] Copy_u8Mode: The signal latch mode to set for the EXTI line. This parameter should be one of the following options:
 *                          - MEXTI_RISING
 *                          - MEXTI_FALLING
 *                          - MEXTI_ON_CHANGE
 *
 * @retval Local_u8ErrorStatus: The error status of the function. This parameter returns:
 *                              - 0 if no error occurred.
 *                              - 1 if an invalid signal latch mode was provided.
 */
u8 MEXTI_u8SetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode);

/**
 * @brief Enables the interrupt for the selected External Interrupt/Event Controller (EXTI) line.
 *
 * This function enables the interrupt for the selected EXTI line.
 *
 * @param[in] Copy_u8Line: The EXTI line to enable the interrupt for. This parameter should be one of the following options:
 *                          - MEXTI_LINE0
 *                          - MEXTI_LINE1
 *                          - MEXTI_LINE2
 *                          - MEXTI_LINE3
 *                          - MEXTI_LINE4
 *                          - MEXTI_LINE5
 *                          - MEXTI_LINE6
 *                          - MEXTI_LINE7
 *                          - MEXTI_LINE8
 *                          - MEXTI_LINE9
 *                          - MEXTI_LINE10
 *                          - MEXTI_LINE11
 *                          - MEXTI_LINE12
 *                          - MEXTI_LINE13
 *                          - MEXTI_LINE14
 *                          - MEXTI_LINE15
 *
 * @retval Local_u8ErrorStatus: The error status of the function. This parameter returns:
 *                              - 0 if no error occurred.
 *                              - 1 if an invalid EXTI line was provided.
 */
u8 MEXTI_u8EnableEXTI(u8 Copy_u8Line);


/**
 * @brief Disables the interrupt for the selected External Interrupt/Event Controller (EXTI) line.
 *
 * This function disables the interrupt for the selected EXTI line.
 *
 * @param[in] Copy_u8Line: The EXTI line to disable the interrupt for. This parameter should be one of the following options:
 *                          - MEXTI_LINE0
 *                          - MEXTI_LINE1
 *                          - MEXTI_LINE2
 *                          - MEXTI_LINE3
 *                          - MEXTI_LINE4
 *                          - MEXTI_LINE5
 *                          - MEXTI_LINE6
 *                          - MEXTI_LINE7
 *                          - MEXTI_LINE8
 *                          - MEXTI_LINE9
 *                          - MEXTI_LINE10
 *                          - MEXTI_LINE11
 *                          - MEXTI_LINE12
 *                          - MEXTI_LINE13
 *                          - MEXTI_LINE14
 *                          - MEXTI_LINE15
 *
 * @retval Local_u8ErrorStatus: The error status of the function. This parameter returns:
 *                              - 0 if no error occurred.
 *                              - 1 if an invalid EXTI line was provided.
 */
u8 MEXTI_u8DisableEXTI(u8 Copy_u8Line);



/**
 * @brief Triggers a software interrupt for the selected External Interrupt/Event Controller (EXTI) line.
 *
 * This function triggers a software interrupt for the selected EXTI line. This can be used to simulate an interrupt and test interrupt handling code.
 *
 * @param[in] Copy_u8Line: The EXTI line to trigger the software interrupt for (in). This parameter should be one of the following options:
 *                          - MEXTI_LINE0
 *                          - MEXTI_LINE1
 *                          - MEXTI_LINE2
 *                          - MEXTI_LINE3
 *                          - MEXTI_LINE4
 *                          - MEXTI_LINE5
 *                          - MEXTI_LINE6
 *                          - MEXTI_LINE7
 *                          - MEXTI_LINE8
 *                          - MEXTI_LINE9
 *                          - MEXTI_LINE10
 *                          - MEXTI_LINE11
 *                          - MEXTI_LINE12
 *                          - MEXTI_LINE13
 *                          - MEXTI_LINE14
 *                          - MEXTI_LINE15
 *
 * @retval Local_u8ErrorStatus: The error status of the function. This parameter returns:
 *                              - 0 if no error occurred.
 *                              - 1 if an invalid EXTI line was provided.
 * 
 * @note This function is currently under development and cannot be used yet. Additional modifications are needed before this function can be used.
 */ 
u8 MEXTI_u8SwTrigger(u8 Copy_u8Line);

/**
 * @brief Sets the callback function to be executed when the External Interrupt/Event Controller (EXTI) interrupt occurs.
 *
 * This function sets the callback function to be executed when the EXTI interrupt occurs. The callback function should have no input parameters and no return value.
 *
 * @param[in] Copy_pfCallback: A pointer to the function to be executed when the EXTI interrupt occurs. This parameter should be a function pointer of the following type:
 *                              - void (*function_name)(void)
 *
 * @retval Local_u8ErrorStatus: The error status of the function (out). This parameter returns:
 *                              - 0 if no error occurred.
 *                              - 1 if a null function pointer was provided.
 */ 
u8 MEXTI_u8SetCallBack(void (*Copy_pfCallback)(void));



#endif /**< __EXTI_INTERFACE_H__ */
