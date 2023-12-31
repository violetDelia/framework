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

#ifndef __FRAMWORK_TENSOR_OPERATOR_HPP__
#define __FRAMWORK_TENSOR_OPERATOR_HPP_
#include "../config.h"
#include "../core/shape.hpp"
#include "../tensor/tensor_helper.hpp"
FRAMEWORK_NAMESPACE
{
    //---------- _Tensor_Operator_Base define ----------//
    /**
     * @brief Tensor_Operator 的基类
     *
     * @tparam Base 基矩阵
     * @tparam placeholder 占位符
     */
    template <typename Base, typename placeholder = void>
    struct _Tensor_Operator_Base
    {
    public:
        using base_type = Base;
        using base_pointer = base_type *;
        using base_const_pointer = const base_type *;
        using base_reference = base_type &;
        using base_const_reference = const base_type &;

        using value_type = int;
        using value_pointer = value_type *;
        using value_const_pointer = const value_type *;
        using value_reference = value_type &;
        using value_const_reference = const value_type &;

        using size_type = size_t;
        using shape_type = Shape<size_type>;
        using shape_reference = shape_type &;

    protected:
    private:
    public:
        // constructor
        constexpr _Tensor_Operator_Base() = default;
        constexpr _Tensor_Operator_Base(const _Tensor_Operator_Base &other) = default;
        constexpr _Tensor_Operator_Base(_Tensor_Operator_Base &&other) = default;
        constexpr _Tensor_Operator_Base &operator=(const _Tensor_Operator_Base &other) = default;
        ~_Tensor_Operator_Base() = default;

        /**
         * @brief 返回矩阵的形状
         *
         *
         * @return Shape
         */
        constexpr shape_type shape(base_const_reference base) const;

        constexpr shape_type dim(base_const_reference base, size_type dimension) const;

        constexpr shape_type dims(base_const_reference base) const;

    protected:
    private:
    public:
    protected:
    private:
    };

    //---------- _Tensor_Operator_Base impletment ----------//
    template <typename Base, typename placeholder>
    constexpr _Tensor_Operator_Base<Base, placeholder>::shape_type _Tensor_Operator_Base<Base, placeholder>::shape(base_const_reference base) const
    {
        __UN_IMPLEMENTED__
        return shape_type();
    };

    //---------- Tensor_Operator define ----------//
    /**
     * @brief Tensor 计算实际进行操作的单元
     *
     * @tparam Base 基矩阵
     * @tparam placeholder 占位符
     */
    template <typename Base, typename placeholder = void>
    struct Tensor_Operator : public _Tensor_Operator_Base<Base>
    {
    public:
        using base_type = Base;
        using base_pointer = base_type *;
        using base_const_pointer = const base_type *;
        using base_reference = base_type &;
        using base_const_reference = const base_type &;

        using value_type = int;
        using value_pointer = value_type *;
        using value_const_pointer = const value_type *;
        using value_reference = value_type &;
        using value_const_reference = const value_type &;

        using size_type = size_t;
        using shape_type = Shape<size_type>;
        using shape_reference = shape_type &;

    protected:
    private:
    public:
        Tensor_Operator() = delete;
        Tensor_Operator(const Tensor_Operator &other) = delete;
        Tensor_Operator(Tensor_Operator &&other) = delete;
        Tensor_Operator &operator=(const Tensor_Operator &other) = delete;
        ~Tensor_Operator() = default;

    protected:
    private:
    public:
    protected:
    private:
    };

    // concept is_Tensor_Operator
    template <typename Ty>
    concept is_Tensor_Operator = is_instance<Ty, Framework::Tensor_Operator>::value;

    // Overloaded Tensor_Operator == and != operators
    template <typename Ty>
    constexpr inline bool operator==(Tensor_Operator<Ty> & /*left*/, Tensor_Operator<Ty> & /*right*/)
    {
        return true;
    };

    template <typename Ty>
    constexpr inline bool operator!=(Tensor_Operator<Ty> & /*left*/, Tensor_Operator<Ty> & /*right*/)
    {
        return false;
    };

    template <typename Ty, typename Other_Ty>
    constexpr inline bool operator==(Tensor_Operator<Ty> & /*left*/, Tensor_Operator<Other_Ty> & /*right*/)
    {
        return false;
    };

    template <typename Ty, typename Other_Ty>
    constexpr inline bool operator!=(Tensor_Operator<Ty> & /*left*/, Tensor_Operator<Other_Ty> & /*right*/)
    {
        return true;
    };

} // namespace FRAMEWORK_NAMESPACE
#ifdef __FRAMWORK__USE__EIGEN__
#include <eigen3/unsupported/Eigen/CXX11/Tensor>
FRAMEWORK_NAMESPACE
{

    /**
     * @brief Tensor_Operator EIGEN 特化版本
     *
     * @tparam Base Eigen::Tensor
     * @tparam placeholder 占位符
     */
    template <is_Eigen_Tensor Eigen_Tensor>
    class Tensor_Operator<Eigen_Tensor, void> : public _Tensor_Operator_Base<Eigen_Tensor>
    {
    public:
        using base_type = Eigen_Tensor;
        using base_pointer = base_type *;
        using base_const_pointer = const base_type *;
        using base_reference = base_type &;
        using base_const_reference = const base_type &;

        using value_type = int;
        using value_pointer = value_type *;
        using value_const_pointer = const value_type *;
        using value_reference = value_type &;
        using value_const_reference = const value_type &;

        using size_type = size_t;
        using shape_type = Shape<size_type>;
        using shape_reference = shape_type &;

    protected:
    private:
    public:
        constexpr Tensor_Operator() = default;
        constexpr Tensor_Operator(const Tensor_Operator &other) = default;
        constexpr Tensor_Operator(Tensor_Operator &&other) = default;
        constexpr Tensor_Operator &operator=(const Tensor_Operator &other) = default;
        ~Tensor_Operator() = default;

        constexpr shape_type shape(base_const_reference base) const;

    protected:
    private:
    public:
    protected:
    private:
    };

    template <is_Eigen_Tensor Eigen_Tensor>
    constexpr Tensor_Operator<Eigen_Tensor, void>::shape_type Tensor_Operator<Eigen_Tensor, void>::shape(base_const_reference base) const
    {
        auto dims = base.dimensions();
        return shape_type(dims.begin(), dims.end());
    };
}
#endif // __FRAMWORK__USE__EIGEN__
#endif //__FRAMWORK_TENSOR_OPERATOR_HPP_