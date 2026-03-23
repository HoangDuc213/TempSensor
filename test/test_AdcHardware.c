/* =========================================================================
    Ceedling - Test-Centered Build System for C
    ThrowTheSwitch.org
    Copyright (c) 2010-25 Mike Karlesky, Mark VanderVoord, & Greg Williams
    SPDX-License-Identifier: MIT
========================================================================= */

#include "unity.h"
#include "Types.h"
#include "AdcHardware.h"
#include "mock_AdcHardwareConfigurator.h"
#include "mock_AdcTemperatureSensor.h"

void setUp(void){ }

void tearDown(void) { }
/* TC-ADC-001 */
void testInitShouldDelegateToConfiguratorAndTemperatureSensor(void)
{
  Adc_Reset_Expect();
  Adc_ConfigureMode_Expect();
  Adc_EnableTemperatureChannel_Expect();
  Adc_StartTemperatureSensorConversion_Expect();

  AdcHardware_Init();
}
/* TC-ADC-002 */
void testGetSampleCompleteShouldReturn_FALSE_WhenTemperatureSensorSampleReadyReturns_FALSE(void)
{
  Adc_TemperatureSensorSampleReady_ExpectAndReturn(FALSE);
  TEST_ASSERT(!AdcHardware_GetSampleComplete());
}
/* TC-ADC-003 */
void testGetSampleCompleteShouldReturn_TRUE_WhenTemperatureSensorSampleReadyReturns_TRUE(void)
{
  Adc_TemperatureSensorSampleReady_ExpectAndReturn(TRUE);
  TEST_ASSERT(AdcHardware_GetSampleComplete());
}
/* TC-ADC-004 */
void testGetSampleShouldDelegateToAdcTemperatureSensor(void)
{
  uint16 sample;
  Adc_ReadTemperatureSensor_ExpectAndReturn(847);

  sample = AdcHardware_GetSample();
  TEST_ASSERT_EQUAL_INT(847, sample);
}
