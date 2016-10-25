// Input device tests for Wall object
//
#include "Wallfixture.h"

namespace testing {

class IndicatorFixture : public WallFixture, public ::testing::WithParamInterface<indicator_led> {
};
TEST_P(IndicatorFixture, TestTurnOnIndicator)
{
    indicator_led lamp = GetParam();

    InSequence lamp_on;
    expectMultiplexerSelectedBus(ADAFRUIT_PWM_I2C_BUS);
    EXPECT_CALL(*io->accessMockPWM(), setPin(lamp, PWM_INDICATOR_ON_VALUE, FALSE));
    wall->turnIndicatorOn(lamp);
}
TEST_P(IndicatorFixture, TestTurnOffIndicator)
{
    indicator_led lamp = GetParam();

    InSequence lamp_off;
    expectMultiplexerSelectsSX1509(ADAFRUIT_PWM_I2C_BUS);
    EXPECT_CALL(*io->accessMockPWM(), setPin(lamp, PWM_INDICATOR_OFF_VALUE, FALSE));
    wall->turnIndicatorOff(lamp);
} 
INSTANTIATE_TEST_CASE_P(IndicatorTests, IndicatorFixture, Values(
    INDICATE_WHITE_LED,
    INDICATE_RED_LED,
    INDICATE_GREEN_LED,
    INDICATE_BLUE_MOTOR,
    INDICATE_ORANGE_MOTOR,
    INDICATE_TRANSDUCER,
    INDICATE_TOGGLES,
    INDICATE_JOYSTICK,
    INDICATE_KNOB,
    INDICATE_SLIDER,
    INDICATE_PHOTO_SENSOR,
    INDICATE_TOUCH_SENSOR,
    INDICATE_POSITIVE_POLE,
    INDICATE_NEGATIVE_POLE
    )
);

}; // namespace
