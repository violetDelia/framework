#include "test_config.h"
#ifdef TEST_CORE
#include "core.hpp"
#include <glog/logging.h>
#include <gtest/gtest.h>

#ifdef TEST_BASE_TYPE
TEST(test_core, int8_t)
{
    ASSERT_EQ(sizeof(Framework::int8_t), 1);
    ASSERT_EQ(std::numeric_limits<Framework::int8_t>::max(), 127);
    ASSERT_EQ(std::numeric_limits<Framework::int8_t>::min(), -128);
    ASSERT_EQ(std::is_integral<Framework::int8_t>::value, true);
    ASSERT_EQ(std::is_floating_point<Framework::int8_t>::value, false);
    ASSERT_EQ(std::is_signed<Framework::int8_t>::value, true);
    ASSERT_EQ(std::is_unsigned<Framework::int8_t>::value, false);
    ASSERT_EQ(std::numeric_limits<Framework::int8_t>::is_bounded, true);
}
TEST(test_core, int16_t)
{
    ASSERT_EQ(sizeof(Framework::int16_t), 2);
    ASSERT_EQ(std::numeric_limits<Framework::int16_t>::max(), 32767);
    ASSERT_EQ(std::numeric_limits<Framework::int16_t>::min(), -32768);
    ASSERT_EQ(std::is_integral<Framework::int16_t>::value, true);
    ASSERT_EQ(std::is_floating_point<Framework::int16_t>::value, false);
    ASSERT_EQ(std::is_signed<Framework::int16_t>::value, true);
    ASSERT_EQ(std::is_unsigned<Framework::int16_t>::value, false);
    ASSERT_EQ(std::numeric_limits<Framework::int16_t>::is_bounded, true);
}
TEST(test_core, int32_t)
{
    ASSERT_EQ(sizeof(Framework::int32_t), 4);
    ASSERT_EQ(std::numeric_limits<Framework::int32_t>::max(), 2147483647);
    ASSERT_EQ(std::numeric_limits<Framework::int32_t>::min(), -2147483648);
    ASSERT_EQ(std::is_integral<Framework::int32_t>::value, true);
    ASSERT_EQ(std::is_floating_point<Framework::int32_t>::value, false);
    ASSERT_EQ(std::is_signed<Framework::int32_t>::value, true);
    ASSERT_EQ(std::is_unsigned<Framework::int32_t>::value, false);
    ASSERT_EQ(std::numeric_limits<Framework::int32_t>::is_bounded, true);
}
TEST(test_core, int64_t)
{
    ASSERT_EQ(sizeof(Framework::int64_t), 8);
    ASSERT_EQ(std::numeric_limits<Framework::int64_t>::max(), LLONG_MAX);
    ASSERT_EQ(std::numeric_limits<Framework::int64_t>::min(), LLONG_MIN);
    ASSERT_EQ(std::is_integral<Framework::int64_t>::value, true);
    ASSERT_EQ(std::is_floating_point<Framework::int64_t>::value, false);
    ASSERT_EQ(std::is_signed<Framework::int64_t>::value, true);
    ASSERT_EQ(std::is_unsigned<Framework::int32_t>::value, false);
    ASSERT_EQ(std::numeric_limits<Framework::int64_t>::is_bounded, true);
}
TEST(test_core, uint8_t)
{
    ASSERT_EQ(sizeof(Framework::uint8_t), 1);
    ASSERT_EQ(std::numeric_limits<Framework::uint8_t>::max(), 255);
    ASSERT_EQ(std::numeric_limits<Framework::uint8_t>::min(), 0);
    ASSERT_EQ(std::is_integral<Framework::uint8_t>::value, true);
    ASSERT_EQ(std::is_floating_point<Framework::uint8_t>::value, false);
    ASSERT_EQ(std::is_signed<Framework::uint8_t>::value, false);
    ASSERT_EQ(std::is_unsigned<Framework::uint8_t>::value, true);
    ASSERT_EQ(std::numeric_limits<Framework::uint8_t>::is_bounded, true);
}
TEST(test_core, uint16_t)
{
    ASSERT_EQ(sizeof(Framework::uint16_t), 2);
    ASSERT_EQ(std::numeric_limits<Framework::uint16_t>::max(), 65535);
    ASSERT_EQ(std::numeric_limits<Framework::uint16_t>::min(), 0);
    ASSERT_EQ(std::is_integral<Framework::uint16_t>::value, true);
    ASSERT_EQ(std::is_floating_point<Framework::uint16_t>::value, false);
    ASSERT_EQ(std::is_signed<Framework::uint16_t>::value, false);
    ASSERT_EQ(std::is_unsigned<Framework::uint16_t>::value, true);
    ASSERT_EQ(std::numeric_limits<Framework::uint16_t>::is_bounded, true);
}
TEST(test_core, uint32_t)
{
    ASSERT_EQ(sizeof(Framework::uint32_t), 4);
    ASSERT_EQ(std::numeric_limits<Framework::uint32_t>::max(), 4294967295);
    ASSERT_EQ(std::numeric_limits<Framework::uint32_t>::min(), 0);
    ASSERT_EQ(std::is_integral<Framework::uint32_t>::value, true);
    ASSERT_EQ(std::is_floating_point<Framework::uint32_t>::value, false);
    ASSERT_EQ(std::is_signed<Framework::uint32_t>::value, false);
    ASSERT_EQ(std::is_unsigned<Framework::uint8_t>::value, true);
    ASSERT_EQ(std::numeric_limits<Framework::uint32_t>::is_bounded, true);
}
TEST(test_core, uint64_t)
{
    ASSERT_EQ(sizeof(Framework::uint64_t), 8);
    ASSERT_EQ(std::numeric_limits<Framework::uint64_t>::max(), ULLONG_MAX);
    ASSERT_EQ(std::numeric_limits<Framework::uint64_t>::min(), 0);
    ASSERT_EQ(std::is_integral<Framework::uint64_t>::value, true);
    ASSERT_EQ(std::is_floating_point<Framework::uint64_t>::value, false);
    ASSERT_EQ(std::is_signed<Framework::uint64_t>::value, false);
    ASSERT_EQ(std::is_unsigned<Framework::uint64_t>::value, true);
    ASSERT_EQ(std::numeric_limits<Framework::uint64_t>::is_bounded, true);
}
TEST(test_core, float32_t)
{
    ASSERT_EQ(sizeof(Framework::float32_t), 4);
    ASSERT_EQ(std::numeric_limits<Framework::float32_t>::max(), FLT_MAX);
    ASSERT_EQ(std::numeric_limits<Framework::float32_t>::min(), FLT_MIN);
    ASSERT_EQ(std::is_integral<Framework::float32_t>::value, false);
    ASSERT_EQ(std::is_floating_point<Framework::float32_t>::value, true);
    ASSERT_EQ(std::is_signed<Framework::float32_t>::value, true);
    ASSERT_EQ(std::is_unsigned<Framework::float32_t>::value, false);
    ASSERT_EQ(std::numeric_limits<Framework::float32_t>::is_bounded, true);
    ASSERT_EQ(std::numeric_limits<Framework::float32_t>::has_infinity, true);
    ASSERT_EQ(std::numeric_limits<Framework::float32_t>::has_quiet_NaN, true);
}
TEST(test_core, float64_t)
{
    ASSERT_EQ(sizeof(Framework::float64_t), 8);
    ASSERT_EQ(std::numeric_limits<Framework::float64_t>::max(), DBL_MAX);
    ASSERT_EQ(std::numeric_limits<Framework::float64_t>::min(), DBL_MIN);
    ASSERT_EQ(std::is_integral<Framework::float64_t>::value, false);
    ASSERT_EQ(std::is_floating_point<Framework::float64_t>::value, true);
    ASSERT_EQ(std::is_signed<Framework::float64_t>::value, true);
    ASSERT_EQ(std::is_unsigned<Framework::float64_t>::value, false);
    ASSERT_EQ(std::numeric_limits<Framework::float64_t>::is_bounded, true);
    ASSERT_EQ(std::numeric_limits<Framework::float64_t>::has_infinity, true);
    ASSERT_EQ(std::numeric_limits<Framework::float64_t>::has_quiet_NaN, true);
}
TEST(test_core, size_t)
{

    ASSERT_EQ(std::is_integral<Framework::size_t>::value, true);
    ASSERT_EQ(std::is_floating_point<Framework::size_t>::value, false);
    ASSERT_EQ(std::is_signed<Framework::size_t>::value, false);
    ASSERT_EQ(std::is_unsigned<Framework::size_t>::value, true);
    ASSERT_EQ(std::numeric_limits<Framework::size_t>::is_bounded, true);
}
#endif // TESE_BASE_TYPE
#endif // TEST_CORE