//    Copyright 2023 时光丶人爱

//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at

//        http://www.apache.org/licenses/LICENSE-2.0

//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.

//    2023-10-11
//    If you have any questions about the code or if you think there is a better way to implement it,
//    please contact me by email 1733535832@qq.com.

#ifndef __FRAMWORK_TENSOR_HELPER_HPP__
#define __FRAMWORK_TENSOR_HELPER_HPP__
#include "core/core.hpp"

#ifdef __FRAMWORK__USE__EIGEN__
#include <eigen3/unsupported/Eigen/CXX11/Tensor>
#endif //__FRAMWORK__USE__EIGEN__

FRAMEWORK_NAMESPACE
{
#ifdef __FRAMWORK__USE__EIGEN__
    //--------- implement of is_Eigen_Tensor ----------//
    template <typename Ty>
    struct _Is_Eigen_Tensor_Implement : public std::false_type
    {
    };

    template <template <typename, int, int, typename> typename Ty, typename Scalar_, int NumIndices_, int Options_, typename IndexType_>
    struct _Is_Eigen_Tensor_Implement<Ty<Scalar_, NumIndices_, Options_, IndexType_>> : public std::is_same<Ty<Scalar_, NumIndices_, Options_, IndexType_>, Eigen::Tensor<Scalar_, NumIndices_, Options_, IndexType_>>
    {
    };

    template <typename Ty>
    concept is_Eigen_Tensor = _Is_Eigen_Tensor_Implement<Ty>::value;
#endif //__FRAMWORK__USE__EIGEN__

} // namespace FRAMEWORK_NAMESPACE
#endif // __FRAMWORK_TENSOR_HELPER_HPP__