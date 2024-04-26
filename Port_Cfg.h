 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Port_Cfg file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Eyad Mohamed
 ******************************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION      (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION      (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION      (3U)

/* Switches the Development Error Detection and Notification on or off
. true: Enabled.
false: Disabled */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* PPre-processor switch to enable / disable the use of the function Port_SetPinDirection().
TRUE: Enabled - Function Port_SetPinDirection() is available.
FALSE: Disabled - Function Port_SetPinDirection() is not available. */
#define PORT_SET_PIN_DIRECTION_API           (STD_ON)

/* Pre-processor switch to enable / disable the use of the function Port_SetPinMode().
true: Enabled - Function Port_SetPinMode() is available.
false: Disabled - Function Port_SetPinMode() is not available. */
#define PORT_SET_PIN_MODE_API                (STD_ON)

/* Pre-processor switch to enable / disable the API to read out the modules version information.
true: Version info API enabled.
false: Version info API disabled. */
#define PORT_VERSION_INFO_API                (STD_ON)
/*
The initial direction of the pin (IN or OUT).
If the direction is not changeable, the value configured here is fixed.
The direction must match the pin mode.
E.g. a pin used for an ADC must be configured to be an in port.
Implementation Type: Port_PinDirectionType
*/
#define PORT_PIN_DIRECTION                       (STD_ON)

/* Number of the configured Port PINs */
#define PORT_CONFIGURED_PINS              (43U)

/*Parameter to indicate if the direction is changeable on a port pin during runtime.
true: Port Pin direction changeable enabled.
false: Port Pin direction changeable disabled.*/
#define PORT_PIN_MODE_CHANGEABLE                 (STD_ON)





/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define PORTA_ID                    (0U)
#define PORTB_ID                    (1U)
#define PORTC_ID                    (2U)
#define PORTD_ID                    (3U)
#define PORTE_ID                    (4U)
#define PORTF_ID                    (5U)


#define PIN0_ID                     (0U)
#define PIN1_ID                     (1U)
#define PIN2_ID                     (2U)
#define PIN3_ID                     (3U)
#define PIN4_ID                     (4U)
#define PIN5_ID                     (5U)
#define PIN6_ID                     (6U)
#define PIN7_ID                     (7U)

/*******************************************************************************
 *                           Pins Direction                                    *
 *******************************************************************************/
#define PORTA_PIN0_DIRECTION       (PORT_PIN_IN)
#define PORTA_PIN1_DIRECTION       (PORT_PIN_IN)
#define PORTA_PIN2_DIRECTION       (PORT_PIN_IN)
#define PORTA_PIN3_DIRECTION       (PORT_PIN_IN)
#define PORTA_PIN4_DIRECTION       (PORT_PIN_IN)
#define PORTA_PIN5_DIRECTION       (PORT_PIN_IN)
#define PORTA_PIN6_DIRECTION       (PORT_PIN_IN)
#define PORTA_PIN7_DIRECTION       (PORT_PIN_IN)

#define PORTB_PIN0_DIRECTION       (PORT_PIN_IN)
#define PORTB_PIN1_DIRECTION       (PORT_PIN_IN)
#define PORTB_PIN2_DIRECTION       (PORT_PIN_IN)
#define PORTB_PIN3_DIRECTION       (PORT_PIN_IN)
#define PORTB_PIN4_DIRECTION       (PORT_PIN_IN)
#define PORTB_PIN5_DIRECTION       (PORT_PIN_IN)
#define PORTB_PIN6_DIRECTION       (PORT_PIN_IN)
#define PORTB_PIN7_DIRECTION       (PORT_PIN_IN)

#define PORTC_PIN0_DIRECTION       (PORT_PIN_IN)
#define PORTC_PIN1_DIRECTION       (PORT_PIN_IN)
#define PORTC_PIN2_DIRECTION       (PORT_PIN_IN)
#define PORTC_PIN3_DIRECTION       (PORT_PIN_IN)
#define PORTC_PIN4_DIRECTION       (PORT_PIN_IN)
#define PORTC_PIN5_DIRECTION       (PORT_PIN_IN)
#define PORTC_PIN6_DIRECTION       (PORT_PIN_IN)
#define PORTC_PIN7_DIRECTION       (PORT_PIN_IN)

#define PORTD_PIN0_DIRECTION       (PORT_PIN_IN)
#define PORTD_PIN1_DIRECTION       (PORT_PIN_IN)
#define PORTD_PIN2_DIRECTION       (PORT_PIN_IN)
#define PORTD_PIN3_DIRECTION       (PORT_PIN_IN)
#define PORTD_PIN4_DIRECTION       (PORT_PIN_IN)
#define PORTD_PIN5_DIRECTION       (PORT_PIN_IN)
#define PORTD_PIN6_DIRECTION       (PORT_PIN_IN)
#define PORTD_PIN7_DIRECTION       (PORT_PIN_IN)

#define PORTE_PIN0_DIRECTION       (PORT_PIN_IN)
#define PORTE_PIN1_DIRECTION       (PORT_PIN_IN)
#define PORTE_PIN2_DIRECTION       (PORT_PIN_IN)
#define PORTE_PIN3_DIRECTION       (PORT_PIN_IN)
#define PORTE_PIN4_DIRECTION       (PORT_PIN_IN)
#define PORTE_PIN5_DIRECTION       (PORT_PIN_IN)

#define PORTF_PIN0_DIRECTION       (PORT_PIN_IN)
#define PORTF_PIN1_DIRECTION       (PORT_PIN_OUT) /* LED */
#define PORTF_PIN2_DIRECTION       (PORT_PIN_IN)
#define PORTF_PIN3_DIRECTION       (PORT_PIN_IN)
#define PORTF_PIN4_DIRECTION       (PORT_PIN_IN) /* Switch */

/*******************************************************************************
 *                            Pins Initial value                               *
 *******************************************************************************/
#define PORTA_PIN0_DATA       (STD_LOW)
#define PORTA_PIN1_DATA       (STD_LOW)
#define PORTA_PIN2_DATA       (STD_LOW)
#define PORTA_PIN3_DATA       (STD_LOW)
#define PORTA_PIN4_DATA       (STD_LOW)
#define PORTA_PIN5_DATA       (STD_LOW)
#define PORTA_PIN6_DATA       (STD_LOW)
#define PORTA_PIN7_DATA       (STD_LOW)

#define PORTB_PIN0_DATA       (STD_LOW)
#define PORTB_PIN1_DATA       (STD_LOW)
#define PORTB_PIN2_DATA       (STD_LOW)
#define PORTB_PIN3_DATA       (STD_LOW)
#define PORTB_PIN4_DATA       (STD_LOW)
#define PORTB_PIN5_DATA       (STD_LOW)
#define PORTB_PIN6_DATA       (STD_LOW)
#define PORTB_PIN7_DATA       (STD_LOW)

#define PORTC_PIN0_DATA       (STD_LOW)
#define PORTC_PIN1_DATA       (STD_LOW)
#define PORTC_PIN2_DATA       (STD_LOW)
#define PORTC_PIN3_DATA       (STD_LOW)
#define PORTC_PIN4_DATA       (STD_LOW)
#define PORTC_PIN5_DATA       (STD_LOW)
#define PORTC_PIN6_DATA       (STD_LOW)
#define PORTC_PIN7_DATA       (STD_LOW)

#define PORTD_PIN0_DATA       (STD_LOW)
#define PORTD_PIN1_DATA       (STD_LOW)
#define PORTD_PIN2_DATA       (STD_LOW)
#define PORTD_PIN3_DATA       (STD_LOW)
#define PORTD_PIN4_DATA       (STD_LOW)
#define PORTD_PIN5_DATA       (STD_LOW)
#define PORTD_PIN6_DATA       (STD_LOW)
#define PORTD_PIN7_DATA       (STD_LOW)

#define PORTE_PIN0_DATA       (STD_LOW)
#define PORTE_PIN1_DATA       (STD_LOW)
#define PORTE_PIN2_DATA       (STD_LOW)
#define PORTE_PIN3_DATA       (STD_LOW)
#define PORTE_PIN4_DATA       (STD_LOW)
#define PORTE_PIN5_DATA       (STD_LOW)

#define PORTF_PIN0_DATA       (STD_LOW)
#define PORTF_PIN1_DATA       (STD_HIGH)
#define PORTF_PIN2_DATA       (STD_LOW)
#define PORTF_PIN3_DATA       (STD_LOW)
#define PORTF_PIN4_DATA       (STD_LOW)/* Switch */

/*******************************************************************************
 *                           Pins Modes                                        *
 *******************************************************************************/
#define PORTA_PIN0_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTA_PIN1_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTA_PIN2_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTA_PIN3_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTA_PIN4_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTA_PIN5_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTA_PIN6_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTA_PIN7_MODE_TYPE      (PORT_PIN_MODE_DIO)

#define PORTB_PIN0_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTB_PIN1_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTB_PIN2_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTB_PIN3_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTB_PIN4_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTB_PIN5_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTB_PIN6_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTB_PIN7_MODE_TYPE      (PORT_PIN_MODE_DIO)

#define PORTC_PIN0_MODE_TYPE      (PORT_PIN_MODE_OFF)
#define PORTC_PIN1_MODE_TYPE      (PORT_PIN_MODE_OFF)
#define PORTC_PIN2_MODE_TYPE      (PORT_PIN_MODE_OFF)
#define PORTC_PIN3_MODE_TYPE      (PORT_PIN_MODE_OFF)
#define PORTC_PIN4_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTC_PIN5_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTC_PIN6_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTC_PIN7_MODE_TYPE      (PORT_PIN_MODE_DIO)

#define PORTD_PIN0_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTD_PIN1_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTD_PIN2_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTD_PIN3_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTD_PIN4_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTD_PIN5_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTD_PIN6_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTD_PIN7_MODE_TYPE      (PORT_PIN_MODE_DIO)

#define PORTE_PIN0_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTE_PIN1_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTE_PIN2_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTE_PIN3_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTE_PIN4_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTE_PIN5_MODE_TYPE      (PORT_PIN_MODE_DIO)

#define PORTF_PIN0_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTF_PIN1_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTF_PIN2_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTF_PIN3_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTF_PIN4_MODE_TYPE      (PORT_PIN_MODE_DIO)

/*******************************************************************************
 *                           Pins Internal Resistor                            *
 *******************************************************************************/
#define PORTA_PIN0_RESISTOR       (OFF)
#define PORTA_PIN1_RESISTOR       (OFF)
#define PORTA_PIN2_RESISTOR       (OFF)
#define PORTA_PIN3_RESISTOR       (OFF)
#define PORTA_PIN4_RESISTOR       (OFF)
#define PORTA_PIN5_RESISTOR       (OFF)
#define PORTA_PIN6_RESISTOR       (OFF)
#define PORTA_PIN7_RESISTOR       (OFF)

#define PORTB_PIN0_RESISTOR       (OFF)
#define PORTB_PIN1_RESISTOR       (OFF)
#define PORTB_PIN2_RESISTOR       (OFF)
#define PORTB_PIN3_RESISTOR       (OFF)
#define PORTB_PIN4_RESISTOR       (OFF)
#define PORTB_PIN5_RESISTOR       (OFF)
#define PORTB_PIN6_RESISTOR       (OFF)
#define PORTB_PIN7_RESISTOR       (OFF)

#define PORTC_PIN0_RESISTOR       (OFF)
#define PORTC_PIN1_RESISTOR       (OFF)
#define PORTC_PIN2_RESISTOR       (OFF)
#define PORTC_PIN3_RESISTOR       (OFF)
#define PORTC_PIN4_RESISTOR       (OFF)
#define PORTC_PIN5_RESISTOR       (OFF)
#define PORTC_PIN6_RESISTOR       (OFF)
#define PORTC_PIN7_RESISTOR       (OFF)

#define PORTD_PIN0_RESISTOR       (OFF)
#define PORTD_PIN1_RESISTOR       (OFF)
#define PORTD_PIN2_RESISTOR       (OFF)
#define PORTD_PIN3_RESISTOR       (OFF)
#define PORTD_PIN4_RESISTOR       (OFF)
#define PORTD_PIN5_RESISTOR       (OFF)
#define PORTD_PIN6_RESISTOR       (OFF)
#define PORTD_PIN7_RESISTOR       (OFF)

#define PORTE_PIN0_RESISTOR       (OFF)
#define PORTE_PIN1_RESISTOR       (OFF)
#define PORTE_PIN2_RESISTOR       (OFF)
#define PORTE_PIN3_RESISTOR       (OFF)
#define PORTE_PIN4_RESISTOR       (OFF)
#define PORTE_PIN5_RESISTOR       (OFF)

#define PORTF_PIN0_RESISTOR       (OFF)
#define PORTF_PIN1_RESISTOR       (OFF)
#define PORTF_PIN2_RESISTOR       (OFF)
#define PORTF_PIN3_RESISTOR       (OFF)
#define PORTF_PIN4_RESISTOR       (PULL_UP) /* Switch */

/*******************************************************************************
 *                          Pins Direction Changable                           *
 *******************************************************************************/
#define PORTA_PIN0_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTA_PIN1_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTA_PIN2_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTA_PIN3_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTA_PIN4_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTA_PIN5_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTA_PIN6_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTA_PIN7_DIRECTION_CHANGABLE         (STD_OFF)

#define PORTB_PIN0_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTB_PIN1_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTB_PIN2_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTB_PIN3_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTB_PIN4_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTB_PIN5_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTB_PIN6_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTB_PIN7_DIRECTION_CHANGABLE         (STD_OFF)

#define PORTC_PIN0_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTC_PIN1_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTC_PIN2_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTC_PIN3_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTC_PIN4_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTC_PIN5_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTC_PIN6_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTC_PIN7_DIRECTION_CHANGABLE         (STD_OFF)

#define PORTD_PIN0_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTD_PIN1_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTD_PIN2_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTD_PIN3_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTD_PIN4_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTD_PIN5_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTD_PIN6_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTD_PIN7_DIRECTION_CHANGABLE         (STD_OFF)

#define PORTE_PIN0_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTE_PIN1_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTE_PIN2_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTE_PIN3_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTE_PIN4_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTE_PIN5_DIRECTION_CHANGABLE         (STD_OFF)

#define PORTF_PIN0_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTF_PIN1_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTF_PIN2_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTF_PIN3_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTF_PIN4_DIRECTION_CHANGABLE         (STD_OFF)

/*******************************************************************************
 *                          Pins Mode Changable                                *
 *******************************************************************************/

#define PORTA_PIN0_MODE_CHANGABLE         (STD_OFF)
#define PORTA_PIN1_MODE_CHANGABLE         (STD_OFF)
#define PORTA_PIN2_MODE_CHANGABLE         (STD_OFF)
#define PORTA_PIN3_MODE_CHANGABLE         (STD_OFF)
#define PORTA_PIN4_MODE_CHANGABLE         (STD_OFF)
#define PORTA_PIN5_MODE_CHANGABLE         (STD_OFF)
#define PORTA_PIN6_MODE_CHANGABLE         (STD_OFF)
#define PORTA_PIN7_MODE_CHANGABLE         (STD_OFF)

#define PORTB_PIN0_MODE_CHANGABLE         (STD_OFF)
#define PORTB_PIN1_MODE_CHANGABLE         (STD_OFF)
#define PORTB_PIN2_MODE_CHANGABLE         (STD_OFF)
#define PORTB_PIN3_MODE_CHANGABLE         (STD_OFF)
#define PORTB_PIN4_MODE_CHANGABLE         (STD_OFF)
#define PORTB_PIN5_MODE_CHANGABLE         (STD_OFF)
#define PORTB_PIN6_MODE_CHANGABLE         (STD_OFF)
#define PORTB_PIN7_MODE_CHANGABLE         (STD_OFF)

#define PORTC_PIN0_MODE_CHANGABLE         (STD_OFF)
#define PORTC_PIN1_MODE_CHANGABLE         (STD_OFF)
#define PORTC_PIN2_MODE_CHANGABLE         (STD_OFF)
#define PORTC_PIN3_MODE_CHANGABLE         (STD_OFF)
#define PORTC_PIN4_MODE_CHANGABLE         (STD_OFF)
#define PORTC_PIN5_MODE_CHANGABLE         (STD_OFF)
#define PORTC_PIN6_MODE_CHANGABLE         (STD_OFF)
#define PORTC_PIN7_MODE_CHANGABLE         (STD_OFF)

#define PORTD_PIN0_MODE_CHANGABLE         (STD_OFF)
#define PORTD_PIN1_MODE_CHANGABLE         (STD_OFF)
#define PORTD_PIN2_MODE_CHANGABLE         (STD_OFF)
#define PORTD_PIN3_MODE_CHANGABLE         (STD_OFF)
#define PORTD_PIN4_MODE_CHANGABLE         (STD_OFF)
#define PORTD_PIN5_MODE_CHANGABLE         (STD_OFF)
#define PORTD_PIN6_MODE_CHANGABLE         (STD_OFF)
#define PORTD_PIN7_MODE_CHANGABLE         (STD_OFF)

#define PORTE_PIN0_MODE_CHANGABLE         (STD_OFF)
#define PORTE_PIN1_MODE_CHANGABLE         (STD_OFF)
#define PORTE_PIN2_MODE_CHANGABLE         (STD_OFF)
#define PORTE_PIN3_MODE_CHANGABLE         (STD_OFF)
#define PORTE_PIN4_MODE_CHANGABLE         (STD_OFF)
#define PORTE_PIN5_MODE_CHANGABLE         (STD_OFF)

#define PORTF_PIN0_MODE_CHANGABLE         (STD_OFF)
#define PORTF_PIN1_MODE_CHANGABLE         (STD_OFF)
#define PORTF_PIN2_MODE_CHANGABLE         (STD_OFF)
#define PORTF_PIN3_MODE_CHANGABLE         (STD_OFF)
#define PORTF_PIN4_MODE_CHANGABLE         (STD_OFF)

/*******************************************************************************
 *                           Port Modes                                        *
 *******************************************************************************/

#define PORT_PIN_MODE_ADC        (uint8)9
#define PORT_PIN_MODE_DIO        (uint8)0
#define PORT_PIN_MODE_UART       (uint8)1
#define PORT_PIN_MODE_SPI        (uint8)2
#define PORT_PIN_MODE_I2C        (uint8)3
#define PORT_PIN_MODE_TIMER      (uint8)7
#define PORT_PIN_MODE_CAN        (uint8)8
#define PORT_PIN_MODE_OFF        (uint8)10



#endif /* PORT_CFG_H_ */
