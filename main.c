/***************************************************************************//**
 * @file main.c
 * @brief main() function.
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#include "em_cmu.h"
#include "em_gpio.h"
#include "em_wdog.h"
#include "sl_udelay.h"

int main(void)
{
  for (int i = 0; i < 3000; i++) {
      sl_udelay_wait(1000);
  }
  CMU_ClockEnable(cmuClock_WDOG0, true);
  CMU_ClockEnable(cmuClock_GPIO, true);
  GPIO_PinModeSet(gpioPortB, 0, gpioModePushPull, 1);
  WDOG_Init_TypeDef wdogInit = WDOG_INIT_DEFAULT;
  wdogInit.perSel = wdogPeriod_128k;
  WDOGn_Init(WDOG0, &wdogInit);
  while (1) {
      // WDOGn_Feed(WDOG0);
  }
}
