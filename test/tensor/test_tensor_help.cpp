#include "test_config.h"
#ifdef TEST_TENSOR_HELP
#include <glog/logging.h>
#include <gtest/gtest.h>

#ifdef TEST_is_Eigen_Tensor
#include <eigen3/unsupported/Eigen/CXX11/Tensor>
#ifndef __FRAMWORK__USE__EIGEN__
#define __FRAMWORK__USE__EIGEN__
#endif //__FRAMWORK__USE__EIGEN__
#endif // TESR_IS_EIGEN_TENSOR

#include "tensor_helper.hpp"
#ifdef TEST_is_Eigen_Tensor
TEST(tensor_helper, is_Eigen_Tensor)
{
    ASSERT_EQ(Framework::_Is_Eigen_Tensor_Implement<int>::value, false);
    ASSERT_EQ(Framework::_Is_Eigen_Tensor_Implement<std::vector<int>>::value, false);
    ASSERT_EQ(Framework::_Is_Eigen_Tensor_Implement<std::vector<std::vector<std::string>>>::value, false);
    ASSERT_EQ((Framework::_Is_Eigen_Tensor_Implement<Eigen::Tensor<float, 3>>::value), true);
    ASSERT_EQ((Framework::_Is_Eigen_Tensor_Implement<Eigen::Tensor<float, 2>>::value), true);
    ASSERT_EQ((Framework::_Is_Eigen_Tensor_Implement<Eigen::Tensor<float, 2>>::value), true);
    ASSERT_EQ((Framework::_Is_Eigen_Tensor_Implement<Eigen::Tensor<std::int8_t, 2>>::value), true);
    ASSERT_EQ((Framework::_Is_Eigen_Tensor_Implement<Eigen::Tensor<std::int8_t, 2, 0>>::value), true);
    ASSERT_EQ((Framework::_Is_Eigen_Tensor_Implement<Eigen::Tensor<std::int8_t, 2, 0, Eigen::DenseIndex>>::value), true);
}
#endif // TESR_is_Eigen_Tensor
#endif // TEST_TENSOR_HELP
#ifdef __FRAMWORK__USE__EIGEN__
#undef __FRAMWORK__USE__EIGEN__
#endif // __FRAMWORK__USE__EIGEN__
