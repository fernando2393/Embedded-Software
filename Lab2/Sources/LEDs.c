/*! @file
 *
 * @brief LEDs functions implementation and initialization
 *
 * LEDs.c
 *
 *  Created on: 6 Apr 2018
 *      Author: 13181680
 */

#include "types.h"
#include "LEDs.h"
#include "MK70F12.h"

/*! @brief Sets up the LEDs before first use.
   *
   *  @return bool - TRUE if the LEDs were successfully initialized.
   */

bool LEDs_Init()
{

  //Turn on PortA

  SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK; //Port A enabled

  PORTA_PCR10 |= PORT_PCR_MUX(1); //Pin 10 initialized ---> Blue
  PORTA_PCR11 |= PORT_PCR_MUX(1); //Pin 11 initialized ---> Orange
  PORTA_PCR28 |= PORT_PCR_MUX(1); //Pin 28 initialized ---> Yellow
  PORTA_PCR29 |= PORT_PCR_MUX(1); //Pin 29 initialized ---> Green

  GPIOA_PDDR |= 0x30000C00;
  GPIOA_PSOR |= 0x30000C00;

}


/*! @brief Turns an LED on.
 *
 *  @param color The color of the LED to turn on.
 */

void LEDs_On(const TLED color)
{
  GPIOA_PCOR |= color;
}


/*! @brief Turns off an LED.
  *
  *  @param color THe color of the LED to turn off.
  */

void LEDs_Off(const TLED color)
{
  GPIOA_PSOR |= color;
}

/*! @brief Inverts LED's state ( ON to OFF and vice versa )
 *  @param color - toggled color
 */

void LEDs_Toggle(const TLED color)
{
  GPIOA_PTOR |= color;
}
