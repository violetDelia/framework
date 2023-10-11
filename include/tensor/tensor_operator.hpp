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
#include "core/core.hpp"
FRAMEWORK_NAMESPACE
{
    template <typename Base, typename placeholder = void>
    class Tensor_Operator
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

    protected:
    private:
    public:
        Tensor_Operator() = default;
        Tensor_Operator(const Tensor_Operator &other) = default;
        Tensor_Operator(Tensor_Operator &&other) = default;
        Tensor_Operator &operator=(const Tensor_Operator &other) = default;
        ~Tensor_Operator() = default;

    protected:
    private:
    public:
    protected:
    private:
    };

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

#endif //__FRAMWORK_TENSOR_OPERATOR_HPP_