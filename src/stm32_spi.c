/****************************************************************************
 * boards/arm/stm32h7/josh/src/stm32_spi.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdbool.h>
#include <nuttx/spi/spi.h>

#include "stm32_gpio.h"
#include "stm32_spi.h"
#include "josh.h"

#ifdef CONFIG_STM32H7_SPI

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stm32_spidev_initialize
 *
 * Description:
 *   Configure SPI chip select GPIO pins. Call once during board bring-up.
 *
 ****************************************************************************/

void stm32_spidev_initialize(void)
{
#ifdef CONFIG_STM32H7_SPI1
  stm32_configgpio(GPIO_SPI1_CS_IMU);
  stm32_gpiowrite(GPIO_SPI1_CS_IMU, true); /* deassert */
#endif

#ifdef CONFIG_STM32H7_SPI3
  stm32_configgpio(GPIO_SPI3_CS_MAG);
  stm32_gpiowrite(GPIO_SPI3_CS_MAG, true); /* deassert */
#endif

#ifdef CONFIG_STM32H7_SPI2
  stm32_configgpio(GPIO_SPI2_CS0);
  stm32_gpiowrite(GPIO_SPI2_CS0, true); /* deassert */
#endif

#ifdef CONFIG_STM32H7_SPI4
  stm32_configgpio(GPIO_SPI4_CS0);
  stm32_gpiowrite(GPIO_SPI4_CS0, true); /* deassert */
#endif
}

#ifdef CONFIG_STM32H7_SPI1
void stm32_spi1select(FAR struct spi_dev_s *dev, uint32_t devid,
                      bool selected)
{
  if (devid == SPIDEV_USER(0))
    {
      stm32_gpiowrite(GPIO_SPI1_CS_IMU, !selected);
    }
}

uint8_t stm32_spi1status(FAR struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}
#endif /* CONFIG_STM32H7_SPI1 */

#ifdef CONFIG_STM32H7_SPI3
void stm32_spi3select(FAR struct spi_dev_s *dev, uint32_t devid,
                      bool selected)
{
  if (devid == SPIDEV_USER(0))
    {
      stm32_gpiowrite(GPIO_SPI3_CS_MAG, !selected);
    }
}

uint8_t stm32_spi3status(FAR struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}
#endif /* CONFIG_STM32H7_SPI3 */

#ifdef CONFIG_STM32H7_SPI2
void stm32_spi2select(FAR struct spi_dev_s *dev, uint32_t devid,
                      bool selected)
{
  if (devid == SPIDEV_USER(0))
    {
      stm32_gpiowrite(GPIO_SPI2_CS0, !selected);
    }
}

uint8_t stm32_spi2status(FAR struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}
#endif /* CONFIG_STM32H7_SPI2 */

#ifdef CONFIG_STM32H7_SPI4
void stm32_spi4select(FAR struct spi_dev_s *dev, uint32_t devid,
                      bool selected)
{
  if (devid == SPIDEV_USER(0))
    {
      stm32_gpiowrite(GPIO_SPI4_CS0, !selected);
    }
}

uint8_t stm32_spi4status(FAR struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}
#endif /* CONFIG_STM32H7_SPI4 */

#endif /* CONFIG_STM32H7_SPI */
