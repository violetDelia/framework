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

#ifndef __FRAMWORK_SHAPE_HPP__
#define __FRAMWORK_SHAPE_HPP__
#include "core_helper.hpp"
FRAMEWORK_NAMESPACE
{

    //--------- define shape ----------//
    template <is_integer Ty>
    class Shape : public vector<Ty>
    {
    private:
        using father = vector<Ty>;

    public:
        using value_type = father::value_type;
        using size_type = father::size_type;

    protected:
    public:
        // construct
        constexpr Shape() noexcept : father(){};
        constexpr Shape(size_type count, const Ty &value) : father(count, value){};
        constexpr explicit Shape(size_type count) : father(count){};
        template <is_Input_Iterator Iterator>
        constexpr Shape(Iterator first, Iterator last) : father(first, last){};
        constexpr Shape(const Shape &other) noexcept : father(other){};
        constexpr Shape(Shape &&other) noexcept : father(std::move(other)){};
        constexpr Shape(const father &other) noexcept : father(other){};
        constexpr Shape(father &&other) noexcept : father(std::move(other)){};
        constexpr Shape(std::initializer_list<Ty> init_list) : father(init_list){};

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

        // reshape
        [[noreturn]] constexpr void reshape(std::initializer_list<Ty> init_list)
        {
            this->assign(init_list);
        };

        [[noreturn]] constexpr void reshape(const Shape &other)
        {
            this->assign(other.begin(), other.end());
        };

        [[noreturn]] constexpr void reshape(const father &other)
        {
            this->assign(other.begin(), other.end());
        };

        template <is_Input_Iterator Iterator>
        [[noreturn]] constexpr void reshape(Iterator first, Iterator last)
        {
            this->assign(first, last);
        };

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
    protected:
    private:
    };
} // namespace FRAMEWORK_NAMESPACE

#endif //__FRAMWORK_SHAPE_HPP__