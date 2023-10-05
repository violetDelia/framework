#include <iomanip>
#include <iostream>
#include <limits>

#include "include/framwork.hpp"
int main()

{
    ASSERT_EQ(sizeof(Framework::float64_t), 8);
    ASSERT_EQ(std::numeric_limits<Framework::float64_t>::max(), 18446744073709551615);
    ASSERT_EQ(std::numeric_limits<Framework::float64_t>::min(), 0);
    ASSERT_EQ(std::is_integral<Framework::float64_t>::value, true);
    ASSERT_EQ(std::is_floating_point<Framework::float64_t>::value, false);
    ASSERT_EQ(std::is_signed<Framework::float64_t>::value, false);
    ASSERT_EQ(std::is_unsigned<Framework::float64_t>::value, true);
    ASSERT_EQ(std::numeric_limits<Framework::float64_t>::is_bounded, true);
    ASSERT_EQ(std::numeric_limits<Framework::float64_t>::has_infinity, true);
    ASSERT_EQ(std::numeric_limits<Framework::float64_t>::has_quiet_NaN, true);

};