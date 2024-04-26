/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Eyad Mohamed
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
        || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
        || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC const Port_ConfigPins *Port_PortPins = NULL_PTR;
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

/************************************************************************************
     * Service Name: Port_Init
     * Service ID[hex]: 0x00
     * Sync/Async: Synchronous
     * Reentrancy: Non Reentrant
     * Parameters (in): ConfigPtr - Pointer to configuration set.
     * Parameters (inout): None
     * Parameters (out): None
     * Return value: None
     * Description: Initializes the PORT Driver module.
 ************************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr)
{


    uint8 Pin_Pin_Index;
    Port_PortPins = ConfigPtr->Pins;

    #if (PORT_DEV_ERROR_DETECT == STD_ON)
        if (NULL_PTR == ConfigPtr)
        {
            Det_ReportError(PORT_MODULE_ID,
                            PORT_INSTANCE_ID,
                            PORT_INIT_SID,
                            PORT_E_PARAM_CONFIG);
        }
        else
        {
            /* Do Nothing */
        }
    #endif

    for (Pin_Pin_Index = 0; Pin_Pin_Index < PORT_CONFIGURED_PINS; Pin_Pin_Index++)
    {
        volatile uint32 *PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
        volatile uint32 delay = 0;

        switch (Port_PortPins[Pin_Pin_Index].Port_Num)
        {
        case 0:
            PortGpio_Ptr = (volatile uint32*) GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
            break;
        case 1:
            PortGpio_Ptr = (volatile uint32*) GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
            break;
        case 2:
            PortGpio_Ptr = (volatile uint32*) GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
            break;
        case 3:
            PortGpio_Ptr = (volatile uint32*) GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
            break;
        case 4:
            PortGpio_Ptr = (volatile uint32*) GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
            break;
        case 5:
            PortGpio_Ptr = (volatile uint32*) GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
            break;
        }

        /* Enable clock for PORT and allow time for clock to start */
        SYSCTL_REGCGC2_REG |= (1 << Port_PortPins[Pin_Pin_Index].Port_Num);
        delay = SYSCTL_REGCGC2_REG;

        if( ((Port_PortPins[Pin_Pin_Index].Port_Num == 3) && (Port_PortPins[Pin_Pin_Index].Pin_Num == 7)) || ((Port_PortPins[Pin_Pin_Index].Port_Num == 5) && (Port_PortPins[Pin_Pin_Index].Pin_Num == 0)) ) /* PD7 or PF0 */
        {
            /* Unlock the GPIOCR register */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;

            /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , Port_PortPins[Pin_Pin_Index].Pin_Num);
        }
        else if ((Port_PortPins[Pin_Pin_Index].Port_Num == 2) && (Port_PortPins[Pin_Pin_Index].Pin_Num <= 3))
        {
            /* Do Nothing JTAG pins */
        }
        else
        {
            /* Do Nothing ... No need to unlock the commit register for this pin */
        }


        if (Port_PortPins[Pin_Pin_Index].Pin_Mode == PORT_PIN_MODE_DIO)
        {
            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET),Port_PortPins[Pin_Pin_Index].Pin_Num);

            /* Disable Alternative function for this pin by clearing the corresponding bit in GPIOAFSEL register */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET),Port_PortPins[Pin_Pin_Index].Pin_Num);

            /* Clear the PMCx bits for this pin */
            *(volatile uint32*) ((volatile uint8*) PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_PortPins[Pin_Pin_Index].Pin_Num * 4));

            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET),Port_PortPins[Pin_Pin_Index].Pin_Num);
        }

        else if(Port_PortPins[Pin_Pin_Index].Pin_Mode == PORT_PIN_MODE_ADC)
        {
            /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET),Port_PortPins[Pin_Pin_Index].Pin_Num);

            /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
             SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET),Port_PortPins[Pin_Pin_Index].Pin_Num);

            /* Clear the PMCx bits for this pin */
            *(volatile uint32*) ((volatile uint8*) PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_PortPins[Pin_Pin_Index].Pin_Num * 4));

            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET),Port_PortPins[Pin_Pin_Index].Pin_Num);
        }

        if (Port_PortPins[Pin_Pin_Index].Pin_Direction == PORT_PIN_OUT)
        {
            /* Set the corresponding bit in the GPIODIR register to configure it as an output pin */
            SET_BIT(*(volatile uint32* )((volatile uint8* )PortGpio_Ptr + PORT_DIR_REG_OFFSET),Port_PortPins[Pin_Pin_Index].Pin_Num);

            if (Port_PortPins[Pin_Pin_Index].initial_value == STD_HIGH)
            {
                /* Set the corresponding bit in the GPIODATA register to provide initial value HIGH */
                SET_BIT(*(volatile uint32* )((volatile uint8* )PortGpio_Ptr + PORT_DATA_REG_OFFSET),Port_PortPins[Pin_Pin_Index].Pin_Num);
            }
            else
            {
                /* Clear the corresponding bit in the GPIODATA register to provide initial value LOW */
                CLEAR_BIT(*(volatile uint32* )((volatile uint8* )PortGpio_Ptr + PORT_DATA_REG_OFFSET), Port_PortPins[Pin_Pin_Index].Pin_Num);
            }
        }
        else if (Port_PortPins[Pin_Pin_Index].Pin_Direction == PORT_PIN_IN)
        {
            /* Clear the corresponding bit in the GPIODIR register to configure it as an input pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[Pin_Pin_Index].Pin_Num);

            if(Port_PortPins[Pin_Pin_Index].Resistor == PULL_UP)
            {
                /* Set the corresponding bit in the GPIOPUR register to enable the internal pull-up resistor */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PortPins[Pin_Pin_Index].Pin_Num);
            }
            else if(Port_PortPins[Pin_Pin_Index].Resistor == PULL_DOWN)
            {
                /* Set the corresponding bit in the GPIOPDR register to enable the internal pull-down resistor */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PortPins[Pin_Pin_Index].Pin_Num);
            }
            else
            {
                /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull-up resistor */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PortPins[Pin_Pin_Index].Pin_Num);

                /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull-down resistor */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PortPins[Pin_Pin_Index].Pin_Num);
            }
        }
        else
        {
            /* Do Nothing */
        }

    }

    Port_Status = PORT_INITIALIZED;
}

/************************************************************************************
     * Service Name: Port_SetPinDirection
     * Service ID[hex]: 0x01
     * Sync/Async: Synchronous
     * Reentrancy: Reentrant
     * Parameters (in): Pin - Pin ID, Direction - Pin direction to be set.
     * Parameters (inout): None
     * Parameters (out): None
     * Return value: None
     * Description: Function to set the direction of a specific pin.
 ************************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
        /* Check if the Driver is initialized before using this function */
        if(Port_Status == PORT_NOT_INITIALIZED)
        {
            Det_ReportError(PORT_MODULE_ID,
                            PORT_INSTANCE_ID,
                            PORT_SET_PIN_DIRECTION_SID,
                            PORT_E_UNINIT);
        }
        else
        {
            /* Do Nothing */
        }

        /* check if incorrect Port Pin ID passed */
        if(Pin >= PORT_CONFIGURED_PINS)
        {
            Det_ReportError(PORT_MODULE_ID,
                            PORT_INSTANCE_ID,
                            PORT_SET_PIN_DIRECTION_SID,
                            PORT_E_PARAM_PIN );
        }
        else
        {
            /* Do Nothing */
        }

        if(Port_PortPins[Pin].Pin_DirectionChangable == STD_OFF)
        {
            Det_ReportError(PORT_MODULE_ID,
                            PORT_INSTANCE_ID,
                            PORT_SET_PIN_DIRECTION_SID,
                            PORT_E_DIRECTION_UNCHANGEABLE );
        }
        else
        {
            /*DO NOTHING*/
        }
    #endif

    volatile uint32 * PortGpio_Ptr = NULL_PTR;

    if( (Port_PortPins[Pin].Port_Num == 2) && (Port_PortPins[Pin].Pin_Num <= 3)) /* PC0 to PC3 */
        {
            /* Do Nothing ...  this is the JTAG pins */
        }

    else
    {
        switch (Port_PortPins[Pin].Port_Num)
        {
        case 0:
            PortGpio_Ptr = (volatile uint32*) GPIO_PORTA_BASE_ADDRESS;
            break;
        case 1:
            PortGpio_Ptr = (volatile uint32*) GPIO_PORTB_BASE_ADDRESS;
            break;
        case 2:
            PortGpio_Ptr = (volatile uint32*) GPIO_PORTC_BASE_ADDRESS;
            break;
        case 3:
            PortGpio_Ptr = (volatile uint32*) GPIO_PORTD_BASE_ADDRESS;
            break;
        case 4:
            PortGpio_Ptr = (volatile uint32*) GPIO_PORTE_BASE_ADDRESS;
            break;
        case 5:
            PortGpio_Ptr = (volatile uint32*) GPIO_PORTF_BASE_ADDRESS;
            break;
        }
        if (Direction == PORT_PIN_OUT)
        {
            /* Set DIR Register bit to configure it as Output pin for the selected bit */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[Pin].Pin_Num);
            if(Port_PortPins[Pin].initial_value == STD_HIGH)
            {
                /* Set DATA Register bit */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_PortPins[Pin].Pin_Num);
            }
            else
            {
                /* Clear DATA Register bit */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_PortPins[Pin].Pin_Num);
            }
        }

        else if(Port_PortPins[Pin].Pin_Direction == PORT_PIN_IN)
        {
            /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[Pin].Pin_Num);

            if(Port_PortPins[Pin].Resistor == PULL_UP)
            {
                /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PortPins[Pin].Pin_Num);
            }
            else if(Port_PortPins[Pin].Resistor == PULL_DOWN)
            {
                /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PortPins[Pin].Pin_Num);
            }
            else
            {
                /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PortPins[Pin].Pin_Num);
                /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PortPins[Pin].Pin_Num);
            }
        }


    }
}
#endif

/************************************************************************************
    * Service Name: Port_RefreshPortDirection
    * Service ID[hex]: 0x02
    * Sync/Async:   Synchronous
    * Reentrancy:   Non Reentrant
    * Parameters (in):      None
    * Parameters (inout):   None
    * Parameters (out):     None
    * Return value:         None
    * Description: Function to refresh port direction.:
    *              - refreshs the direction of all configured ports to the configured direction (PortPinDirection).
************************************************************************************/
void Port_RefreshPortDirection(void)
{
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
        /* Check if the Driver is initialized before using this function */
    if(PORT_NOT_INITIALIZED == Port_Status)
        {
            /* Report to DET  */
            Det_ReportError(PORT_MODULE_ID,
                    PORT_INSTANCE_ID,
                    PORT_REFRESH_PORT_DIRECTION_SID,
                    PORT_E_UNINIT) ;
        }
        else
        {
            /* Do Nothing */
        }
    #endif

    volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    uint8 Pin_Index;

    for (Pin_Index = 0; Pin_Index < PORT_CONFIGURED_PINS; Pin_Index++)
        {
            switch (Port_PortPins[Pin_Index].Port_Num)
            {
            case 0:
                PortGpio_Ptr = (volatile uint32*) GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                break;
            case 1:
                PortGpio_Ptr = (volatile uint32*) GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                break;
            case 2:
                PortGpio_Ptr = (volatile uint32*) GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                break;
            case 3:
                PortGpio_Ptr = (volatile uint32*) GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                break;
            case 4:
                PortGpio_Ptr = (volatile uint32*) GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                break;
            case 5:
                PortGpio_Ptr = (volatile uint32*) GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                break;
            }

            if (((Port_PortPins[Pin_Index].Port_Num == 3) && (Port_PortPins[Pin_Index].Pin_Num == 7)) || ((Port_PortPins[Pin_Index].Port_Num == 5) && (Port_PortPins[Pin_Index].Pin_Num == 0)) )
            {
                /* Unlock the GPIOCR register */
                *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;

                /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , Port_PortPins[Pin_Index].Pin_Num);
            }
            else if ((Port_PortPins[Pin_Index].Port_Num == 2) && (Port_PortPins[Pin_Index].Pin_Num <= 3))
            {
                /* Do Nothing ...  this is the JTAG pins */
            }
            else
            {
                /* Do Nothing ... No need to unlock the commit register for this pin */
            }

            if (Port_PortPins[Pin_Index].Pin_DirectionChangable == STD_OFF)
            {
                if (Port_PortPins[Pin_Index].Pin_Direction == PORT_PIN_OUT)
                {
                    /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Port_PortPins[Pin_Index].Pin_Num);
                }
                else if (Port_PortPins[Pin_Index].Pin_Direction == PORT_PIN_IN)
                {
                    /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Port_PortPins[Pin_Index].Pin_Num);
                }
                else
                {
                    /* Do Nothing */
                }
            }

        }
}

/************************************************************************************
     * Service Name: Port_GetVersionInfo
     * Service ID[hex]: 0x03
     * Sync/Async: Synchronous
     * Reentrancy: Non Reentrant
     * Parameters (in): versioninfo - Pointer to version information structure.
     * Parameters (inout): None
     * Parameters (out): None
     * Return value: None
     * Description: Function to get version information of the PORT module.
 ************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)

    void Port_GetVersionInfo(Std_VersionInfoType *versioninfo)
    {
        #if (PORT_DEV_ERROR_DETECT == STD_ON)

        /* Check if the Driver is Not Initialized before using this function */
        if (PORT_NOT_INITIALIZED == Port_Status)
        {
            /* Report to DET  */
            Det_ReportError(PORT_MODULE_ID,
                            PORT_INSTANCE_ID,
                            PORT_GET_VERSION_INFO_SID,
                            PORT_E_UNINIT);
        }
        else
        {
            /* No Action Required */
        }

        if (versioninfo == NULL_PTR)
        {
            /* Report to DET  */
            Det_ReportError(PORT_MODULE_ID,
                            PORT_INSTANCE_ID,
                            PORT_GET_VERSION_INFO_SID,
                            PORT_E_PARAM_POINTER);
        }
        else
        {
            /* No Action Required */
        }

        #endif

        /* Copy the vendor Id */
        versioninfo->vendorID = (uint16) PORT_VENDOR_ID;
        /* Copy the module Id */
        versioninfo->moduleID = (uint16) PORT_MODULE_ID;
        /* Copy Software Major Version */
        versioninfo->sw_major_version = (uint8) PORT_SW_MAJOR_VERSION;
        /* Copy Software Minor Version */
        versioninfo->sw_minor_version = (uint8) PORT_SW_MINOR_VERSION;
        /* Copy Software Patch Version */
        versioninfo->sw_patch_version = (uint8) PORT_SW_PATCH_VERSION;

    }
#endif

/************************************************************************************
    * Service Name: Port_SetPinMode
    * Service ID[hex]: 0x04
    * Sync/Async: Synchronous
    * Reentrancy: reentrant
    * Parameters (in): Pin - Port Pin ID number, Mode - New Port Pin mode to be set on port pin
    * Parameters (inout): None
    * Parameters (out): None
    * Return value: None
    * Description: Sets the port pin mode.
************************************************************************************/

#if (PORT_SET_PIN_MODE_API == STD_ON)
    void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
    {
        #if (PORT_DEV_ERROR_DETECT == STD_ON)
            /* Check if the Driver is initialized before using this function */
            if(Port_Status == PORT_NOT_INITIALIZED)
            {
                Det_ReportError(PORT_MODULE_ID,
                                PORT_INSTANCE_ID,
                                PORT_SET_PIN_MODE_SID,
                                PORT_E_UNINIT);
            }
            else
            {
                /* Do Nothing */
            }

            /* check if incorrect Port Pin ID passed */
        if (Pin >= PORT_CONFIGURED_PINS)
        {
            Det_ReportError(PORT_MODULE_ID,
                            PORT_INSTANCE_ID,
                            PORT_SET_PIN_MODE_SID,
                            PORT_E_UNINIT);
        }
        else
        {
            /* Do Nothing */
        }

        /* check if the Port Pin Mode passed not valid */
        if(Mode > PORT_PIN_MODE_DIO)
        {
            Det_ReportError(PORT_MODULE_ID,
                            PORT_INSTANCE_ID,
                            PORT_SET_PIN_MODE_SID,
                            PORT_E_UNINIT);
        }
        else
        {
            /* Do Nothing */
        }

        /* check if the API called when the mode is unchangeable */
        if (Port_PortPins[Pin].Pin_ModeChangable != STD_ON)
        {
            Det_ReportError(PORT_MODULE_ID,
                            PORT_INSTANCE_ID,
                            PORT_SET_PIN_MODE_SID,
                            PORT_E_UNINIT);
        }
        else
        {
            /* Do Nothing */
        }
        #endif

        volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */

        switch(Port_PortPins[Pin].Port_Num)
        {
            case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
             break;
            case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
             break;
            case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
             break;
            case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
             break;
            case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
             break;
            case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
             break;
        }

        if ((Port_PortPins[Pin].Port_Num == 2) && (Port_PortPins[Pin].Pin_Num <= 3))
        {
            /* Do Nothing ...  this is the JTAG pins */
        }



        if (Port_PortPins[Pin].Pin_Mode == PORT_PIN_MODE_DIO)
        {
            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(
                    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET),
                    Port_PortPins[Pin].Pin_Num);

            /* Disable Alternative function for this pin by clearing the corresponding bit in GPIOAFSEL register */
            CLEAR_BIT(
                    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET),
                    Port_PortPins[Pin].Pin_Num);

            /* Clear the PMCx bits for this pin */
            *(volatile uint32*) ((volatile uint8*) PortGpio_Ptr
                    + PORT_CTL_REG_OFFSET) &= ~(0x0000000F
                    << (Port_PortPins[Pin].Pin_Num * 4));

            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET),
                    Port_PortPins[Pin].Pin_Num);
        }


        else if (Port_PortPins[Pin].Pin_Mode == PORT_PIN_MODE_ADC)
        {
            /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
            CLEAR_BIT(
                    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET),
                    Port_PortPins[Pin].Pin_Num);

            /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET),
                    Port_PortPins[Pin].Pin_Num);

            /* Clear the PMCx bits for this pin */
            *(volatile uint32*) ((volatile uint8*) PortGpio_Ptr
                    + PORT_CTL_REG_OFFSET) &= ~(0x0000000F
                    << (Port_PortPins[Pin].Pin_Num * 4));

            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET),
                    Port_PortPins[Pin].Pin_Num);
        }


        else
        {
            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PortPins[Pin].Pin_Num);

            /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortPins[Pin].Pin_Num);

            /* Set the PMCx bits for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (Mode & 0x0000000F << (Port_PortPins[Pin].Pin_Num * 4));

            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PortPins[Pin].Pin_Num);
        }
    }
#endif

