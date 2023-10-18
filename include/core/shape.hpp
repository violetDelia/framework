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
 * @file shape.hpp
 * @brief define class Shape
 *
 *
 *
 * @author 时光丶人爱
 * @date 2023-10-11
 * @see If you have any questions about the code or if you think there is a better way to implement
 * it,please contact me by email 1733535832@qq.com.
 */

#ifndef __FRAMWORK_SHAPE_HPP__
#define __FRAMWORK_SHAPE_HPP__
#include "core_helper.hpp"
FRAMEWORK_NAMESPACE
{   

    //---------- Shape define ----------//
    /**
     * @brief 表示形状的容器,继承自std::vector,只能通过reshape改变容器里的元素
     *
     * @tparam Ty 元素类型(约束:is_integer)
     */
    template <is_Integer Ty>
    class Shape : public vector<Ty>
    {
    private:
        using father = vector<Ty>;

    public:
        using value_type = father::value_type;
        using size_type = father::size_type;

    protected:
    public:
        /**
         * @brief 构造一个空的Shape
         *
         */
        constexpr Shape() noexcept;

        /**
         * @brief 根据迭代器生成相应的Shape
         *
         *
         * @tparam Iterator 迭代器(约束:is_Input_Iterator)
         * @param first 指向第一个元素的迭代器
         * @param last 指向最后一个元素的迭代器
         */
        template <is_Input_Iterator Iterator>
        explicit constexpr Shape(Iterator first, Iterator last);

        /**
         * @brief 构造一个跟other具有相同元素的Shape
         *
         *
         * @param other 其他的Shape
         */
        explicit constexpr Shape(const Shape<Ty> &other) noexcept;

        /**
         * @brief 构造一个跟other具有相同元素的Shape
         *
         *
         * @param other 其他的Shape
         */
        explicit constexpr Shape(Shape &&other) noexcept;

        /**
         * @brief 构造一个跟other具有相同元素的Shape
         *
         *
         * @param other shape的父类容器
         */
        explicit constexpr Shape(const father &other) noexcept;

        /**
         * @brief 构造一个跟other具有相同元素的Shape
         *
         *
         * @param other shape的父类容器
         */
        explicit constexpr Shape(father &&other) noexcept;

        /**
         * @brief 根据初始化列表构造Shape
         *
         *
         * @param init_list 初始化列表
         */
        explicit constexpr Shape(std::initializer_list<Ty> init_list);

        // assignment
        using father::operator=;

        // method about iterator
        using father::begin;
        using father::cbegin;
        using father::cend;
        using father::end;

        // using methods
        using father::at;
        using father::size;

        /**
         * @brief 根据init_list替换shape里的元素
         *
         *
         * @param init_list 初始化列表
         */
        constexpr void reshape(std::initializer_list<Ty> init_list);

        /**
         * @brief 将other中的元素赋值给Shape
         *
         *
         * @param other 其他的Shape实例
         */
        constexpr void reshape(const Shape &other);

        /**
         * @brief 将other中的元素赋值给Shape
         *
         *
         * @param other Shape父类的实例
         */
        constexpr void reshape(const father &other);

        /**
         * @brief 将首位迭代器中的元素赋值给Shape
         *
         *
         * @tparam Iterator 迭代器(约束:is_Input_Iterator)
         * @param first 指向第一个元素的迭代器
         * @param last 指向最后一个元素的迭代器
         */
        template <is_Input_Iterator Iterator>
        constexpr void reshape(Iterator first, Iterator last);

    protected:
        // data
        using father::data;

    private:
        // ban some methods that not use
        using father::operator[];
        using father::assign;
        using father::back;
        using father::capacity;
        using father::clear;
        using father::crbegin;
        using father::crend;
        using father::emplace;
        using father::emplace_back;
        using father::empty;
        using father::erase;
        using father::front;
        using father::get_allocator;
        using father::insert;
        using father::max_size;
        using father::pop_back;
        using father::push_back;
        using father::rbegin;
        using father::rend;
        using father::reserve;
        using father::resize;
        using father::shrink_to_fit;
        using father::swap;

    public:
        // friend istream &operator>>(istream &in, Shape &shape);

    protected:
    private:
    };


    //---------- Shape implement ----------//
    template <is_Integer Ty>
    constexpr Shape<Ty>::Shape() noexcept : father(){};

    template <is_Integer Ty>
    template <is_Input_Iterator Iterator>
    constexpr Shape<Ty>::Shape(Iterator first, Iterator last) : father(first, last){};

    template <is_Integer Ty>
    constexpr Shape<Ty>::Shape(const Shape<Ty> &other) noexcept : father(other){};

    template <is_Integer Ty>
    constexpr Shape<Ty>::Shape(Shape && other) noexcept : father(std::move(other)){};

    template <is_Integer Ty>
    constexpr Shape<Ty>::Shape(const father &other) noexcept : father(other){};

    template <is_Integer Ty>
    constexpr Shape<Ty>::Shape(std::initializer_list<Ty> init_list) : father(std::move(init_list)){};

    template <is_Integer Ty>
    constexpr Shape<Ty>::Shape(father && other) noexcept : father(std::move(other)){};

    template <is_Integer Ty>
    constexpr void Shape<Ty>::reshape(std::initializer_list<Ty> init_list)
    {
        this->assign(init_list.begin(), init_list.end());
    };

    template <is_Integer Ty>
    constexpr void Shape<Ty>::reshape(const Shape &other)
    {
        this->assign(other.begin(), other.end());
    };

    template <is_Integer Ty>
    constexpr void Shape<Ty>::reshape(const father &other)
    {
        this->assign(other.begin(), other.end());
    };

    template <is_Integer Ty>
    template <is_Input_Iterator Iterator>
    constexpr void Shape<Ty>::reshape(Iterator first, Iterator last)
    {
        this->assign(first, last);
    };

} // namespace FRAMEWORK_NAMESPACE

#endif //__FRAMWORK_SHAPE_HPP__