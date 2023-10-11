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

#ifdef TEST_SHAPE
TEST(Shape, construct__size__at)
{
    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape1;
    ASSERT_EQ(shape1.size(), 0);
    EXPECT_ANY_THROW(shape1.at(0));

    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape2(2, 2);
    ASSERT_EQ(shape2.size(), 2);
    ASSERT_EQ(shape2.at(0), 2);
    ASSERT_EQ(shape2.at(1), 2);
    EXPECT_ANY_THROW(shape2.at(2));

    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape3(2);
    ASSERT_EQ(shape3.size(), 2);
    ASSERT_EQ(shape3.at(0), 0);
    ASSERT_EQ(shape3.at(1), 0);
    EXPECT_ANY_THROW(shape3.at(2));

    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape4(shape2.begin(), shape2.end());
    ASSERT_EQ(shape4.size(), 2);
    ASSERT_EQ(shape4.at(0), 2);
    ASSERT_EQ(shape4.at(1), 2);
    EXPECT_ANY_THROW(shape4.at(2));

    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape5(shape2);
    ASSERT_EQ(shape5.size(), 2);
    ASSERT_EQ(shape5.at(0), 2);
    ASSERT_EQ(shape5.at(1), 2);
    EXPECT_ANY_THROW(shape5.at(2));

    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape6(std::move(shape2));
    ASSERT_EQ(shape6.size(), 2);
    ASSERT_EQ(shape6.at(0), 2);
    ASSERT_EQ(shape6.at(1), 2);
    EXPECT_ANY_THROW(shape6.at(2));
    EXPECT_ANY_THROW(shape2.at(0));
    ASSERT_EQ(shape2.size(), 0);

    std::vector<std::size_t> vector1(2);
    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape7(vector1);
    ASSERT_EQ(shape7.size(), 2);
    ASSERT_EQ(shape7.at(0), 0);
    ASSERT_EQ(shape7.at(1), 0);
    EXPECT_ANY_THROW(shape7.at(2));
    ASSERT_EQ(vector1.size(), 2);

    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape8(std::move(vector1));
    ASSERT_EQ(shape8.size(), 2);
    ASSERT_EQ(shape8.at(0), 0);
    ASSERT_EQ(shape8.at(1), 0);
    EXPECT_ANY_THROW(shape8.at(2));
    EXPECT_ANY_THROW(shape2.at(0));
    ASSERT_EQ(vector1.size(), 0);

    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape9{1, 2, 3};
    ASSERT_EQ(shape9.size(), 3);
    ASSERT_EQ(shape9.at(0), 1);
    ASSERT_EQ(shape9.at(1), 2);
    ASSERT_EQ(shape9.at(2), 3);
    EXPECT_ANY_THROW(shape9.at(3));
}

TEST(Shape, begin__end__cbegin__cend)
{
    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape1{1, 2, 3};
    auto begin = shape1.begin();
    auto end = shape1.end();
    auto cbegin = shape1.cbegin();
    auto cend = shape1.cend();
    ASSERT_EQ(*begin, *cbegin);
    ASSERT_EQ(*end, *end);
    ASSERT_EQ(begin - cend, cbegin - cend);
    while (begin != cend)
    {
        begin++;
    }
    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape2;
    ASSERT_EQ(shape2.begin(), shape2.end());
    ASSERT_EQ(shape2.cbegin(), shape2.cend());
}
#endif // TEST_SHAPE

#endif // TEST_CORE