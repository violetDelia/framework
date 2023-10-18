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

/**
 * @file core_helper.hpp
 * @brief define some templates and concept; define some base type name and class
 *
 *
 *
 * @author 时光丶人爱
 * @date 2023-10-11
 * @see If you have any questions about the code or if you think there is a better way to implement
 * it,please contact me by email 1733535832@qq.com.
 */

#ifndef __FRAMWORK_CORE_HELPER_HPP__
#define __FRAMWORK_CORE_HELPER_HPP__
#include <type_traits>
#include <iterator>
#include <vector>
#include <array>
#include <initializer_list>
#include <cstdint>
#include <iostream>
//---------- namespace define ----------//

// Framwork namespace axu
#define FRAMEWORK_NAMESPACE_NAME Framework
#define FRAMEWORK_NAMESPACE \
    namespace FRAMEWORK_NAMESPACE_NAME

#define Framework_ FRAMEWORK_NAMESPACE_NAME::

// un_implemented
#define __UN_IMPLEMENTED__ std::cout << "not implemented" << std::endl   \
                                     << __PRETTY_FUNCTION__ << std::endl \
                                     << std::endl;

FRAMEWORK_NAMESPACE
{
    //--------- define bese type ----------//
    using int8_t = std::int8_t;
    using int16_t = std::int16_t;
    using int32_t = std::int32_t;
    using int64_t = std::int64_t;
    using uint8_t = std::uint8_t;
    using uint16_t = std::uint16_t;
    using uint32_t = std::uint32_t;
    using uint64_t = std::uint64_t;
    using float32_t = float;
    using float64_t = double;
    using size_t = std::size_t;

    //--------- define container ----------//
    template <typename Ty>
    using vector = std::vector<Ty>;

    template <typename Ty, size_t Num>
    using array = std::array<Ty, Num>;

    //--------- implement of is_instance ----------//
    template <typename, template <typename...> typename>
    struct _Is_Instance_Implement : public std::false_type
    {
    };

    template <template <typename...> typename _Base_Ty, typename... _args>
    struct _Is_Instance_Implement<_Base_Ty<_args...>, _Base_Ty> : public std::true_type
    {
    };

    template <typename Ty, template <typename...> typename Base_Ty>
    using is_instance = _Is_Instance_Implement<std::remove_cvref_t<Ty>, Base_Ty>;

    //--------- implement of has_iterator_category ----------//
    template <typename Iterator>
    using iterator_tag = typename std::iterator_traits<Iterator>::iterator_category;

    template <typename _Ty, typename = void>
    inline constexpr bool _Has_Iterator_Category_Implement = false;

    template <typename _Ty>
    inline constexpr bool _Has_Iterator_Category_Implement<_Ty, std::void_t<iterator_tag<_Ty>>> = true;

    template <typename Ty>
    struct Has_Iterator_Category : public std::bool_constant<_Has_Iterator_Category_Implement<Ty>>
    {
    };

    //--------- define concepts ----------//
    template <typename Ty>
    concept is_Integer = std::is_integral<Ty>::value;

    template <typename Ty>
    concept is_Iterator = Has_Iterator_Category<Ty>::value;

    template <typename Ty>
    concept is_Input_Iterator = std::is_nothrow_convertible_v<iterator_tag<Ty>, std::input_iterator_tag>;

} // namespace FRAMEWORK_NAMESPACE

#endif //__FRAMWORK_CORE_HELPER_HPP__