#include "test_config.h"
#ifdef TEST_CORE
#include "core.hpp"
#include <glog/logging.h>
#include <gtest/gtest.h>

#ifdef TEST_BASE_TYPE
TEST(base_type, int8_t)
{
    ASSERT_EQ(sizeof(FRAMEWORK_NAMESPACE_NAME::int8_t), 1);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::int8_t>::max(), 127);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::int8_t>::min(), -128);
    ASSERT_EQ(std::is_integral<FRAMEWORK_NAMESPACE_NAME::int8_t>::value, true);
    ASSERT_EQ(std::is_floating_point<FRAMEWORK_NAMESPACE_NAME::int8_t>::value, false);
    ASSERT_EQ(std::is_signed<FRAMEWORK_NAMESPACE_NAME::int8_t>::value, true);
    ASSERT_EQ(std::is_unsigned<FRAMEWORK_NAMESPACE_NAME::int8_t>::value, false);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::int8_t>::is_bounded, true);
}
TEST(base_type, int16_t)
{
    ASSERT_EQ(sizeof(FRAMEWORK_NAMESPACE_NAME::int16_t), 2);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::int16_t>::max(), 32767);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::int16_t>::min(), -32768);
    ASSERT_EQ(std::is_integral<FRAMEWORK_NAMESPACE_NAME::int16_t>::value, true);
    ASSERT_EQ(std::is_floating_point<FRAMEWORK_NAMESPACE_NAME::int16_t>::value, false);
    ASSERT_EQ(std::is_signed<FRAMEWORK_NAMESPACE_NAME::int16_t>::value, true);
    ASSERT_EQ(std::is_unsigned<FRAMEWORK_NAMESPACE_NAME::int16_t>::value, false);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::int16_t>::is_bounded, true);
}
TEST(base_type, int32_t)
{
    ASSERT_EQ(sizeof(FRAMEWORK_NAMESPACE_NAME::int32_t), 4);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::int32_t>::max(), 2147483647);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::int32_t>::min(), -2147483648);
    ASSERT_EQ(std::is_integral<FRAMEWORK_NAMESPACE_NAME::int32_t>::value, true);
    ASSERT_EQ(std::is_floating_point<FRAMEWORK_NAMESPACE_NAME::int32_t>::value, false);
    ASSERT_EQ(std::is_signed<FRAMEWORK_NAMESPACE_NAME::int32_t>::value, true);
    ASSERT_EQ(std::is_unsigned<FRAMEWORK_NAMESPACE_NAME::int32_t>::value, false);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::int32_t>::is_bounded, true);
}
TEST(base_type, int64_t)
{
    ASSERT_EQ(sizeof(FRAMEWORK_NAMESPACE_NAME::int64_t), 8);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::int64_t>::max(), LLONG_MAX);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::int64_t>::min(), LLONG_MIN);
    ASSERT_EQ(std::is_integral<FRAMEWORK_NAMESPACE_NAME::int64_t>::value, true);
    ASSERT_EQ(std::is_floating_point<FRAMEWORK_NAMESPACE_NAME::int64_t>::value, false);
    ASSERT_EQ(std::is_signed<FRAMEWORK_NAMESPACE_NAME::int64_t>::value, true);
    ASSERT_EQ(std::is_unsigned<FRAMEWORK_NAMESPACE_NAME::int32_t>::value, false);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::int64_t>::is_bounded, true);
}
TEST(base_type, uint8_t)
{
    ASSERT_EQ(sizeof(FRAMEWORK_NAMESPACE_NAME::uint8_t), 1);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::uint8_t>::max(), 255);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::uint8_t>::min(), 0);
    ASSERT_EQ(std::is_integral<FRAMEWORK_NAMESPACE_NAME::uint8_t>::value, true);
    ASSERT_EQ(std::is_floating_point<FRAMEWORK_NAMESPACE_NAME::uint8_t>::value, false);
    ASSERT_EQ(std::is_signed<FRAMEWORK_NAMESPACE_NAME::uint8_t>::value, false);
    ASSERT_EQ(std::is_unsigned<FRAMEWORK_NAMESPACE_NAME::uint8_t>::value, true);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::uint8_t>::is_bounded, true);
}
TEST(base_type, uint16_t)
{
    ASSERT_EQ(sizeof(FRAMEWORK_NAMESPACE_NAME::uint16_t), 2);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::uint16_t>::max(), 65535);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::uint16_t>::min(), 0);
    ASSERT_EQ(std::is_integral<FRAMEWORK_NAMESPACE_NAME::uint16_t>::value, true);
    ASSERT_EQ(std::is_floating_point<FRAMEWORK_NAMESPACE_NAME::uint16_t>::value, false);
    ASSERT_EQ(std::is_signed<FRAMEWORK_NAMESPACE_NAME::uint16_t>::value, false);
    ASSERT_EQ(std::is_unsigned<FRAMEWORK_NAMESPACE_NAME::uint16_t>::value, true);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::uint16_t>::is_bounded, true);
}
TEST(base_type, uint32_t)
{
    ASSERT_EQ(sizeof(FRAMEWORK_NAMESPACE_NAME::uint32_t), 4);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::uint32_t>::max(), 4294967295);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::uint32_t>::min(), 0);
    ASSERT_EQ(std::is_integral<FRAMEWORK_NAMESPACE_NAME::uint32_t>::value, true);
    ASSERT_EQ(std::is_floating_point<FRAMEWORK_NAMESPACE_NAME::uint32_t>::value, false);
    ASSERT_EQ(std::is_signed<FRAMEWORK_NAMESPACE_NAME::uint32_t>::value, false);
    ASSERT_EQ(std::is_unsigned<FRAMEWORK_NAMESPACE_NAME::uint8_t>::value, true);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::uint32_t>::is_bounded, true);
}
TEST(base_type, uint64_t)
{
    ASSERT_EQ(sizeof(FRAMEWORK_NAMESPACE_NAME::uint64_t), 8);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::uint64_t>::max(), ULLONG_MAX);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::uint64_t>::min(), 0);
    ASSERT_EQ(std::is_integral<FRAMEWORK_NAMESPACE_NAME::uint64_t>::value, true);
    ASSERT_EQ(std::is_floating_point<FRAMEWORK_NAMESPACE_NAME::uint64_t>::value, false);
    ASSERT_EQ(std::is_signed<FRAMEWORK_NAMESPACE_NAME::uint64_t>::value, false);
    ASSERT_EQ(std::is_unsigned<FRAMEWORK_NAMESPACE_NAME::uint64_t>::value, true);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::uint64_t>::is_bounded, true);
}
TEST(base_type, float32_t)
{
    ASSERT_EQ(sizeof(FRAMEWORK_NAMESPACE_NAME::float32_t), 4);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::float32_t>::max(), FLT_MAX);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::float32_t>::min(), FLT_MIN);
    ASSERT_EQ(std::is_integral<FRAMEWORK_NAMESPACE_NAME::float32_t>::value, false);
    ASSERT_EQ(std::is_floating_point<FRAMEWORK_NAMESPACE_NAME::float32_t>::value, true);
    ASSERT_EQ(std::is_signed<FRAMEWORK_NAMESPACE_NAME::float32_t>::value, true);
    ASSERT_EQ(std::is_unsigned<FRAMEWORK_NAMESPACE_NAME::float32_t>::value, false);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::float32_t>::is_bounded, true);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::float32_t>::has_infinity, true);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::float32_t>::has_quiet_NaN, true);
}
TEST(base_type, float64_t)
{
    ASSERT_EQ(sizeof(FRAMEWORK_NAMESPACE_NAME::float64_t), 8);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::float64_t>::max(), DBL_MAX);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::float64_t>::min(), DBL_MIN);
    ASSERT_EQ(std::is_integral<FRAMEWORK_NAMESPACE_NAME::float64_t>::value, false);
    ASSERT_EQ(std::is_floating_point<FRAMEWORK_NAMESPACE_NAME::float64_t>::value, true);
    ASSERT_EQ(std::is_signed<FRAMEWORK_NAMESPACE_NAME::float64_t>::value, true);
    ASSERT_EQ(std::is_unsigned<FRAMEWORK_NAMESPACE_NAME::float64_t>::value, false);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::float64_t>::is_bounded, true);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::float64_t>::has_infinity, true);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::float64_t>::has_quiet_NaN, true);
}
TEST(base_type, size_t)
{

    ASSERT_EQ(std::is_integral<FRAMEWORK_NAMESPACE_NAME::size_t>::value, true);
    ASSERT_EQ(std::is_floating_point<FRAMEWORK_NAMESPACE_NAME::size_t>::value, false);
    ASSERT_EQ(std::is_signed<FRAMEWORK_NAMESPACE_NAME::size_t>::value, false);
    ASSERT_EQ(std::is_unsigned<FRAMEWORK_NAMESPACE_NAME::size_t>::value, true);
    ASSERT_EQ(std::numeric_limits<FRAMEWORK_NAMESPACE_NAME::size_t>::is_bounded, true);
}
#endif // TESE_BASE_TYPE



#endif // TEST_CORE