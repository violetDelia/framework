
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

#ifndef __FRAMWORK_TENSOR_HPP__
#define __FRAMWORK_TENSOR_HPP__
#include "core/shape.hpp"
#include "tensor_operator.hpp"
#include "tensor_helper.hpp"
#include <initializer_list>
FRAMEWORK_NAMESPACE
{
    /**
     * @brief 基于Base进行计算的tensor,可以支持多种矩阵.
     *
     * @tparam Base 被包装的矩阵, 比如Eigen::tensor
     */
    template <typename Base>
    class Tensor
    {
    protected:
        using base_operator = Tensor_Operator<Base>;
        using base_type = base_operator::base_type;
        using base_pointer = base_operator::base_pointer;
        using base_const_pointer = base_operator::base_const_pointer;
        using base_reference = base_operator::base_reference;
        using base_const_reference = base_operator::base_const_reference;

    public:
        using value_type = base_operator::value_type;
        using value_pointer = base_operator::value_pointer;
        using value_const_pointer = base_operator::value_const_pointer;
        using value_reference = base_operator::value_reference;
        using value_const_reference = base_operator::value_const_reference;

        using size_type = size_t;
        // using shape_type = Shape<size_type>;
        // using shape_pointer = shape_type::pointer;
        // using shape_const_pointer = shape_type::const_pointer;
        // using shape_reference = shape_type::reference;
        // using shape_const_reference = shape_type::const_reference;
    protected:
        using vector_type = std::vector<value_type>;
        using vector_const_type = const std::vector<value_type>;
        using shape_type = Shape<value_type>;
        using shape_reference = shape_type &;

    private:
    public:
        constexpr Tensor() : _operator(), _base()
        {
            std::cout << "Tensor_construct" << std::endl;
            std::cout << __PRETTY_FUNCTION__ << std::endl
                      << std::endl;
        };

        explicit constexpr Tensor(std::initializer_list<size_type> &init_list)
        {
            std::cout << "not_impletment" << std::endl;
            std::cout << __PRETTY_FUNCTION__ << std::endl
                      << std::endl;
        };

        explicit constexpr Tensor(shape_reference shape)
        {
            std::cout << "not_impletment" << std::endl;
            std::cout << __PRETTY_FUNCTION__ << std::endl
                      << std::endl;
        };

        explicit constexpr Tensor(shape_reference shape, std::initializer_list<size_type> &init_list)
        {
            std::cout << "not_impletment" << std::endl;
            std::cout << __PRETTY_FUNCTION__ << std::endl
                      << std::endl;
        };

        template <is_Input_Iterator Iterator>
        explicit constexpr Tensor(Iterator first, Iterator last)
        {
            std::cout << "not_impletment" << std::endl;
            std::cout << __PRETTY_FUNCTION__ << std::endl
                      << std::endl;
        };

        constexpr size_type dim(size_type dimension) const
        {
            std::cout << "not_impletment" << std::endl;
            std::cout << __PRETTY_FUNCTION__ << std::endl
                      << std::endl;
            return size_type();
        };

        constexpr size_type dim() const
        {
            std::cout << "not_impletment" << std::endl;
            std::cout << __PRETTY_FUNCTION__ << std::endl
                      << std::endl;
            return size_type();
        }

        constexpr Shape<size_type> shape() const
        {
            std::cout << "not_impletment" << std::endl;
            std::cout << __PRETTY_FUNCTION__ << std::endl
                      << std::endl;
            return Shape<size_type>();
        }


        protected:
    private:
    public:
        // shape_type shape;

        // protected:
        base_operator _operator;
        base_type _base;

    private:
    };
} // namespace FRAMEWORK_NAMESPACE

#endif // __FRAMWORK_TENSOR_HPP__
