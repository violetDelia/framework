#include "test_config.h"
#ifdef TEST_SHAPE
#include "core.hpp"
#include <glog/logging.h>
#include <gtest/gtest.h>
TEST(Shape, construct__size__at)
{
    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape1;
    ASSERT_EQ(shape1.size(), 0);
    EXPECT_ANY_THROW(shape1.at(0));

    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape2{2, 2};
    ASSERT_EQ(shape2.size(), 2);
    ASSERT_EQ(shape2.at(0), 2);
    ASSERT_EQ(shape2.at(1), 2);
    EXPECT_ANY_THROW(shape2.at(2));

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

    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape9 = {2, 2};
    ASSERT_EQ(shape9.size(), 2);
    ASSERT_EQ(shape9.at(0), 2);
    ASSERT_EQ(shape9.at(1), 2);
    EXPECT_ANY_THROW(shape9.at(2));
    
    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape10 = shape6;
    ASSERT_EQ(shape10.size(), 2);
    ASSERT_EQ(shape10.at(0), 2);
    ASSERT_EQ(shape10.at(1), 2);
    EXPECT_ANY_THROW(shape10.at(2));

    FRAMEWORK_NAMESPACE_NAME::Shape<unsigned short> shape11 = shape6;
    ASSERT_EQ(shape11.size(), 2);
    ASSERT_EQ(shape11.at(0), 2);
    ASSERT_EQ(shape11.at(1), 2);
    EXPECT_ANY_THROW(shape11.at(2));

    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape12 = shape11;
    ASSERT_EQ(shape12.size(), 2);
    ASSERT_EQ(shape12.at(0), 2);
    ASSERT_EQ(shape12.at(1), 2);
    EXPECT_ANY_THROW(shape12.at(2));

    
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
TEST(Shape, reshape)
{
    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape1{1, 2, 3};
    shape1.reshape({});
    ASSERT_EQ(shape1.size(), 0);
    EXPECT_ANY_THROW(shape1.at(0));

    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape2{1, 2, 3};
    shape1.reshape(shape2);
    ASSERT_EQ(shape1.size(), 3);
    ASSERT_EQ(shape1.at(0), 1);
    ASSERT_EQ(shape1.at(1), 2);
    ASSERT_EQ(shape1.at(2), 3);
    EXPECT_ANY_THROW(shape1.at(3));
    ASSERT_EQ(shape2.size(), 3);
    ASSERT_EQ(shape2.at(0), 1);
    ASSERT_EQ(shape2.at(1), 2);
    ASSERT_EQ(shape2.at(2), 3);
    EXPECT_ANY_THROW(shape2.at(3));

    std::vector<std::size_t> father1{4, 5, 6};
    ASSERT_EQ(father1.size(), 3);
    ASSERT_EQ(father1.at(0), 4);
    ASSERT_EQ(father1.at(1), 5);
    ASSERT_EQ(father1.at(2), 6);
    EXPECT_ANY_THROW(father1.at(3));
    shape1.reshape(father1);
    ASSERT_EQ(shape1.size(), 3);
    ASSERT_EQ(shape1.at(0), 4);
    ASSERT_EQ(shape1.at(1), 5);
    ASSERT_EQ(shape1.at(2), 6);
    EXPECT_ANY_THROW(shape1.at(3));

    shape1.reshape({1, 2});
    ASSERT_EQ(shape1.size(), 2);
    ASSERT_EQ(shape1.at(0), 1);
    ASSERT_EQ(shape1.at(1), 2);
    EXPECT_ANY_THROW(shape1.at(2));

    FRAMEWORK_NAMESPACE_NAME::Shape<short> shape3;
    shape3.reshape(shape2);
    ASSERT_EQ(shape3.size(), 3);
    ASSERT_EQ(shape3.at(0), 1);
    ASSERT_EQ(shape3.at(1), 2);
    ASSERT_EQ(shape3.at(2), 3);
    EXPECT_ANY_THROW(shape3.at(3));


}
TEST(Shape, operators)
{
    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape1{1, 2, 3};
    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape2{1, 2, 3};
    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape3{1, 2};

    ASSERT_EQ(shape1 == shape2, true);
    ASSERT_EQ(shape1 != shape2, false);
    ASSERT_EQ(shape1 == shape3, false);
    ASSERT_EQ(shape1 != shape3, true);

    FRAMEWORK_NAMESPACE_NAME::Shape<int> shape4{1, 2, 3};
    FRAMEWORK_NAMESPACE_NAME::Shape<short> shape5{2, 3};
    ASSERT_EQ(shape1 == shape4, true);
    ASSERT_EQ(shape1 != shape4, false);
    ASSERT_EQ(shape1 == shape5, false);
    ASSERT_EQ(shape1 != shape5, true);
}
#endif // TEST_SHAPE